#include <gtkmm-4.0/gtkmm/application.h>
#include <iostream>
#include "Window.h"
#include "Circle.h"
#include "SimplePolygon.h"
#include <vector>
#include "Point.h"

int main(int argc, char* argv[]) {

    //Circle c(1, {0, 0}, 2);
    std::vector<Point> points = {{2,  2},
                            {6,  1},
                            {7,  2},
                            {5,  -2},
                            {1,  -2},
                            {4, 1},
                            {1, 1},
                            {-2, -1},
                            {-2, 2}};
    SimplePolygon sp(points);
    std::cout << "Polygon area: " << sp.Area();
    auto app = Gtk::Application::create("org.gtkmm.example");
    //g_application_new(nullptr, G_APPLICATION_FLAGS_NONE);
    return app->make_window_and_run<Window>(argc, argv);
}
