#ifndef GEOMETRICSHAPES_QUADRANGLE_H
#define GEOMETRICSHAPES_QUADRANGLE_H

#include "../Shape.h"
#include <vector>

using std::vector;

class Quadrangle : public Shape {
private:
    Point p1, p2, p3, p4;
public:
    Quadrangle();
    Quadrangle(unsigned int id, double x, double y, double rotation_angle,
               Point p1, Point p2, Point p3, Point p4);

    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};


#endif //GEOMETRICSHAPES_QUADRANGLE_H
