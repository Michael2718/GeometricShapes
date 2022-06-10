#ifndef GEOMETRICSHAPES_ELLIPSE_H
#define GEOMETRICSHAPES_ELLIPSE_H

#include "../AbstractEllipse.h"

class Ellipse : public AbstractEllipse {
private:
    double a, b; // a - Semi-major axis; b - Semi-minor axis
public:
    Ellipse(unsigned int id, Point center, double a, double b);

    double GetA() const {return a;}
    double GetB() const {return b;}

    void Scale(double k) override;

    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_ELLIPSE_H