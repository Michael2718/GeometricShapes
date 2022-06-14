#include <iostream>
#include <vector>
#include "ShapeFactory.h"
#include "SimplePolygon.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Point.h"

using std::cout, std::cin, std::vector;

void DisplayMainMenu() {
    cout << "Main Menu.\n";
    cout << "1 - Shape list.\n";
    cout << "2 - Shape Info.\n";
    cout << "3 - Add Shape.\n";
    cout << "4 - Remove Shape.\n";
    cout << "0 - Exit.\n";
    cout << "Selection: ";
}

void DisplayShapeSelection() {
    cout << "Select Shape.\n";
    cout << "1 - Simple Polygon.\n";
    cout << "2 - Rectangle.\n";
    cout << "3 - Rhombus.\n";
    cout << "4 - Trapezoid.\n";
    cout << "5 - Ellipse.\n";
    cout << "6 - Circle.\n";
    cout << "0 - Exit to main menu.\n";
    cout << "Selection: ";
}

void DisplayShapeList(const ShapeFactory& factory) {
    cout << "Shapes:\n";
    for (auto shape: factory.GetShapes()) {
        cout << shape << "\n";
    }
    cout << "\n";
}

void ChooseShape(int choice) {
    switch (choice) {
        case 1:
            break;
        case 2:
            cout << "\n";
            break;
        case 3:
            cout << "\n";
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            break;
    }
}

int main() {
    //ShapeFactory factory;
    vector<Point> points = {{2,  2},
                            {6,  1},
                            {7,  2},
                            {5,  -2},
                            {1,  -2},
                            {4, 1},
                            {1, 1},
                            {-2, -1},
                            {-2, 2}};
    SimplePolygon sp(1, points);
    Rectangle r(2, {0, 0}, 3, 2);
    Circle c(3, {-1, -1}, 4);

/*    vector<AbstractShape*> shapes;
    shapes.push_back(new SimplePolygon(sp));
    shapes.push_back(new Rectangle(r));
    shapes.push_back(new Circle(c));*/


    ShapeFactory factory;
    factory.AddShape(new SimplePolygon(sp));
    factory.AddShape(new Rectangle(r));
    factory.AddShape(new Circle(c));

    int choice = 0, shape_index = 0, shape_choice = 0;

    system("clear");
    do {
        DisplayMainMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\n";
                if (factory.GetQuantity() == 0) {
                    cout << "Shape list is empty.";
                } else {
                    DisplayShapeList(factory);
                }
                break;
            case 2:
                cout << "\n";
                if (factory.GetQuantity() == 0) {
                    cout << "Shape list is empty.";
                } else {
                    cout << "There are " << factory.GetQuantity()
                         << " Shapes in the list.\n"
                         << "Enter shape index: ";
                    cin >> shape_index;
                    cout << factory.GetShapes()[shape_index] << "\n";
                    cout << "\n";
                }
                break;
            case 3:
                cout << "\n";
                DisplayShapeSelection();
                cin >> shape_choice;

                break;
            case 4:
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (choice != 0);

    return 0;
}