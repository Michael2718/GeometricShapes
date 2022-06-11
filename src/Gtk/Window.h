#ifndef GEOMETRICSHAPES_WINDOW_H
#define GEOMETRICSHAPES_WINDOW_H

#include <gtkmm-4.0/gtkmm/application.h>
#include <gtkmm-4.0/gtkmm/window.h>
#include <gtkmm-4.0/gtkmm/frame.h>
#include <gtkmm-4.0/gtkmm/box.h>
#include "DrawingArea.h"
#include "Notebook.h"

class Window : public Gtk::Window {
public:
    Window();
    ~Window() override = default;
protected:
    DrawingArea drawing_area;
    Notebook notebook;
    Gtk::Box box;
};


#endif //GEOMETRICSHAPES_WINDOW_H
