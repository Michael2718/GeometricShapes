cmake_minimum_required(VERSION 3.22)
project(GeometricShapes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS )

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(GeometricShapes src/main.cpp)
#add_executable(Ellipse_Circle
#        src/AbstractShapeSubclasses/AbstractEllipseSubclasses/Ellipse.h src/AbstractShapeSubclasses/AbstractEllipseSubclasses/Circle.h
#        src/AbstractShapeSubclasses/AbstractEllipseSubclasses/Ellipse.cpp src/AbstractShapeSubclasses/AbstractEllipseSubclasses/Circle.cpp
#        src/AbstractShapeSubclasses/AbstractEllipse.h src/AbstractShapeSubclasses/AbstractEllipse.cpp
#        src/AbstractShape.h src/AbstractShape.cpp
#        src/main_CLI.cpp)

add_executable(SandBox
        src/AbstractShape.h
        src/AbstractShape.cpp
        src/AbstractShapeSubclasses/AbstractPolygon.h
        src/AbstractShapeSubclasses/AbstractPolygon.cpp
        src/AbstractShapeSubclasses/AbstractPolygonSubclasses/Polygon.h
        src/AbstractShapeSubclasses/AbstractPolygonSubclasses/Polygon.cpp
        src/Point.h
        src/Point.cpp
        src/AbstractShapeSubclasses/AbstractEllipse.h
        src/AbstractShapeSubclasses/AbstractEllipse.cpp
        src/AbstractShapeSubclasses/AbstractEllipseSubclasses/Ellipse.h
        src/AbstractShapeSubclasses/AbstractEllipseSubclasses/Ellipse.cpp
        src/AbstractShapeSubclasses/AbstractEllipseSubclasses/Circle.h
        src/AbstractShapeSubclasses/AbstractEllipseSubclasses/Circle.cpp
        src/SandBox.cpp)

target_link_libraries(GeometricShapes
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

