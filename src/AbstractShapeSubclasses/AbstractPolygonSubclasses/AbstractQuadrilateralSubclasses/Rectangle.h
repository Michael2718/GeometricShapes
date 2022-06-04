#ifndef GEOMETRICSHAPES_RECTANGLE_H
#define GEOMETRICSHAPES_RECTANGLE_H

#include "../AbstractQuadrilateral.h"
#include "../../../Point.h"

class Rectangle : public AbstractQuadrilateral {
private:
    Point top_left_corner;
    double width, height;
public:
    Rectangle(unsigned int id, Point top_left_corner, int width, int height);

    double GetWidth() const {return width;}
    double GetHeight() const {return height;}

    void SetWidth(double new_width);
    void SetHeight(double new_height);

    double Perimeter() const override;
    double Area() const override;
};

#endif //GEOMETRICSHAPES_RECTANGLE_H
