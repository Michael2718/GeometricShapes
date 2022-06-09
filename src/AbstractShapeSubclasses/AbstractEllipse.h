#ifndef GEOMETRICSHAPES_ABSTRACTELLIPSE_H
#define GEOMETRICSHAPES_ABSTRACTELLIPSE_H

#include "../AbstractShape.h"
#include "../Point.h"

class AbstractEllipse : public AbstractShape {
private:
    Point center;
    double rotation_angle;
public:
    AbstractEllipse(unsigned int id, Point center);

    Point GetCenter() const {return center;}
    double GetRotationAngle() const {return rotation_angle;}

    void Rotate(double angle) override;
    void Translate(double x, double y) override;
};


#endif //GEOMETRICSHAPES_ABSTRACTELLIPSE_H
