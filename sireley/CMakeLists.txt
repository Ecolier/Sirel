cmake_minimum_required(VERSION 3.13)
project(sireley_lib)

file(GLOB headers sireley.h sireley_client.h sireley_types.h sireley_request.h sireley_response.h platform/sireley_request.platform.h)
file(GLOB sources sources/sireley_request.c)

include_directories(${CMAKE_CURRENT_LIST_DIR})

if (APPLE)
    set(CMAKE_C_FLAGS "-x objective-c")
    list(APPEND sources sources/apple/sireley_request.apple.m)
endif ()

file(GLOB files ${headers} ${sources})
add_library(${PROJECT_NAME} ${files})

if (APPLE)
target_link_libraries(${PROJECT_NAME}
        "-framework Cocoa"
        "-framework Foundation"
        )
endif ()