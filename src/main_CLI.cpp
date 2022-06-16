#include <iostream>
#include <utility>
#include <vector>
#include <string>

#include "MainMenu.h"
#include "AbstractShape.h"
#include "Point.h"
#include "SimplePolygon.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapezoid.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Circle.h"
#include "ComplexShape.h"

using std::vector;

int main(int argc, char *argv[]) {
    vector<AbstractShape *> shape_list;

    // shape_list.push_back(new Rectangle({0, 0}, 4, 2));
/*    Rectangle rectangle({6, 4}, 12, 8);
    Triangle triangle({4,16}, {12, 8}, {0, 8});
    Circle circle({0, 0}, 4);

    shape_list.push_back(new Rectangle(rectangle));
    shape_list.push_back(new Triangle(triangle));
    shape_list.push_back(new Circle(circle));*/

    MainMenu(argc, argv, shape_list);

    for (auto shape: shape_list) delete shape;

    return 0;
}