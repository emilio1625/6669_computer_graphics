cmake_minimum_required(VERSION 3.6)
project(primitivas)

set(SOURCE_FILES src/primitivas.cpp inc/primitivas.h)

add_library(primitivas ${SOURCE_FILES})
target_include_directories(primitivas PUBLIC inc)

