#ifndef GEOMETRICSHAPES_TRAPEZOID_H
#define GEOMETRICSHAPES_TRAPEZOID_H

#include "../AbstractQuadrilateral.h"
#include "../../../Point.h"

class Trapezoid : public AbstractQuadrilateral {
private:
    Point center; // Center is located at the middle of midline.
    double a, b, c, d, h; // 'a' is top side parallel to bottom 'b' side.
public:
    Trapezoid(unsigned int id, Point p1, Point p2, Point p3, Point p4);

    double GetA() const {return a;}
    double GetB() const {return b;}
    double GetC() const {return c;}
    double GetD() const {return d;}
    double GetHeight() const {return h;}
    Point GetCenter() const {return center;}

    void Scale(double k) override;
    void Rotate(double angle) override;

    // TODO : Implement Perimeter() method
    double Perimeter() const override;
    double Area() const override;
};


#endif //GEOMETRICSHAPES_TRAPEZOID_H
