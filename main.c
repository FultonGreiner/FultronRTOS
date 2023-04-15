#include "main.h"

#include <inttypes.h>
#include <stdbool.h>

enum {
	GPIO_MODE_INPUT,
	GPIO_MODE_OUTPUT,
	GPIO_MODE_AF,
	GPIO_MODE_ANALOG
};

static inline void gpio_set_mode(uint16_t pin, uint8_t mode) {
	struct gpio *gpio = GPIO(PINBANK(pin));
	int n = PINNO(pin);
	// clear current setting
	gpio->MODER &= ~(3U << (n * 2));
	// set new mode
	gpio->MODER |= (mode & 3U) << (n * 2);
}

static inline void gpio_write(uint16_t pin, bool val) {
	struct gpio *gpio = GPIO(PINBANK(pin));
	gpio->BSRR = (1U << PINNO(pin)) << (val ? 0x0 : 0x10);
}

static inline void spin(volatile uint32_t count) {
	while (count--) {
		asm("nop");
	}
}

int main(void) {
	// B7 -> blue user led
	uint16_t led = PIN('B', 7);
	RCC->AHB1ENR |= BIT(PINBANK(led));
	gpio_set_mode(led, GPIO_MODE_OUTPUT);
	while (true) {
		gpio_write(led, true);
		spin(999999);
		gpio_write(led, false);
		spin(999999);
	}
	return 0;
}

__attribute__((naked, noreturn)) void _reset(void) {
	extern long _sbss, _ebss, _sdata, _edata, _sidata;
	for (long *src = &_sbss; src < &_ebss; src++) {
		*src = 0;
	}
	for (long *src = &_sdata, *dst = &_sidata; src < &_edata;) {
		*src++ = *dst++;
	}

	main();
	for (;;) (void) 0;
}

extern void _estack(void);

__attribute__((section(".vectors"))) void (*tab[16 + 52])(void) = {_estack, _reset};

