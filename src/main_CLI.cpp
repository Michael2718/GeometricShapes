#include <iostream>
//#include "Shape.h"
#include "ShapeSubclasses/AbstractEllipseSubclasses/Ellipse.h"
#include "ShapeSubclasses/AbstractEllipseSubclasses/Circle.h"

using std::cout, std::cin;

int main() {
    Point center(-1, 1);
    Ellipse e(center, 2, 1);
    Circle c(center, 1);
    cout << e.Area() << "\n";
    cout << c.Area();
    return 0;
}