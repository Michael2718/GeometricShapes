#include <iostream>
#include <utility>
#include <thread>
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

#include "QT/Draw.h"

using std::cout, std::cin, std::vector, std::string, std::exception, std::move, std::thread;

/* MAIN MENU */
void PrintMainMenu() {
    cout << "Main Menu.\n"
         << "0 - Exit.\n"
         << "1 - Shape list.\n"
         << "2 - Shapes Info.\n"
         << "3 - Specific Shape Info.\n"
         << "4 - Add Shape.\n"
         << "5 - Remove Shape.\n"
         << "6 - Transform Shape.\n"
         << "7 - Draw all shapes.\n"
         << "Selection: ";
}

/* MAIN MENU OPTIONS */
void PrintShapeList(const vector<AbstractShape *>& shape_list) {
    if (shape_list.empty()) {
        cout << "Shape list is empty.\n";
    } else {
        cout << "Shape list:\n";
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

// SPECIFIC SHAPE INFO
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

// ADD SHAPE
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

/* ADDING SHAPE */

// ALL SHAPES
Point InputCenter() {
    double cx, cy;
    cout << "Enter center in format:\n"
         << "x y\n";
    cin >> cx >> cy;
    return {cx, cy};
}

void AddShape(AbstractShape* shape, vector<AbstractShape *>& shape_list) {
    shape_list.push_back(shape);
}

// SIMPLE POLYGON
int InputVertexCount() {
    int vertex_count = 0;
    do {
        cout << "Enter number of vertices: ";
        cin >> vertex_count;
        if (vertex_count < 3) {
            cout << "Invalid number of vertices(should be in range [3,+∞). Try again.\n";
        }
    } while (vertex_count < 3);
    return vertex_count;
}

vector<Point> InputVerticesOfSimplePolygon(int vertex_count) {
    cout << "Enter " << vertex_count
         <<" vertices of Simple Polygon in clockwise order, starting with left-upper corner "
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

SimplePolygon CreateSimplePolygon() {
    vector<Point> points;
    int vertex_count;
    while (true) {
        vertex_count = InputVertexCount();
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
    return SimplePolygon(points);
}

// RECTANGLE
int InputRectangleDefinitionMethod() {
    cout << "Select definition method:\n";
    cout << "1 - By center and width, height.\n"
         << "2 - By Four Points.\n"
         << "Selection: ";
    int choice;
    do {
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Try Again.\n";
            cout << "Select definition method:\n";
            cout << "1 - By center, width, height.\n"
                 << "2 - By Four Points.\n"
                 << "Selection: ";
        }
    } while (choice != 1 && choice != 2);
    return choice;
}

vector<double> InputRectangleSides() {
    double width, height;
    do {
        cout << "Enter width: ";
        cin >> width;
        cout << "Enter height: ";
        cin >> height;
        if (width <= 0 || height <=0) {
            cout << "Invalid width or height. Try Again.\n";
        }
    } while (width <= 0 || height <=0);
    return {width, height};
}

vector<Point> InputRectanglePoints() {
    cout << "Enter 4 Points of Rectangle in clockwise order, starting with left-upper corner, "
         << "in following format:\n"
         << "x y\n";

    double px, py;
    vector<Point> points;

    for (int i = 0; i < 4; i++) {
        cin >> px >> py;
        points.emplace_back(px, py);
    }

    return points;
}

Rectangle CreateRectangle() {
    int choice = InputRectangleDefinitionMethod();

    if(choice == 1) {
        Point center;
        vector<double> sides;
        while (true) {
            center = InputCenter();
            sides = InputRectangleSides();
            try {
                Rectangle rectangle(center, sides[0], sides[1]);
                break;
            } catch (exception &ex) {
                cout << "Rectangle was not created. " << ex.what() << " "
                     << "Try Again.\n";
                continue;
            }
        }
        return {center, sides[0], sides[1]};
    } else if(choice == 2) {
        vector<Point> points;
        while (true) {
            points = InputRectanglePoints();
            try {
                Rectangle rectangle(points[0], points[1], points[2], points[3]);
                break;
            } catch (exception &ex) {
                cout << "Rectangle was not created. " << ex.what() << " "
                     << "Try Again.\n";
                points.clear();
                continue;
            }
        }
        return {points[0], points[1], points[2], points[3]};
    }
    return {{0, 0}, 1, 1};
}

// RHOMBUS
int InputRhombusDefinitionMethod() {
    cout << "Select definition method:\n";
    cout << "1 - By center and two diagonals.\n"
         << "2 - By center and two points.\n"
         << "Selection: ";
    int choice;
    do {
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Try Again.\n";
            cout << "Select definition method:\n";
            cout << "1 - By center and two diagonals.\n"
                 << "2 - By center and two points.\n"
                 << "Selection: ";
        }
    } while (choice != 1 && choice != 2);
    return choice;
}

vector<double> InputRhombusDiagonals() {
    double d1, d2;
    do {
        cout << "Enter First diagonal(parallel to OX axis): ";
        cin >> d1;
        cout << "Enter Second diagonal(parallel to OY axis): ";
        cin >> d2;
        if (d1 <= 0 || d2 <=0) {
            cout << "Invalid diagonals. Try Again.\n";
        }
    } while (d1 <= 0 || d2 <=0);
    return {d1, d2};
}

vector<Point> InputRhombusTwoPoints() {
    cout << "Enter 2 Points of Rhombus in clockwise order, starting with upper point, "
         << "in following format:\n"
         << "x y\n";

    double px, py;
    vector<Point> points;

    for (int i = 0; i < 2; i++) {
        cin >> px >> py;
        points.emplace_back(px, py);
    }

    return points;
}

Rhombus CreateRhombus() {
    int choice = InputRhombusDefinitionMethod();
    Point center;

    if(choice == 1) {
        vector<double> diagonals;

        while (true) {
            center = InputCenter();
            diagonals = InputRhombusDiagonals();
            try {
                Rhombus rmb(center, diagonals[0], diagonals[1]);
                break;
            } catch (exception& ex) {
                cout << "Rhombus was not created. " << ex.what() << " "
                     << "Try Again.\n";
                continue;
            }
        }
        return {center, diagonals[0], diagonals[1]};
    } else if(choice == 2) {
        vector<Point> two_points;
        while (true) {
            center = InputCenter();
            two_points = InputRhombusTwoPoints();
            try {
                Rhombus rhombus(center, two_points[0], two_points[1]);
                break;
            } catch (exception& ex) {
                cout << "Rhombus was not created. " << ex.what() << " "
                     << "Try Again.\n";
                continue;
            }
        }
        return {center, two_points[0], two_points[1]};
    }
    return {{0,0}, 1, 1};
}

// TRAPEZOID
vector<Point> InputTrapezoidPoints() {
    double px, py;
    vector<Point> points;

    cout << "Enter 4 Points of Trapezoid in clockwise order, starting with upper-left point, "
         << "in following format:\n"
         << "x y\n";

    for (int i = 0; i < 4; i++) {
        cin >> px >> py;
        points.emplace_back(px, py);
    }

    return points;
}

Trapezoid CreateTrapezoid() {
    vector<Point> points;
    while (true) {
        points = InputTrapezoidPoints();
        try {
            Trapezoid trapezoid(points[0], points[1], points[2], points[3]);
            break;
        } catch (exception& ex) {
            cout << "Trapezoid was not created. " << ex.what() << " "
                 << "Try Again.\n";
            continue;
        }
    }
    return {points[0], points[1], points[2], points[3]};
}

// TRIANGLE
vector<Point> InputPointsOfTriangle() {
    cout << "Enter 3 points of Triangle in clockwise order, starting with upper-upper one, "
         << " in the following format:\n"
         << "x y\n";

    vector<Point> points;
    double px, py;
    for (int i = 0; i < 3; i++) {
        cin >> px >> py;
        points.emplace_back(px, py);
    }
    return points;
}

Triangle CreateTriangle() {
    vector<Point> points;
    while (true) {
        points = InputPointsOfTriangle();
        try {
            Triangle triangle(points);
            break;
        } catch (exception& ex) {
            cout << "Triangle was not created. " << ex.what() << " "
                 << "Try Again.\n";
            continue;
        }
    }
    return Triangle(points);
}

// ELLIPSE
vector<double> InputAxes() {
    double a, b;
    do {
        cout << "Enter Semi-major axis 'a'(parallel to OX axis): ";
        cin >> a;
        cout << "Enter Semi-minor axis 'b'(parallel to OY axis): ";
        cin >> b;
        if (a <= 0 || b <=0) {
            cout << "Invalid axes. Try Again.\n";
        }
    } while (a <= 0 || b <=0);
    return {a, b};
}

Ellipse CreateEllipse() {
    Point center;
    vector<double> axes;
    while (true) {
        center = InputCenter();
        axes = InputAxes();
        try {
            Ellipse ellipse(center, axes[0], axes[1]);
            break;
        } catch (exception& ex) {
            cout << "Ellipse was not created. " << ex.what() << " "
                 << "Try Again.\n";
            continue;
        }
    }
    return {center, axes[0], axes[1]};
}

// CIRCLE
double InputRadius() {
    double radius;
    do {
        cout << "Enter Radius: ";
        cin >> radius;
        if (radius <= 0) {
            cout << "Invalid Radius. Try Again.\n";
        }
    } while (radius <= 0);
    return radius;
}

Circle CreateCircle() {
    Point center;
    double radius;
    while (true) {
        center = InputCenter();
        radius = InputRadius();
        try {
            Circle circle(center, radius);
            break;
        } catch (exception& ex) {
            cout << "Circle was not created. " << ex.what() << " "
                 << "Try Again.\n";
            continue;
        }
    }
    return {center, radius};
}

// COMPLEX_SHAPE
bool isShapeIndicesCorrect(const vector<int>& indices, size_t shape_list_size) {
    if (indices[0] < 0 || indices[0] >= shape_list_size) return false;
    for (int i = 0; i < indices.size()-1; i++) {
        for (int j = i+1; j < indices.size(); j++) {
            if (indices[i] == indices[j]) return false;
            if (indices[j] < 0 || indices[j] >= shape_list_size) return false;
        }
    }
    return true;
}

vector<int> InputShapeIndices(vector<AbstractShape *>& shape_list) {
    int number_of_shapes;

    do {
        cout << "Enter Number of Shapes: ";
        cin >> number_of_shapes;
        if (number_of_shapes <= 0 || number_of_shapes > shape_list.size()) {
            cout << "Invalid Number of Shapes. Try Again.\n";
        }
    } while (number_of_shapes <= 0 || number_of_shapes > shape_list.size());

    vector<int> indices(number_of_shapes);
    do {
        PrintShapeList(shape_list);
        cout << "Select " << number_of_shapes << " shapes from list.\n"
             << "Enter unique indices space-separated: ";
        for (int i = 0; i < number_of_shapes; i++) {
            cin >> indices[i];
        }
        if (!isShapeIndicesCorrect(indices, shape_list.size())) {
            cout << "Invalid indices. Try again.\n";
            indices = vector<int>(number_of_shapes);
        }
    } while(!isShapeIndicesCorrect(indices, shape_list.size()));

    return indices;
}

ComplexShape CreateComplexShape(vector<AbstractShape *>& shape_list) {
    vector<int> indices;
    vector<AbstractShape *> complex_shape_list;
    while (true) {
        PrintShapeList(shape_list);
        indices = InputShapeIndices(shape_list);
        for (auto index: indices) {
            AddShape(shape_list[index], complex_shape_list);
        }
        try {
            ComplexShape complex_shape(complex_shape_list);
            break;
        } catch (exception &ex) {
            cout << "Complex Shape was not created. " << ex.what() << " "
                 << "Try Again.\n";
            continue;
        }
    }
    ComplexShape complex_shape(complex_shape_list);
    for (auto shape: complex_shape_list) shape->SetPartOfComplexShape(true);
    return complex_shape;
}

void AddShapeMenu(vector<AbstractShape *>& shape_list, int choice) {
    AbstractShape* p_shape = nullptr;
    switch (choice) {
        case 1:
            p_shape = new SimplePolygon(CreateSimplePolygon());
            break;
        case 2:
            p_shape = new Rectangle(CreateRectangle());
            break;
        case 3:
            p_shape = new Rhombus(CreateRhombus());
            break;
        case 4:
            p_shape = new Trapezoid(CreateTrapezoid());
            break;
        case 5:
            p_shape = new Triangle(CreateTriangle());
            break;
        case 6:
            p_shape = new Ellipse(CreateEllipse());
            break;
        case 7:
            p_shape = new Circle(CreateCircle());
            break;
        case 8:
            if (shape_list.empty()) {
                cout << "Shape list is empty.\n";
                cout << "\n";
            } else {
                p_shape = new ComplexShape(CreateComplexShape(shape_list));
            }
        default:
            break;
    }
    if (p_shape != nullptr) {
        AddShape(p_shape, shape_list);
        cout << "\n";
        cout << "Shape was added successfully.\n";
        cout << "\n";
    }
}

/* DELETING SHAPE */
int SelectShapeFromListToDelete(vector<AbstractShape *>& shape_list) {
    int index;
    do {
        PrintShapeList(shape_list);
        cout << "Select Shape from list to delete.\n"
             << "Enter shape index: ";
        cin >> index;
        if (index < 0 || index >= shape_list.size()) {
            cout << "Invalid index. Try again.\n";
        }
    } while (index < 0 || index >= shape_list.size());
    return index;
}

void DeleteShape(vector<AbstractShape *>& shape_list, int index) {
    if (shape_list[index]->isPartOfComplexShape()) {
        cout << "\n";
        cout << "Shape is part of Complex Shape.\n";
        cout << "\n";
    } else {
        if (shape_list[index]->GetId() == COMPLEX_SHAPE) {
            for (auto shape: dynamic_cast<ComplexShape*>(shape_list[index])->GetShapes()) {
                shape->SetPartOfComplexShape(false);
            }
        }
        delete shape_list[index];
        shape_list.erase(shape_list.begin()+index);
        cout << "\n";
        cout << "Shape was deleted successfully.\n";
        cout << "\n";
    }
}

/* TRANSFORMING SHAPE */
int SelectShapeFromListToTransform(vector<AbstractShape *>& shape_list) {
    int index;
    do {
        cout << "Select Shape from list to transform.\n"
             << "Enter shape index: ";
        cin >> index;
        cout << "\n";
        if (index < 0 || index >= shape_list.size()) {
            cout << "Invalid index. Try again.\n";
        }
    } while (index < 0 || index >= shape_list.size());
    return index;
}

void PrintTransformMethods() {
    cout << "Select Transform Method.\n"
         << "0 - Exit to main menu.\n"
         << "1 - Scale.\n"
         << "2 - Rotate.\n"
         << "3 - Translate.\n";
}

int SelectTransformMethod() {
    int choice;
    do {
        PrintTransformMethods();
        cout << "Selection: ";
        cin >> choice;
        cout << "\n";
        if (choice < 0 || choice > 3) {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice < 0 || choice > 3);
    return choice;
}

double InputScaleFactor() {
    double k;
    do {
        cout << "Enter Scale Factor 'k'(k > 0): ";
        cin >> k;
        if (k <= 0) {
            cout << "Invalid Scale Factor. Try Again.\n";
        }
    } while (k <= 0);
    return k;
}

double InputRotationAngle() {
    double angle;
    cout << "Enter Angle to rotate shape in clockwise order: ";
    cin >> angle;
    return angle;
}

vector<double> InputTranslateVector() {
    double dx, dy;
    cout << "Enter Translate Vector coordinates in following format:\n"
         << "x y\n";
    cin >> dx >> dy;
    return {dx, dy};
}

void TransformShape(vector<AbstractShape *>& shape_list, int index, int choice) {
    vector<double> translate_vector;
    switch (choice) {
        case 1:
            shape_list[index]->Scale(InputScaleFactor());
            break;
        case 2:
            shape_list[index]->Rotate(InputRotationAngle());
            break;
        case 3:
            translate_vector = InputTranslateVector();
            shape_list[index]->Translate(translate_vector[0], translate_vector[1]);
        default:
            break;
    }
    cout << "\n";
    cout << "Transformed successfully.\n";
    cout << "\n";
}

void MainMenu(int argc, char *argv[], vector<AbstractShape *>& shape_list) {
    int choice, shape_choice, delete_index, transform_index, transform_method;
    thread draw_thread;
    system("clear");
    do {
        PrintMainMenu();
        cin >> choice;
        cout << "\n";
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
                if (!shape_list.empty()) {
                    PrintShapeInfo(shape_list, SelectShapeFromList(shape_list));
                }
                break;
            case 4:
                PrintAddShapeMenu();
                shape_choice = SelectFromAddShapeMenu(shape_list);
                AddShapeMenu(shape_list, shape_choice);
                break;
            case 5:
                delete_index = SelectShapeFromListToDelete(shape_list);
                DeleteShape(shape_list, delete_index);
                break;
            case 6:
                PrintShapeList(shape_list);
                if (!shape_list.empty()) {
                    transform_index = SelectShapeFromListToTransform(shape_list);
                    transform_method = SelectTransformMethod();
                    TransformShape(shape_list, transform_index, transform_method);
                }
                break;
            case 7:
                cout << "Shapes are being drawn.\n";
                Draw(argc, argv, shape_list);
                cout << "\n";
                cout << "Shapes were drawn successfully.\n";
                cout << "\n";
                break;
            default:
                cout << "Invalid Choice.\n";
                cout << "\n";
                break;
        }
    } while (choice != 0);
}
