# FultronRTOS

FultronRTOS is a real-time operating system designed to target the STM32F4x series of MCUs. It is created from bare-metal, using the development board and MCU datasheets, as well as STLINK and the GNU ARM Toolchain.

## Purpose

I began this project to learn more about operating systems and low-level software by creating a real-time operating system from scratch. FultronRTOS is designed to provide a platform for running real-time embedded applications on STM32F4x series MCUs.

## Features

FultronRTOS has several important features that make it a powerful choice for running real-time embedded applications:

- **GNU Linker Script**: FultronRTOS includes a custom GNU linker script that provides memory layout and linking information for the operating system and any applications that run on it.

- **Interrupt Handlers**: FultronRTOS includes a set of interrupt handler functions that are used to handle various hardware interrupts that occur on the MCU. These functions ensure that real-time applications can run smoothly without any interruptions.

- **Scheduler** [IN PROGRESS]: The scheduler is responsible for allocating CPU time to each task, ensuring that real-time applications are executed in a timely manner. The scheduler is designed to be efficient and flexible, allowing for a wide range of real-time applications to be run on the MCU.

## Progress

### 0. Board Selection and Toolchain Setup

#### Selected Board
| Board | MCU Datasheet | Board Datasheet |
| ----- | ------------- | --------------- |
| [32F411EDISCOVERY](https://www.st.com/en/evaluation-tools/32f411ediscovery.html) | [STM32F411xC STM32F411xE](https://www.digikey.ch/htmldatasheets/production/1776125/0/0/1/stm32f411xc-stm32f411xe.html) | [Discovery kit with STM32F411VE MCU](https://www.st.com/resource/en/data_brief/32f411ediscovery.pdf) |

#### Required Tools
| Tool | Installation Link | Purpose |
| ---- | ----------------- | ------- |
| GNU Arm Embedded | [link](https://developer.arm.com/downloads/-/gnu-rm) | compilation and linking |
| GNU Make | [link](https://www.gnu.org/software/make/) | build automation |
| STLINK Tools | [link](https://github.com/stlink-org/stlink) | debug and flashing |

### 1. Datasheet Review

The datasheet contains information necessary for much of the project. The information gathered will be used for everything from controlling the clock frequency, to creating the IVT and its corresponding interrupt handlers.

#### Memory Map

The following information can be found in Section 5 of the MCU datasheet. There are other sections of memory, but these are the ones necessary for this project.

| Section | Start Address | Stop Address | Size |
| ------- | ------------- | ------------ | ---- |
| Code | 0x0000 0000 | 0x1FFF FFFF | 512 Mb |
| SRAM (aliased by bit-banding) | 0x2000 0000 | 0x2002 0000 | 128 Kb | 
| Peripherals | 0x4000 0000 | 0x5FFF FFFF | 512 Mb |
| Flash | 0x0800 0000 | 0x0807 FFFF | 512 Kb |

#### Peripherals

The following peripherals will be used in this project, and can be found in Section 5 of the MCU datasheet.

| Peripheral | Bus | Start Address |
| ------- | --- | ------------- |
| USART1 | APB2 | 0x4001 1000 |
| USART6 | APB2 | 0x4001 1400 |
| GPIOA | AHB1 | 0x4002 0000 |
| GPIOB | AHB1 | 0x4002 0400 |

## License

FultronRTOS is released under the GNU GENERAL PUBLIC LICENSE. See LICENSE for more information.
