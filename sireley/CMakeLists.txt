cmake_minimum_required(VERSION 3.13)
project(sireley_lib)

include_directories(${CMAKE_CURRENT_LIST_DIR})

# add a platform here to implement your own version of Sireley
if (APPLE)
    add_subdirectory(platform/apple)
endif()

set(headers

        # public headers
        sireley.h
        sireley_client.h
        sireley_types.h
        sireley_request.h
        sireley_response.h

        #private headers
        private/sireley_request_private.h)

set(sources sources/sireley_request.c)

list(APPEND files ${headers} ${sources})
list(APPEND files ${headers} ${sireley_platform_files})

message(${sireley_platform_files})

add_library(${PROJECT_NAME} ${files})

# link platform specific libraries
target_link_libraries(${PROJECT_NAME} ${sireley_platform_libs})