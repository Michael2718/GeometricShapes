#include <iostream>
#include <vector>
#include <string>

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

using std::cout, std::cin, std::vector, std::string, std::exception;

void PrintMainMenu() {
    cout << "Main Menu.\n"
         << "0 - Exit.\n"
         << "1 - Shape list.\n"
         << "2 - Shapes Info.\n"
         << "3 - Specific Shape Info.\n"
         << "4 - Add Shape.\n"
         << "5 - Remove Shape.\n"
         << "6 - Display all shapes\n"
         << "7 - Display specific shape\n"
         << "Selection: ";
}

int SelectFromMenu() {
    int choice;
    do {
        cin.clear();
        cin.ignore();
        cin >> choice;
        cout << "\n";
        if (cin.fail()) {
            cout << "Invalid Choice. Try Again.\n";
        } else {
            return choice;
        }
        PrintMainMenu();
    } while (true);
    // TODOOOOO
}

void PrintShapeList(const vector<AbstractShape *>& shape_list) {
    if (shape_list.empty()) {
        cout << "Shape list is empty.\n";
    } else {
        cout << "Shape list:\n";
        cout << "\n";
        for (int i = 0; i < shape_list.size(); i++) {
            cout << i << " - " <<  shape_list[i]->GetStringId() << "\n";
        }
    }
    cout << "\n";
}

void PrintShapesInfo(const vector<AbstractShape *>& shape_list) {
    if (shape_list.empty()) {
        cout << "Shape list is empty.\n";
    } else {
        cout << "Shapes Info:\n";
        cout << "\n";
        for (auto shape: shape_list) {
            cout << shape->Info() << "\n";
        }
    }
    cout << "\n";
}

int SelectShapeFromList(const vector<AbstractShape *>& shape_list) {
    int index;
    do {
        cin.clear();
        cin.ignore();
        cout << "Select index: ";
        cin >> index;
        if (cin.fail() || index < 0 || index >= shape_list.size()) {
            cout << "Invalid shape index. Try Again.\n";
        }
    } while (cin.fail() || index < 0 || index >= shape_list.size());
    cout << "\n";
    return index;
}

void PrintShapeInfo(const vector<AbstractShape *>& shape_list, int index) {
    cout << shape_list[index]->Info() << "\n";
    cout << "\n";
}

void PrintAddShapeMenu() {
    cout << "Select Shape to Add.\n"
         << "0 - Exit to main menu.\n"
         << "1 - Simple Polygon.\n"
         << "2 - Rectangle.\n"
         << "3 - Rhombus.\n"
         << "4 - Trapezoid.\n"
         << "5 - Triangle.\n"
         << "6 - Ellipse.\n"
         << "7 - Circle.\n"
         << "8 - ComplexShape.\n";
}

int SelectFromAddShapeMenu(const vector<AbstractShape *>& shape_list) {
    int choice;
    do {
        cin.clear();
        cin.ignore();
        cout << "Selection: ";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 8) {
            cout << "Invalid choice. Try Again.\n";
        }
    } while (cin.fail() || choice < 0 || choice > 8);
    cout << "\n";
    return choice;
}

vector<Point> InputVerticesOfSimplePolygon(int vertex_count) {
    cout << "Enter " << vertex_count
         <<" vertices of simple polygon in clockwise order, starting from left-upper corner "
         << " in the following format:\n"
         << "x1 y1\n"
         << "x2 y2\n"
         << "...\n"
         << "xn yn\n";

    vector<Point> points;
    double px, py;
    for (int i = 0; i < vertex_count; i++) {
        cin >> px >> py;
        points.emplace_back(px, py);
    }
    return points;
}

void AddSimplePolygon(vector<AbstractShape *>& shape_list) {
    int vertex_count = 0;
    while (vertex_count < 3) {
        cout << "Enter number of vertices: ";
        cin >> vertex_count;
    }

    vector<Point> points;
    while (true) {
        points = InputVerticesOfSimplePolygon(vertex_count);
        try {
            SimplePolygon sp(points);
            break;
        } catch (exception& ex) {
            cout << "Simple Polygon was not created. " << ex.what() << " "
                 << "Try Again.\n";
            continue;
        }
    }

    SimplePolygon sp(points);
    shape_list.push_back(new SimplePolygon(sp));
    cout << "Simple Polygon was successfully added.\n";
}

