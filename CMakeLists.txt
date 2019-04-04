cmake_minimum_required(VERSION 3.13)

set(sirel_root_dir ${CMAKE_CURRENT_LIST_DIR})

# Library
add_subdirectory(sirel)

# Tests
add_subdirectory(tests/simple)
add_subdirectory(tests/oauth2)
