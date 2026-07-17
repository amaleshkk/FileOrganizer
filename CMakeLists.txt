cmake_minimum_required(VERSION 3.16)

project(fileOrganizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable(fileOrganizer 
    src/main.cpp
    src/FileParser.cpp
    src/FileCopy.cpp)