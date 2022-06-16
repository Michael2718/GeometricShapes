#ifndef GEOMETRICSHAPES_ELLIPSE_H
#define GEOMETRICSHAPES_ELLIPSE_H

#include "AbstractEllipse.h"
#include <string>

class Ellipse : public AbstractEllipse {
private:
    double a, b; // a - Semi-major axis; b - Semi-minor axis
public:
    Ellipse(Point center, double a, double b);

    double GetA() const {return a;}
    double GetB() const {return b;}
    std::vector<AbstractShape* > GetShapes() const override {return {};}

    void Scale(double k) override;

    double Perimeter() const override;
    double Area() const override;

    std::string Info() const override;
};

#endif //GEOMETRICSHAPES_ELLIPSE_H
