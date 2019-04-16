cmake_minimum_required(VERSION 3.13)

project(sirel_http)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${sirel_root_dir})

set(sources http_request.h http_response.h)

if (APPLE)
    list(APPEND sources
            apple/apple_http_request.h
            apple/apple_http_request.m)
endif ()

add_library(${PROJECT_NAME} ${sources})

if (APPLE)
    target_link_libraries(${PROJECT_NAME}
            "-framework Cocoa"
            "-framework Foundation")
endif ()