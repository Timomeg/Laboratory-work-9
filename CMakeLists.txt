cmake_minimum_required(VERSION 3.4)
project(Laboratory-work-9)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB String.cpp)

add_library(String STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})
target_link_libraries(main ${SOURCE_LIB})
