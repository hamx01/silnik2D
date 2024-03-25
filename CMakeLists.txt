cmake_minimum_required(VERSION 3.27)
project(silnik2D)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

add_executable(silnik2D main.cpp
        Engine.cpp
        Engine.h
        Engine.h)

target_link_libraries(silnik2D sfml-graphics)