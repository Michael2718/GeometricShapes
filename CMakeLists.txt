cmake_minimum_required(VERSION 3.22)
project(GeometricShapes)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

set(SHAPES_HEADERS
        src/Shapes/
        src/Shapes/AbstractShape.h
        src/Shapes/Point.h
        src/Shapes/ComplexShape.h
        src/Shapes/ShapeFactory.h
        src/Shapes/AbstractShapeSubclasses/AbstractEllipse.h
        src/Shapes/AbstractShapeSubclasses/AbstractPolygon.h
        src/Shapes/AbstractShapeSubclasses/AbstractEllipseSubclasses/Ellipse.h
        src/Shapes/AbstractShapeSubclasses/AbstractEllipseSubclasses/Circle.h
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateral.h
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/SimplePolygon.h
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/Triangle.h
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/Rectangle.h
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/Rhombus.h
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/Trapezoid.h)

set(SHAPES_SOURCES
        src/Shapes/AbstractShape.cpp
        src/Shapes/Point.cpp
        src/Shapes/ComplexShape.cpp
        src/Shapes/ShapeFactory.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractEllipse.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractPolygon.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractEllipseSubclasses/Ellipse.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractEllipseSubclasses/Circle.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateral.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/SimplePolygon.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/Triangle.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/Rectangle.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/Rhombus.cpp
        src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/Trapezoid.cpp)

set(GTK_HEADERS
        src/Gtk/DrawingArea.h
        src/Gtk/Window.h
        src/Gtk/Notebook.h)

set(GTK_SOURCES
        src/Gtk/DrawingArea.cpp
        src/Gtk/Window.cpp
        src/Gtk/Notebook.cpp)

add_executable(GeometricShapes_CLI ${SHAPES_HEADERS} ${SHAPES_SOURCES} src/main_CLI.cpp)

target_include_directories(GeometricShapes_CLI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/)
target_include_directories(GeometricShapes_CLI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses)
target_include_directories(GeometricShapes_CLI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractEllipseSubclasses/)
target_include_directories(GeometricShapes_CLI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/)
target_include_directories(GeometricShapes_CLI PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/)

add_executable(GeometricShapes
        ${SHAPES_HEADERS}
        ${SHAPES_SOURCES}
        ${GTK_HEADERS}
        ${GTK_SOURCES}
        src/main.cpp)

target_link_libraries(GeometricShapes ${GTKMM_LIBRARIES})

target_include_directories(GeometricShapes PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Gtk/)
target_include_directories(GeometricShapes PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/)
target_include_directories(GeometricShapes PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses)
target_include_directories(GeometricShapes PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractEllipseSubclasses/)
target_include_directories(GeometricShapes PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/)
target_include_directories(GeometricShapes PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/)

add_executable(SandBox ${SHAPES_HEADERS} ${SHAPES_SOURCES} src/SandBox.cpp)

target_include_directories(SandBox PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/)
target_include_directories(SandBox PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses)
target_include_directories(SandBox PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractEllipseSubclasses/)
target_include_directories(SandBox PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/)
target_include_directories(SandBox PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Shapes/AbstractShapeSubclasses/AbstractPolygonSubclasses/AbstractQuadrilateralSubclasses/)
