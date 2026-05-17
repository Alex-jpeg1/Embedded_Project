add_library(Init)

target_sources(Init
            PRIVATE
                init.cpp ADCSRA.cpp ADMUX.cpp
            PUBLIC 
                FILE_SET HEADERS
                BASE_DIRS .
                FILES init.hpp
)