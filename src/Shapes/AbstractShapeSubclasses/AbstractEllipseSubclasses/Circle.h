#ifndef GEOMETRICSHAPES_CIRCLE_H
#define GEOMETRICSHAPES_CIRCLE_H

#include "../AbstractEllipse.h"

class Circle : public AbstractEllipse {
private:
    double r;
public:
    Circle(Point center, double r);

    double GetRadius() const {return r;}

    void Scale(double k) override;

    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_CIRCLE_H
