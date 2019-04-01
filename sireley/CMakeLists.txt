cmake_minimum_required(VERSION 3.13)
project(sireley_lib)

include_directories(${CMAKE_CURRENT_LIST_DIR})

file(GLOB headers sireley.h sireley_client.h sireley_types.h sireley_request.h sireley_response.h
        private/private.sireley_request.h private/platform.sireley_client.h private/platform.sireley_types.h)
file(GLOB sources sources/sireley_request.c)

if (APPLE)
    set(CMAKE_C_FLAGS "-x objective-c")
    list(APPEND sources sources/apple/apple.sireley_request.m sources/apple/sireley_client.m)
endif ()

file(GLOB files ${headers} ${sources})
add_library(${PROJECT_NAME} ${files})

if (APPLE)
target_link_libraries(${PROJECT_NAME}
        "-framework Cocoa"
        "-framework Foundation"
        )
endif ()