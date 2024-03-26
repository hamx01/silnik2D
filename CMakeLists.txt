cmake_minimum_required(VERSION 3.25)
project(silnik2D)

set(CMAKE_CXX_STANDARD 17)

add_executable(silnik2D main.cpp
        Engine.cpp
        Engine.h
        Engine.h)

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    include_directories(C:/SFML/bin C:/SFML/include C:/SFML/lib) # dodane
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules") # dodane
    find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
    if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(silnik2D ${SFML_LIBRARIES})
    endif()
elseif(APPLE)
    find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
    target_link_libraries(silnik2D sfml-graphics)
endif()