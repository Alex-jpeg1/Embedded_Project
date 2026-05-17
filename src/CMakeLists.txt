add_executable(${PROJECT_NAME}
                main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Init)

if(MCU STREQUAL "atmega328p")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
        COMMENT "Generating HEX file for upload"
    )
endif()