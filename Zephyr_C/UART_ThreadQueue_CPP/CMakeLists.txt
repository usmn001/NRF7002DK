# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(BLINKY)

target_sources(app PRIVATE src/main.cpp)
#target_sources(app PRIVATE src/myfunction.c)
target_sources_ifdef(CONFIG_UART_FUNC app PRIVATE src/uartfunc.cpp)
target_sources_ifdef(CONFIG_LED_FUNC app PRIVATE src/led.cpp)