#include <iostream>
#include <vector>
#include <algorithm>

#include "ShapeFactory.h"
#include "AbstractShape.h"
#include "Point.h"
#include "SimplePolygon.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Trapezoid.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComplexShape.h"

using std::cout, std::cin, std::cerr, std::vector;

int main() {
/*    vector<Point> points = {{2,  2},
                            {6,  1},
                            {7,  2},
                            {5,  -2},
                            {1,  -2},
                            {4, 1},
                            {1, 1},
                            {-2, -1},
                            {-2, 2}};*/

/*    vector<Point> points = {{2,4},
                            {6, 4},
                            {4, 4},
                            {5, 2},
                            {3,2}};*/



    Rectangle rectangle({6, 4}, 12, 8);
    cout << "Rectangle was created." << "\n";

    Triangle triangle({4,16}, {12, 8}, {0, 8});
    cout << "Triangle was created." << "\n";

    vector<AbstractShape *> shapes1;
    shapes1.push_back(new Rectangle(rectangle));
    shapes1.push_back(new Triangle(triangle));

    ComplexShape tr_rec(shapes1);
    cout << "Complex shape(triangle and rectangle) was created." << "\n";

    Circle circle({-4, 4}, 4);
    cout << "Circle created." << "\n";

    vector<AbstractShape *> shapes2;
    shapes2.push_back(new ComplexShape(tr_rec));
    shapes2.push_back(new Circle(circle));

    ComplexShape complex_shape(shapes2);
    cout << "Complex shape(Complex shape(triangle and rectangle) and Circle) was created.\n";

    cout << "\n";
    cout << complex_shape.Info();

    for (auto shape: shapes1) delete shape;
    for (auto shape: shapes2) delete shape;

    return 0;
}
