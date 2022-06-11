#ifndef GEOMETRICSHAPES_DRAWINGAREA_H
#define GEOMETRICSHAPES_DRAWINGAREA_H

#include <gtkmm-4.0/gtkmm/drawingarea.h>

class DrawingArea : public Gtk::DrawingArea {
public:
    DrawingArea();
    ~DrawingArea() override = default;
protected:
    void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};

#endif //GEOMETRICSHAPES_DRAWINGAREA_H
