cmake_minimum_required(VERSION 3.22)
project(GeometricShapes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE HEADERS src/AbstractShapeSubclasses/*.h
                          src/AbstractShape.h
                          src/ComplexShape.h
                          src/Point.h)

file(GLOB_RECURSE SOURCES src/AbstractShapeSubclasses/*.cpp
                          src/AbstractShape.cpp
                          src/ComplexShape.cpp
                          src/Point.cpp
                          src/SandBox.cpp)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(GeometricShapes src/main.cpp)

add_executable(SandBox ${SOURCES} ${HEADERS})


target_link_libraries(GeometricShapes
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
