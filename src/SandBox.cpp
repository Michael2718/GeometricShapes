#include <iostream>
#include <vector>
#include <algorithm>

#include "ShapeFactory.h"
#include "AbstractShape.h"
#include "Point.h"
#include "SimplePolygon.h"
#include "Rectangle.h"
#include "Circle.h"

using std::cout, std::cin, std::cerr, std::vector;

int main() {
    vector<Point> points = {{2,  2},
                            {6,  1},
                            {7,  2},
                            {5,  -2},
                            {1,  -2},
                            {4, 1},
                            {1, 1},
                            {-2, -1},
                            {-2, 2}};

    SimplePolygon simple_polygon(1, points);
    cout << "Simple Polygon Area: " << simple_polygon.Area() << "\n";

    Rectangle rectangle(2, {0, 0}, 3, 2);
    cout << "Rectangle Area: " << rectangle.Area() << "\n";

    Circle circle(3, {-1, -1}, 4);
    cout << "Circle Area: " << circle.Area() << "\n";

    vector<AbstractShape*> shapes;
    shapes.push_back(new SimplePolygon(simple_polygon));
    shapes.push_back(new Rectangle(rectangle));
    shapes.push_back(new Circle(circle));

    ShapeFactory factory;
    factory.AddShape(new SimplePolygon(simple_polygon));
    factory.AddShape(new Rectangle(rectangle));
    factory.AddShape(new Circle(circle));

    for (auto &shape: shapes) {
        delete shape;
    }

    return 0;
}
