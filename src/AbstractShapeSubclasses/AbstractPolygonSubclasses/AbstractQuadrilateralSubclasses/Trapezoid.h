#ifndef GEOMETRICSHAPES_TRAPEZOID_H
#define GEOMETRICSHAPES_TRAPEZOID_H

#include "../AbstractQuadrilateral.h"
#include "../../../Point.h"

class Trapezoid : public AbstractQuadrilateral {
private:
    Point center; // Center is located at the middle of midline.
    double a, b, height; // 'a' is top side parallel to bottom 'b' side.
public:
    Trapezoid(unsigned int id, Point center, double a, double b, double height);

    double GetA() const {return a;}
    double GetB() const {return b;}
    double GetHeight() const {return height;}

    void SetA(double new_a);
    void SetB(double new_b);
    void SetHeight(double new_height);
    // TODO : Implement Perimeter() method
    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_TRAPEZOID_H
