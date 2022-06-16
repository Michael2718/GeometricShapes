/*#include <iostream>
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
        vector<Point> points = {{2,  2},
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
                            {3,2}};

    vector<AbstractShape *> shape_list;

    Rectangle rectangle({6, 4}, 12, 8);
    Triangle triangle({4,16}, {12, 8}, {0, 8});
    Circle circle({0, 0}, 4);
    shape_list.push_back(new Rectangle(rectangle));
    shape_list.push_back(new Triangle(triangle));
    shape_list.push_back(new Circle(circle));

    cout << dynamic_cast<Rectangle*>(shape_list[0])->GetWidth();
    //cout << shape_list[0]->Info();
    //DeleteShape(shape_list, 4);
    for (auto shape: shape_list) delete shape;

    return 0;
}*/



#include <QApplication>
#include "Circle.h"
#include <thread>
#include <iostream>
#include <vector>
#include "QT/Widget.h"



int main(int argc, char *argv[]) {
    std::vector<AbstractShape *> shape_list;

    shape_list.push_back(new Circle({0, 0}, 4));

    std::thread draw_thread(main_draw, argc, argv, shape_list);
    draw_thread.join();
    std::cout << "Ended drawing. Exited from window to console!";
    return 0;
}

