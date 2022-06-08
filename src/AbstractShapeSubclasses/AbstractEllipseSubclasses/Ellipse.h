#ifndef GEOMETRICSHAPES_ELLIPSE_H
#define GEOMETRICSHAPES_ELLIPSE_H

#include "../AbstractEllipse.h"

class Ellipse : public AbstractEllipse {
private:
    double a, b, rotation_angle; // a - Semi-major axis; b - Semi-minor axis
public:
    Ellipse(unsigned int id, Point center, double a, double b);

    double GetA() const {return a;}
    double GetB() const {return b;}
    double GetRotationAngle() const {return rotation_angle;}

    void Scale(double k) override;
    void Rotate(double angle) override;

    // TODO: Implement Move method
    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_ELLIPSE_H
