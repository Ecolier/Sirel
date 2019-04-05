cmake_minimum_required(VERSION 3.13)

set(sirel_root_dir ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(core)
add_subdirectory(http)
add_subdirectory(oauth2)
add_subdirectory(tests/simple)
add_subdirectory(tests/oauth2)
