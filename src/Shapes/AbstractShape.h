#ifndef GEOMETRICSHAPES_ABSTRACTSHAPE_H
#define GEOMETRICSHAPES_ABSTRACTSHAPE_H

#include "Point.h"

enum ShapeID {
    SIMPLE_POLYGON,
    RECTANGLE,
    RHOMBUS,
    TRAPEZOID,
    TRIANGLE,
    ELLIPSE,
    CIRCLE,
    COMPLEX_SHAPE
};

class AbstractShape {
private:
    ShapeID id;
public:
    explicit AbstractShape(ShapeID id);
    virtual ~AbstractShape() = default;

    unsigned int GetId() const {return id;}
    virtual Point GetCenter() const = 0;

    virtual void Scale(double k) = 0;
    virtual void Rotate(double angle) = 0;
    virtual void Rotate(Point r_center, double angle) = 0;
    virtual void Translate(double dx, double dy) = 0;

    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

#endif //GEOMETRICSHAPES_ABSTRACTSHAPE_H
