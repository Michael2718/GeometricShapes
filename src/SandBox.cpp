#include <iostream>
#include <vector>
#include <algorithm>

#include "ShapeFactory.h"
#include "AbstractShape.h"
#include "Point.h"
#include "SimplePolygon.h"
#include "Rectangle.h"
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
                            {-2, 2}};
    vector<Point> points = {{2,4},
                            {6, 4},
                            {4, 4},
                            {5, 2},
                            {3,2}};*/

    Rectangle rectangle(2, {5.5, 2}, 7, 4);
    cout << "Rectangle created. Center: " << rectangle.GetCenter() << "\n";

    Circle circle(1, {0, 2}, 2);
    cout << "Circle created. Center: " << circle.GetCenter() << "\n";

    vector<AbstractShape *> shapes = {new Circle(circle), new Rectangle(rectangle)};

    ComplexShape complex_shape(3, shapes);
    cout << "Complex shape created. Center: " << complex_shape.GetCenter() << "\n";
    complex_shape.Scale(2);
    cout << "Complex shape scaled by 2" << "\n";
    cout << "Center of Circle: " << complex_shape.GetShapes()[0]->GetCenter() << "\n";
    cout << "Center of Rectangle: " << complex_shape.GetShapes()[1]->GetCenter() << "\n";

/*    vector<AbstractShape*> shapes;
    shapes.push_back(new SimplePolygon(simple_polygon));
    shapes.push_back(new Rectangle(rectangle));
    shapes.push_back(new Circle(circle));

    ShapeFactory factory;
    factory.AddShape(new SimplePolygon(simple_polygon));
    factory.AddShape(new Rectangle(rectangle));
    factory.AddShape(new Circle(circle));

    for (auto &shape: shapes) {
        delete shape;
    }*/

    return 0;
}
