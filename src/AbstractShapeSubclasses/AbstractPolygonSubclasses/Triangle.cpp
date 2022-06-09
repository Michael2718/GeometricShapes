#include "Triangle.h"
#include <stdexcept>
#include <vector>
#include "cmath"

using std::invalid_argument, std::vector;

Triangle::Triangle(unsigned int id, std::vector<Point> points)
    : AbstractPolygon(id, 3), p1(points[0]), p2(points[1]), p3(points[2]),
    center({(p1.X()+p2.X()+p3.X())/3, (p1.Y()+p2.Y()+p3.Y())/3}) {
    if (points.size() != 3) throw invalid_argument("Invalid points.");
    if (this->Area() == 0)  throw invalid_argument("Invalid points.");
    if(p1 == p2 || p1 == p2 || p1 == p3 || p2 == p3) throw invalid_argument("Invalid points.");
}

Triangle::Triangle(unsigned int id, Point p1, Point p2, Point p3)
    : AbstractPolygon(id, 3), p1(p1), p2(p2), p3(p3),
    center({(p1.X()+p2.X()+p3.X())/3, (p1.Y()+p2.Y()+p3.Y())/3}) {
    if (this->Area() == 0) throw invalid_argument("Invalid points.");
    if(p1 == p2 || p1 == p2 || p1 == p3 || p2 == p3) throw invalid_argument("Invalid points.");
}

void Triangle::SetPoints(const std::vector<Point>& new_points) {
    p1 = new_points[0];
    p2 = new_points[1];
    p3 = new_points[2];
}

void Triangle::Scale(double k) {
    vector<Point> new_points;
    for (auto point: GetPoints()) {
        new_points.emplace_back(k*point.X()+(1-k)*center.X(),
                                k*point.Y()+(1-k)*center.Y());
    }
    SetPoints(new_points);
}

void Triangle::Rotate(double angle) {
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

double Triangle::Perimeter() const {
    double a = sqrt(pow(p2.X() - p1.X(), 2) + pow(p2.Y() - p1.Y(), 2));
    double b = sqrt(pow(p3.X() - p2.X(), 2) + pow(p3.Y() - p2.Y(), 2));
    double c = sqrt(pow(p1.X() - p3.X(), 2) + pow(p1.Y() - p3.Y(), 2));
    return a + b + c;
}

double Triangle::Area() const {
    return 0.5*std::abs(p1.X()*(p2.Y() - p3.Y()) +
                           p2.X()*(p3.Y() - p1.Y()) +
                           p3.X()*(p1.Y() - p2.Y()));
}
