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

void AddShape(AbstractShape* shape, vector<AbstractShape *>& shape_list) {
    shape_list.push_back(shape);
}

void DeleteShape(vector<AbstractShape *>& shape_list, int index) {
    if (shape_list[index]->isPartOfComplexShape()) {
        cout << "Shape is part of Complex Shape.\n";
    } else {
        if (shape_list[index]->GetId() == COMPLEX_SHAPE) {
            for (auto shape: shape_list[index]->GetShapes()) {
                shape->SetPartOfComplexShape(false);
            }
        }
        delete shape_list[index];
        shape_list.pop_back();
    }
}

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

    vector<AbstractShape *> shape_list;

    Rectangle rectangle({6, 4}, 12, 8);
    Triangle triangle({4,16}, {12, 8}, {0, 8});
    Circle circle({0, 0}, 4);

    AddShape(new Rectangle(rectangle), shape_list);
    AddShape(new Triangle(triangle), shape_list);
    AddShape(new Circle(circle), shape_list);

    vector<AbstractShape *> complex_shape_list1;
    shape_list[0]->SetPartOfComplexShape(true);
    AddShape(shape_list[0], complex_shape_list1);
    shape_list[1]->SetPartOfComplexShape(true);
    AddShape(shape_list[1], complex_shape_list1);
    shape_list[2]->SetPartOfComplexShape(true);
    AddShape(shape_list[2], complex_shape_list1);
    AddShape(new ComplexShape(complex_shape_list1), shape_list);

    vector<AbstractShape *> complex_shape_list2;
    shape_list[2]->SetPartOfComplexShape(true);
    AddShape(shape_list[2], complex_shape_list2);
    shape_list[3]->SetPartOfComplexShape(true);
    AddShape(shape_list[3], complex_shape_list2);
    AddShape(new ComplexShape(complex_shape_list2), shape_list);

    DeleteShape(shape_list, 4);
    DeleteShape(shape_list, 2);
    DeleteShape(shape_list, 3);
    //DeleteShape(shape_list, 4);
    for (auto shape: shape_list) delete shape;

    return 0;
}
