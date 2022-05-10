cmake_minimum_required(VERSION 3.22)
project(GeometricShapes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(MAIN src/main_CLI.cpp)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(GeometricShapes src/main.cpp)
add_executable(CLI ${MAIN})

target_link_libraries(GeometricShapes
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

