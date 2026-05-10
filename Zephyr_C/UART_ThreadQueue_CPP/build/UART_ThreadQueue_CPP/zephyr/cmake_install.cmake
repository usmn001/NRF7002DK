# Install script for directory: /home/musman/ncs/nrfSDK/zephyr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/musman/ncs/toolchains/b2ecd2435d/opt/zephyr-sdk/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/arch/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/lib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/soc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/boards/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/subsys/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/drivers/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/nrf/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/hostap/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/mcuboot/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/mbedtls/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/trusted-firmware-m/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/cjson/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/azure-sdk-for-c/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/cirrus-logic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/openthread/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/memfault-firmware-sdk/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/canopennode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/chre/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/lz4/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/nanopb/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/zscilib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/cmsis/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/cmsis-dsp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/cmsis-nn/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/cmsis_6/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/fatfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/hal_nordic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/hal_st/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/hal_tdk/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/hal_wurthelektronik/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/liblc3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/libmetal/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/littlefs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/loramac-node/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/lvgl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/mipi-sys-t/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/nrf_wifi/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/open-amp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/percepio/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/picolibc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/segger/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/tinycrypt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/uoscore-uedhoc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/zcbor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/nrfxlib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/nrf_hw_models/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/modules/connectedhomeip/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/kernel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/cmake/flash/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/cmake/usage/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/musman/Desktop/NRF7002DK_GIT/Zephyr_C/UART_ThreadQueue_CPP/build/UART_ThreadQueue_CPP/zephyr/cmake/reports/cmake_install.cmake")
endif()

