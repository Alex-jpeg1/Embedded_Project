add_library(Potentiometers)

target_sources(Potentiometers
            PRIVATE
                Potentiometer.cpp
            PUBLIC 
                FILE_SET HEADERS
                BASE_DIRS .
                FILES Potentiometer.hpp
)