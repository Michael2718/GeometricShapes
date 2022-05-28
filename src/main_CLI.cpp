#include <iostream>
//#include "Shape.h"
#include "ShapeSubclasses/AbstractEllipseSubclasses/Ellipse.h"
#include "ShapeSubclasses/AbstractEllipseSubclasses/Circle.h"

using std::cout, std::cin;

int main() {
    Point center(-1, 1);
    Ellipse e(0, center, 2, 1);
    Circle c(1, center, 1);
    cout << e.Perimeter() << "\n";
    cout << c.Perimeter() << "\n";
    //cout << c.getRadius();
    return 0;
}