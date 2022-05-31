#include <iostream>
#include <vector>
#include "Point.h"

#include "AbstractShapeSubclasses/AbstractPolygonSubclasses/Polygon.h"

using std::cout, std::cin, std::vector;

/*src/AbstractShape.h
        src/AbstractShapeSubclasses/AbstractPolygon.h
        src/AbstractShapeSubclasses/AbstractPolygon.cpp*/
int main() {
    vector<Point> points(Point(1,2), Point(0,2), Point(0, 0));
    Polygon p(1, points);
    //cout << c.getRadius();
    return 0;
}
src/AbstractShape.cpp
