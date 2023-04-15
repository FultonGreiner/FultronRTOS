#ifndef MAIN_H
#define MAIN_H

#include <inttypes.h>

#define BIT(x) (1UL << (x))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (pin & 255)
#define PINBANK(pin) (pin >> 8)

struct rcc {
	volatile uint32_t CR,
			 PLLCFGR,
			 CFGR,
			 CIR,
			 AHB1RSTR,
			 AHB2RSTR,
			 RESERVED0,
			 RESERVED1,
			 APB1RSTR,
			 APB2RSTR,
			 RESERVED3,
			 RESERVED4,
			 AHB1ENR,
			 AHB2ENR,
			 RESERVED5,
			 RESERVED6,
			 APB1ENR,
			 APB2ENR,
			 RESERVED7,
			 RESERVED8,
			 AHB1LPENR,
			 AHB2LPENR,
			 RESERVED9,
			 RESERVED10,
			 APB1LPENR,
			 APB2LPENR,
			 RESERVED11,
			 RESERVED12,
			 BDCR,
			 CSR,
			 RESERVED13,
			 RESERVED14,
			 SSCGR,
			 PLLI2SCFGR,
			 DCKCFGR;
};
#define RCC ((struct rcc *) 0x40023800)

struct gpio {
	volatile uint32_t MODER,
			 OTYPER,
			 OSPEEDR,
			 PUPDR,
			 IDR,
			 ODR,
			 BSRR,
			 LCKR,
			 AFRL,
			 AFRH;
};
#define GPIO(bank) ((struct gpio *) (0x40020000 + 0x400 * (bank)))

#endif