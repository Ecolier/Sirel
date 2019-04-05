cmake_minimum_required(VERSION 3.13)

project(sirel_core)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${sirel_root_dir})

set(sources
        generic_request.h
        generic_response.h
        sources/generic_request.c)

add_library(${PROJECT_NAME} ${sources})