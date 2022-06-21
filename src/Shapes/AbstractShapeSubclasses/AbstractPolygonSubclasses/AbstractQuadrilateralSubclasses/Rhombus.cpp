#include "Rhombus.h"
#include <stdexcept>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using std::invalid_argument, std::vector, std::string, std::ostringstream;

Rhombus::Rhombus(Point center, double d1, double d2)
    : AbstractQuadrilateral(RHOMBUS,
                            {center.X(), center.Y()+d2/2},
                            {center.X()+d1/2, center.Y()},
                            {center.X(), center.Y()-d2/2},
                            {center.X()-d1/2, center.Y()},
                            center),
    d1(d1), d2(d2) {
    if (d1 <= 0 || d2 <= 0) throw invalid_argument("Invalid diagonals.");
}

Rhombus::Rhombus(Point center, Point p1, Point p2)
    : AbstractQuadrilateral(RHOMBUS, p1, p2,
                            {2 * center.X() - p1.X(), 2 * center.Y() - p1.Y()},
                            {2 * center.X() - p2.X(), 2 * center.Y() - p2.Y()},
                            center),
    d1(sqrt(pow(2*(p1.X() - center.X()), 2) + pow(2*(p1.Y() - center.Y()), 2))),
    d2(sqrt(pow(2*(p2.X() - center.X()), 2) + pow(2*(p2.Y() - center.Y()), 2))) {
    if ((p1.X()-center.X())*(p2.X()-center.X()) + (p1.Y()-center.Y())*(p2.Y()-center.Y()) != 0) {
        throw invalid_argument("Invalid points.");
    }
    if (p1.Y() < p2.Y()) throw invalid_argument("Invalid points.");
}

void Rhombus::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    d1 *= k;
    d2 *= k;
    vector<Point> new_points;
    for (auto point: GetPoints()) {
        new_points.emplace_back(k*(point.X()-GetCenter().X())+GetCenter().X(),
                                k*(point.Y()-GetCenter().Y())+GetCenter().Y());
    }
    SetPoints(new_points);
}

double Rhombus::Perimeter() const {return 2*sqrt(d1*d1 + d2*d2);}

double Rhombus::Area() const {return (d1*d2)/2;}

string Rhombus::Info() const {
    ostringstream oss;

    oss << "Rhombus Info:" << "\n"
        << AbstractQuadrilateral::Info() << "\n"
        << "First Diagonal: " << d1 << "\n"
        << "Second Diagonal: " << d2 << "\n"
        << "Perimeter: " << Perimeter() << "\n"
        << "Area: " << Area();

    return oss.str();
}
