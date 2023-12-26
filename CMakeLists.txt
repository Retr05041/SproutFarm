# Basic CMake project for RayLib
# Created by Parker Cranfield 24/12/2023

cmake_minimum_required(VERSION 3.10)

project(RayLibTemplate)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE
    -lraylib 
    -lGL 
    -lm 
    -lpthread 
    -ldl 
    -lrt 
    -lX11
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)