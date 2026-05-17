add_library(DigitalOutput)

target_sources(DigitalOutput
            PRIVATE
                DigitalOutput.cpp
            PUBLIC 
                FILE_SET HEADERS
                BASE_DIRS .
                FILES DigitalOutput.hpp
)
target_link_libraries(DigitalOutput PRIVATE Init)