# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(BLINKY)

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_sources(app PRIVATE src/main.cpp)
target_sources(app PRIVATE src/drivers/led.cpp)
target_sources(app PRIVATE src/drivers/uart.cpp)