void AddRectangle(vector<AbstractShape *>& shape_list) {

    cout << "Select definition method:\n";
    cout << "1 - By center, width, height.\n"
         << "2 - By Four Points.\n";
    int choice;
    do {
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Try Again.\n";
            cout << "Select definition method:\n";
            cout << "1 - By center, width, height.\n"
                 << "2 - By Four Points.\n";
        }
    } while (choice != 1 && choice != 2);

    if(choice == 1) {
        double cx, cy, width, height;
        cout << "Enter center of Rectangle in format:\n"
             << "x y\n";
        cin >> cx >> cy;

        while (true) {
            cout << "Enter width: ";
            cin >> width;
            cout << "Enter height: ";
            cin >> height;
            try {
                Rectangle rec({cx, cy}, width, height);
                break;
            } catch (exception& ex) {
                cout << "Rectangle was not created. " << ex.what() << " "
                     << "Try Again.\n";
                continue;
            }
        }
        Rectangle rec({cx, cy}, width, height);
        shape_list.push_back(new Rectangle(rec));
    } else if(choice == 2) {
        double px, py;
        vector<Point> points;
        while (true) {
            cout << "Enter 4 Points of Rectangle in clockwise order, starting from left-upper corner"
                 << "in following format:\n"
                 << "x y\n";
            for (int i = 0; i < 4; i++) {
                cin >> px >> py;
                points.emplace_back(px, py);
            }
            try {
                Rectangle rec(points[0], points[1], points[2], points[3]);
                break;
            } catch (exception& ex) {
                cout << "Rectangle was not created. " << ex.what() << " "
                     << "Try Again.\n";
                points.clear();
                continue;
            }
        }
        Rectangle rec(points[0], points[1], points[2], points[3]);
        shape_list.push_back(new Rectangle(rec));
    }
    cout << "Rectangle was successfully added.\n";
}

void AddRhombus(vector<AbstractShape *>& shape_list) {
/*    double cx, cy, width, height;
    cout << "Enter center of Rectangle in format:\n"
         << "x y\n";
    cin >> cx >> cy;
    Rhombus r()

    while (true) {
        cout << "Enter width: ";
        cin >> width;
        cout << "Enter height: ";
        cin >> height;
        try {
            Rectangle rec({cx, cy}, width, height);
            break;
        } catch (exception& ex) {
            cout << "Rectangle was not created. " << ex.what() << " "
                 << "Try Again.\n";
            continue;
        }
    }

    Rectangle rec({cx, cy}, width, height);
    shape_list.push_back(new Rectangle(rec));
    cout << "Rectangle was successfully added.\n";*/
}

void AddShape(vector<AbstractShape *>& shape_list, int choice) {
    switch (choice) {
        case 1:
            AddSimplePolygon(shape_list);
            break;
        case 2:
            AddRectangle(shape_list);
            break;
        case 3:
            AddRhombus(shape_list);
            break;
    }
}

int main() {
    vector<AbstractShape *> shape_list;

    int choice, shape_choice;

    system("clear");
    do {
        PrintMainMenu();
        //choice = SelectFromMenu();
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Thanks for using!\n";
                break;
            case 1:
                PrintShapeList(shape_list);
                break;
            case 2:
                PrintShapesInfo(shape_list);
                break;
            case 3:
                PrintShapeList(shape_list);
                PrintShapeInfo(shape_list, SelectShapeFromList(shape_list));
                break;
            case 4:
                PrintAddShapeMenu();
                shape_choice = SelectFromAddShapeMenu(shape_list);
                AddShape(shape_list, shape_choice);
                break;
            default:
                cout << "Invalid Choice.\n";
                cout << "\n";
                break;
        }
    } while (choice != 0);

    for (auto shape: shape_list) delete shape;

    return 0;
}