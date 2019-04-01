cmake_minimum_required(VERSION 3.13)
project(sirel_complete)

set(sirel_project_root_path ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(sirel)
add_subdirectory(tests)