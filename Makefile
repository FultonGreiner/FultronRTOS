TOOLCHAIN_PREFIX = arm-none-eabi-

CC      = $(TOOLCHAIN_PREFIX)gcc
OBJDUMP = $(TOOLCHAIN_PREFIX)objcopy
STFLASH   = st-flash

CCFLAGS ?= -W -Wall -Wextra -Werror -Wundef -Wshadow -Wdouble-promotion \
           -Wformat-truncation -fno-common -Wconversion -Wpadded \
           -g3 -Os -ffunction-sections -fdata-sections -I. -Iinclude \
           -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 $(EXTRA_CFLAGS)

LDFLAGS ?= -Tlink.ld -nostartfiles -nostdlib --specs nano.specs -lc -lgcc -Wl,--gc-sections

SRCS = main.c

LIBDIR=libs
SRCDIR=src
BINDIR=bin

LDFLAGS +=-Wl,-Map=$(BINDIR)/$@.map
VPATH = $(BINDIR) $(LIBDIR) $(SRCDIR)

build: firmware.elf

firmware.elf: prep_dirs $(SRCS)
	$(CC) $(SRCS) $(CCFLAGS) $(LDFLAGS) -o $(BINDIR)/$@

firmware.bin: firmware.elf
	$(CC_CPY) -O binary $(BINDIR)/$< $(BINDIR)/$@

flash: firmware.bin
	$(STFLASH) --reset write $(BINDIR)/firmware.bin 0x8000000

prep_dirs:
	mkdir -p $(BINDIR)

clean:
	$(RM) $(BINDIR)/firmware.*
	$(RM) -rf $(BINDIR)
