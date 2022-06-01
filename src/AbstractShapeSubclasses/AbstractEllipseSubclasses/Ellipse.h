#ifndef GEOMETRICSHAPES_ELLIPSE_H
#define GEOMETRICSHAPES_ELLIPSE_H

#include "../AbstractEllipse.h"

class Ellipse : public AbstractEllipse {
private:
    double a, b;
public:
    Ellipse(unsigned int id, Point center, double a, double b);

    double GetA() const {return a;}
    double GetB() const {return b;}

    void SetA(double new_a);
    void SetB(double new_b);
    // TODO: Implement Move method
    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_ELLIPSE_H
