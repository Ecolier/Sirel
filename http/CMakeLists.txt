cmake_minimum_required(VERSION 3.13)

project(sirel_http)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${sirel_root_dir})

set(sources http_request.h private/http_request.private.h)

if (APPLE)
    list(APPEND sources
            apple/http_request.apple.h
            apple/http_request.apple.m)
endif ()

add_library(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} sirel_core)

if (APPLE)
    target_link_libraries(${PROJECT_NAME}
            "-framework Cocoa"
            "-framework Foundation")
endif ()
