# FultronRTOS

FultronRTOS is a real-time operating system designed to target the STM32F4x series of MCUs. It is created from bare-metal, using the development board and MCU datasheets, as well as STLINK and the GNU ARM Toolchain.

## Purpose

I began this project to learn more about operating systems and low-level software by creating a real-time operating system from scratch. FultronRTOS is designed to provide a platform for running real-time embedded applications on STM32F4x series MCUs.

## Features

FultronRTOS has several important features that make it a powerful choice for running real-time embedded applications:

- **GNU Linker Script**: FultronRTOS includes a custom GNU linker script that provides memory layout and linking information for the operating system and any applications that run on it.

- **Interrupt Handlers**: FultronRTOS includes a set of interrupt handler functions that are used to handle various hardware interrupts that occur on the MCU. These functions ensure that real-time applications can run smoothly without any interruptions.

- **Scheduler**: The scheduler is the heart of FultronRTOS. It is responsible for allocating CPU time to each task, ensuring that real-time applications are executed in a timely manner. The scheduler is designed to be highly efficient and flexible, allowing for a wide range of real-time applications to be run on the MCU.

## License

FultronRTOS is released under the MIT License. See LICENSE for more information.
