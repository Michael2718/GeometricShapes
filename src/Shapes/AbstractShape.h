#ifndef GEOMETRICSHAPES_ABSTRACTSHAPE_H
#define GEOMETRICSHAPES_ABSTRACTSHAPE_H

#include <string>
#include "Point.h"

enum ShapeId {
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
    ShapeId id;
public:
    explicit AbstractShape(ShapeId id);
    virtual ~AbstractShape() = default;

    ShapeId GetId() const {return id;}
    std::string GetStringId() const;
    virtual Point GetCenter() const = 0;

    virtual void Scale(double k) = 0;
    virtual void Rotate(double angle) = 0;
    virtual void Rotate(Point r_center, double angle) = 0;
    virtual void Translate(double dx, double dy) = 0;

    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;

    virtual std::string Info() const = 0;
};

#endif //GEOMETRICSHAPES_ABSTRACTSHAPE_H
