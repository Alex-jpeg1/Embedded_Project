cmake_minimum_required(VERSION 3.10)

project(Arduino_Subwoofer LANGUAGES C CXX)

set(MCU atmega328p)

if(MCU STREQUAL "atmega328p")
    set(CMAKE_C_FLAGS "-mmcu=${MCU} -Os -Wall")
    set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -Os -Wall")
    add_definitions(-DF_CPU=16000000UL)
endif()

set(CMAKE_EXECUTABLE_SUFFIX ".elf")

add_subdirectory(lib)
add_subdirectory(src)