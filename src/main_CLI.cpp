#include <iostream>
//#include "Shape.h"
#include "ShapeSubclasses/Rectangle.h"
using std::cout, std::cin;

int main() {
    Rectangle a(2, 4, 6);

    cout << a.GetA();
    return 0;
}