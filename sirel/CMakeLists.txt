cmake_minimum_required(VERSION 3.13)
project(sirel_lib)

include_directories(${CMAKE_CURRENT_LIST_DIR})

# add a platform here to implement your own version of Sirel
if (APPLE)
    add_subdirectory(platform/apple)
endif()

set(headers

        # public headers
        sirel.h
        sirel_client.h
        sirel_types.h
        sirel_request.h
        sirel_response.h

        #private headers
        private/sirel_request_private.h)

set(sources sources/sirel_request.c)

list(APPEND files ${headers} ${sources})
list(APPEND files ${headers} ${sirel_platform_files})

add_library(${PROJECT_NAME} ${files})

# link platform specific libraries
target_link_libraries(${PROJECT_NAME} ${sirel_platform_libs})