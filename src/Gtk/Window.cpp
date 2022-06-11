#include "Window.h"

Window::Window()
        : box(Gtk::Orientation::HORIZONTAL) {
    set_title("Geometric Shapes");
    set_default_size(1366, 768);
    set_resizable(false);

    box.append(drawing_area);
    box.append(notebook);
    set_child(box);
}
