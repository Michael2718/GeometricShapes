cmake_minimum_required(VERSION 3.22)
project(GeometricShapes VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#set(HEADERS src)

set(HEADERS src/Shape.h src/ShapeSubclasses/Rectangle.h)
set(SOURCES src/main_CLI.cpp src/Shape.cpp src/ShapeSubclasses/Rectangle.cpp)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(GeometricShapes src/main.cpp src/Shape.cpp src/Shape.h)

add_executable(GeometricShapesCLI ${SOURCES} ${HEADERS})
#target_include_directories(GeometricShapesCLI PRIVATE src)

target_link_libraries(GeometricShapes
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

