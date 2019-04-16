cmake_minimum_required(VERSION 3.13)

project(sirel_oauth2)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${sirel_root_dir})
set(sources oauth2_request.h
            sources/oauth2_request.c)

add_library(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} sirel_http)

find_library(jsmn_lib libjsmn PATHS ${sirel_root_dir}/vendors/jsmn)
target_link_libraries(${PROJECT_NAME} ${jsmn_lib})