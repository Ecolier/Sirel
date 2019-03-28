cmake_minimum_required(VERSION 3.13)
project(sireley_complete)

set(sireley_project_root_path ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(sireley)
add_subdirectory(tests)