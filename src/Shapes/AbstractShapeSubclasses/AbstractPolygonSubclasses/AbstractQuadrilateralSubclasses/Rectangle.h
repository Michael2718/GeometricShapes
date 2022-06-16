#ifndef GEOMETRICSHAPES_RECTANGLE_H
#define GEOMETRICSHAPES_RECTANGLE_H

#include "AbstractQuadrilateral.h"
#include "Point.h"
#include <string>

class Rectangle : public AbstractQuadrilateral {
private:
    double width, height;
public:
    Rectangle(Point center, double width, double height);
    Rectangle(Point p1, Point p2, Point p3, Point p4);

    double GetWidth() const {return width;}
    double GetHeight() const {return height;}
    std::vector<AbstractShape* > GetShapes() const override {return {};}

    void Scale(double k) override;

    double Perimeter() const override;
    double Area() const override;

    std::string Info() const override;
};

#endif //GEOMETRICSHAPES_RECTANGLE_H
