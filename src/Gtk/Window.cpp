#include "Window.h"

Window::Window()
        : box(Gtk::Orientation::HORIZONTAL) {
    set_title("Test app");
    set_default_size(1280, 720);
    set_resizable(false);

    box.append(drawing_area);
    box.append(control_frame);
    set_child(box);

    //control_frame.set_margin(10);
    control_frame.set_label("Control frame");
    control_frame.set_size_request(380, 720);
    //control_frame.
    //control_frame.set_label_align(Gtk::Align::END);
    //set_child(drawing_area);
}
