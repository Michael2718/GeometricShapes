#ifndef GEOMETRICSHAPES_SHAPE_H
#define GEOMETRICSHAPES_SHAPE_H

#include "Point.h"

class Shape {
private:

    unsigned int id;
    double x, y, rotation_angle; // (x, y) specifies the top-left point of the Rectangle circumscribed around Shape
public:
    Shape();
    Shape(unsigned int id, double x, double y, double rotation_angle);

    unsigned int getId() const {return id;}
    double getX() const {return x;}
    double getY() const {return y;}
    double getRotationAngle() const {return rotation_angle;}

    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

#endif //GEOMETRICSHAPES_SHAPE_H
