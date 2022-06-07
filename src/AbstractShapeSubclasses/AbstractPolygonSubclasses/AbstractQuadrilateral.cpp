#include "AbstractQuadrilateral.h"
#include <stdexcept>
#include <vector>

using std::invalid_argument, std::vector;

AbstractQuadrilateral::AbstractQuadrilateral(unsigned int id, Point p1, Point p2, Point p3, Point p4)
    : AbstractPolygon(id, 4),
    p1(p1), p2(p2), p3(p3), p4(p4) {
    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
        throw invalid_argument("Invalid Points.");
    }
}

vector<Point> AbstractQuadrilateral::GetPoints() const {return vector<Point>({p1, p2, p3, p4});}

void AbstractQuadrilateral::SetPoints(const std::vector<Point> &new_points) {
    if (new_points.size() != 4) throw invalid_argument("Invalid new_points vector size. Should be the size of 4.");
    p1 = new_points[0];
    p2 = new_points[1];
    p3 = new_points[2];
    p4 = new_points[3];
}
