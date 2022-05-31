#ifndef GEOMETRICSHAPES_POINT_H
#define GEOMETRICSHAPES_POINT_H

#include <ostream>

class Point {
private:
    double x, y;
public:
    Point();
    Point(double x, double y);

    double GetX() const;
    double GetY() const;
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

#endif //GEOMETRICSHAPES_POINT_H
