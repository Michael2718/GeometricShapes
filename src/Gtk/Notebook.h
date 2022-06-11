#ifndef GEOMETRICSHAPES_NOTEBOOK_H
#define GEOMETRICSHAPES_NOTEBOOK_H

#include <gtkmm-4.0/gtkmm/notebook.h>
#include <gtkmm-4.0/gtkmm/combobox.h>
//#include <gtkmm-4.0/gtkmm/te>
#include <gtkmm-4.0/gtkmm/button.h>
#include <gtkmm-4.0/gtkmm/box.h>

class Notebook : public Gtk::Notebook {
public:
    Notebook();
    ~Notebook() override = default;
protected:
    Gtk::ComboBox combo_box;
    Gtk::Button button;
    Gtk::Box simple_polygon, rectangle, rhombus, trapezoid, triangle, ellipse, circle, complex_shape;
};


#endif //GEOMETRICSHAPES_NOTEBOOK_H
