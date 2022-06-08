#include "Trapezoid.h"
#include <stdexcept>
#include <cmath>
#include <vector>

using std::invalid_argument, std::vector;

Trapezoid::Trapezoid(unsigned int id, Point p1, Point p2, Point p3, Point p4)
    : AbstractQuadrilateral(id, p1, p2, p3, p4),
    a(sqrt(pow(p2.X()-p1.X(),2)+pow(p2.Y()-p1.Y(),2))),
    b(sqrt(pow(p4.X()-p3.X(),2)+pow(p4.Y()-p3.Y(),2))),
    c(sqrt(pow(p3.X()-p2.X(),2)+pow(p3.Y()-p2.Y(),2))),
    d(sqrt(pow(p1.X()-p4.X(),2)+pow(p1.Y()-p4.Y(),2))),
    h(sqrt(c*c - 0.25*pow(((c*c - d*d)/(b - a) + b - a), 2))),
    center({(p1.X()+p2.X()+p3.X()+p4.X())/4, (p1.Y()+p2.Y()+p3.Y()+p4.Y())/4}) {
    if (p3.X()-p4.X() != 0 && p3.Y()-p4.Y() != 0) {
        if ((p2.X()-p1.X()) / (p3.X()-p4.X()) != (p2.Y()-p1.Y()) / (p3.Y()-p4.Y()))
        throw invalid_argument("Invalid points.");
    }
    if (center.Y() - p1.Y() >= 0) throw invalid_argument("Invalid points.");
}

void Trapezoid::Scale(double k) {
    if (k <= 0) throw invalid_argument("Invalid scale factor k.");
    a *= k;
    b *= k;
    c *= k;
    d *= k;
    vector<Point> new_points;
    for (auto point: GetPoints()) {
        new_points.emplace_back(k*point.X()+(1-k)*center.X(),
                                k*point.Y()+(1-k)*center.Y());
    }
    SetPoints(new_points);
}

void Trapezoid::Rotate(double angle) {
    vector<Point> new_points;
    double r_angle = angle * (M_PI / 180.0);
    double new_x, new_y;
    for (auto point: GetPoints()) {
        new_x = center.X() + (point.X()-center.X())*cos(r_angle) + (point.Y()-center.Y())*sin(r_angle);
        new_y = center.Y() - (point.X()-center.X())*sin(r_angle) + (point.Y()-center.Y())*cos(r_angle);
        new_points.emplace_back(new_x, new_y);
    }
    SetPoints(new_points);
}

double Trapezoid::Perimeter() const {return a + b + c + d;}

double Trapezoid::Area() const {return (a + b) / 2 * h;}
