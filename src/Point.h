#ifndef GEOMETRICSHAPES_POINT_H
#define GEOMETRICSHAPES_POINT_H


class Point {
private:
    double x, y;
public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    double GetX() const {return x;}
    double GetY() const {return y;}
};


#endif //GEOMETRICSHAPES_POINT_H
