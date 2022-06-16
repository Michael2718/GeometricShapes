#include <vector>

#include "MainMenu.h"
#include "AbstractShape.h"

using std::vector;

int main(int argc, char *argv[]) {
    vector<AbstractShape *> shape_list;

    MainMenu(argc, argv, shape_list);

    for (auto shape: shape_list) delete shape;

    return 0;
}