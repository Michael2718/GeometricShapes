#ifndef GEOMETRICSHAPES_RECTANGLE_H
#define GEOMETRICSHAPES_RECTANGLE_H

#include "../AbstractQuadrilateral.h"
#include "../../../Point.h"

class Rectangle : public AbstractQuadrilateral {
private:
    Point center;
    double width, height;
public:
    Rectangle(unsigned int id, Point center, double width, double height);
    Rectangle(unsigned int id, Point p1, Point p2, Point p3, Point p4);

    double GetWidth() const {return width;}
    double GetHeight() const {return height;}

    void Scale(double k) override;
    void Rotate(double angle) override;

    double Perimeter() const override;
    double Area() const override;
};

#endif //GEOMETRICSHAPES_RECTANGLE_H
