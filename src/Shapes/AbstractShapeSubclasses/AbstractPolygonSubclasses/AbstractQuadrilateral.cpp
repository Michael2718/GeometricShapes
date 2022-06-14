#include "AbstractQuadrilateral.h"
#include <stdexcept>
#include <vector>

using std::invalid_argument, std::vector;

AbstractQuadrilateral::AbstractQuadrilateral(ShapeID id, Point p1, Point p2, Point p3, Point p4, Point center)
    : AbstractPolygon(id, 4),
    p1(p1), p2(p2), p3(p3), p4(p4), center(center) {
    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
        throw invalid_argument("Invalid Points.");
    }
}

vector<Point> AbstractQuadrilateral::GetPoints() const {return vector<Point>({p1, p2, p3, p4});}

void AbstractQuadrilateral::Rotate(double angle) {
    vector<Point> new_points;
    for (auto point: GetPoints()) {
        new_points.emplace_back(point.Rotate(center, angle));
    }
    SetPoints(new_points);
}

void AbstractQuadrilateral::Rotate(Point r_center, double angle) {
    vector<Point> new_points;
    for (auto point: GetPoints()) {
        new_points.emplace_back(point.Rotate(r_center, angle));
    }
    SetPoints(new_points);
}

void AbstractQuadrilateral::Translate(double dx, double dy) {
    center.Translate(dx, dy);
    p1.Translate(dx, dy);
    p2.Translate(dx, dy);
    p3.Translate(dx, dy);
    p4.Translate(dx, dy);
}

void AbstractQuadrilateral::SetPoints(const std::vector<Point> &new_points) {
    if (new_points.size() != 4) throw invalid_argument("Invalid new_points vector size. Should be the size of 4.");
    p1 = new_points[0];
    p2 = new_points[1];
    p3 = new_points[2];
    p4 = new_points[3];
}
