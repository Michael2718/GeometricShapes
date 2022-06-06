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
