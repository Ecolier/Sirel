cmake_minimum_required(VERSION 3.13)

set(dir ${CMAKE_CURRENT_LIST_DIR})

set(sireley_platform_files
        ${dir}/sireley_request_apple.h
        ${dir}/sireley_request_apple.m
        ${dir}/sireley_client_apple.m
        PARENT_SCOPE)

set(sireley_platform_libs
        "-framework Cocoa"
        "-framework Foundation"
        PARENT_SCOPE)
