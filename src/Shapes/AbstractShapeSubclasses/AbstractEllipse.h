#ifndef GEOMETRICSHAPES_ABSTRACTELLIPSE_H
#define GEOMETRICSHAPES_ABSTRACTELLIPSE_H

#include "AbstractShape.h"
#include "Point.h"
#include <string>

class AbstractEllipse : public AbstractShape {
private:
    Point center;
    double rotation_angle;
public:
    AbstractEllipse(ShapeId id, Point center);

    Point GetCenter() const override {return center;}
    double GetRotationAngle() const {return rotation_angle;}

    void Rotate(double angle) override;
    void Rotate(Point r_center, double angle) override;
    void Translate(double dx, double dy) override;

    std::string Info() const override;
};


#endif //GEOMETRICSHAPES_ABSTRACTELLIPSE_H
