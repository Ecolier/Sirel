cmake_minimum_required(VERSION 3.13)

set(dir ${CMAKE_CURRENT_LIST_DIR})

set(sirel_platform_files
        ${dir}/sirel_request_apple.h
        ${dir}/sirel_request_apple.m
        ${dir}/sirel_client_apple.m
        PARENT_SCOPE)

set(sirel_platform_libs
        "-framework Cocoa"
        "-framework Foundation"
        PARENT_SCOPE)
