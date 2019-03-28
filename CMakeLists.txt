cmake_minimum_required(VERSION 3.13)
project(rest-client)

set(files rest-client.h sources/platform.h)

include_directories(./)
add_subdirectory(tests/simple)

if (APPLE)
    set(CMAKE_C_FLAGS "-x objective-c")
    list(APPEND files sources/Apple/rest-client.m)
elseif (NOT APPLE)
    set(CMAKE_C_STANDARD 99)
endif()

list(APPEND files sources/rest-client.c)

add_library(rest-client ${files})

if (APPLE)
target_link_libraries(${PROJECT_NAME}
        "-framework Cocoa"
        "-framework Foundation"
        )
endif()