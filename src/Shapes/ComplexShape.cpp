#include "ComplexShape.h"
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include "Point.h"

using std::invalid_argument, std::vector, std::string, std::ostringstream;

Point CalculateCenter(const vector<AbstractShape *> &shapes) {
    double center_x = 0, center_y = 0, area = 0;
    for (auto shape: shapes) {
        center_x += shape->GetCenter().X()*shape->Area();
        center_y += shape->GetCenter().Y()*shape->Area();
        area += shape->Area();
    }
    return {center_x/area, center_y/area};
}

ComplexShape::ComplexShape(const vector<AbstractShape *> &shapes)
    : AbstractShape(COMPLEX_SHAPE), shapes(shapes), center(CalculateCenter(shapes)) {
    if (shapes.empty()) throw invalid_argument("Invalid number of shapes. Complex shape can't be empty.");
    for (auto shape: shapes) {
        if (shape->isPartOfComplexShape()) {
            throw invalid_argument("Invalid shapes. Some of shapes are already in another Complex shape.");
        }
    }
}

void ComplexShape::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    double dx, dy;
    for (auto shape: shapes) {
        dx = (k-1)*(shape->GetCenter().X()-center.X());
        dy = (k-1)*(shape->GetCenter().Y()-center.Y());
        shape->Translate(dx, dy);
        shape->Scale(k);
    }
}

void ComplexShape::Rotate(double angle) {
    for (auto shape: shapes) {
        shape->Rotate(center, angle);
    }
}

void ComplexShape::Rotate(Point r_center, double angle) {
    center.Rotate(r_center, angle);
    for (auto shape: shapes) {
        shape->Rotate(r_center, angle);
    }
}


void ComplexShape::Translate(double dx, double dy) {
    center.Translate(dx, dy);
    for (auto shape: shapes) shape->Translate(dx, dy);
}

double ComplexShape::Perimeter() const {
    double perimeter = 0;
    for (auto shape: shapes) perimeter += shape->Perimeter();
    return perimeter;
}

double ComplexShape::Area() const {
    double area = 0;
    for (auto shape: shapes) area += shape->Area();
    return area;
}

string ComplexShape::Info() const {
    ostringstream oss;

    oss << "Complex Shape Info:" << "\n";

    oss << "Center: " << GetCenter() << "\n"
        << "Perimeter: "<< Perimeter() << "\n"
        << "Area: "<< Area() << "\n";

    for (auto shape: shapes) {
        oss << shape->Info();
        if (shape != shapes.back()) oss << "\n";
    }

    return oss.str();
}
