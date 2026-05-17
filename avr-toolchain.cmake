set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

if(DEFINED ENV{CC})
    set(CMAKE_C_COMPILER $ENV{CC})
else()
    set(CMAKE_C_COMPILER avr-gcc)
endif()

if(DEFINED ENV{CXX})
    set(CMAKE_CXX_COMPILER $ENV{CXX})
else()
    set(CMAKE_CXX_COMPILER avr-g++)
endif()

get_filename_component(COMPILER_DIR ${CMAKE_C_COMPILER} DIRECTORY)
get_filename_component(COMPILER_NAME ${CMAKE_C_COMPILER} NAME_WE)
string(REPLACE "-gcc" "-objcopy" OBJCOPY_NAME "${COMPILER_NAME}")

if(COMPILER_DIR)
    set(CMAKE_OBJCOPY "${COMPILER_DIR}/${OBJCOPY_NAME}")
else()
    set(CMAKE_OBJCOPY avr-objcopy)
endif()