#ifndef GEOMETRICSHAPES_RECTANGLE_H
#define GEOMETRICSHAPES_RECTANGLE_H

#include "../AbstractQuadrilateral.h"
#include "../../../Point.h"

class Rectangle : public AbstractQuadrilateral {
private:
    Point top_left_corner;
    double a, b;
public:
    Rectangle(unsigned int id, Point top_left_corner, int a, int b);

    double GetA() const {return a;}
    double GetB() const {return b;}

    void SetA(double new_a);
    void SetB(double new_b);

    double Perimeter() const override;
    double Area() const override;
};

#endif //GEOMETRICSHAPES_RECTANGLE_H
