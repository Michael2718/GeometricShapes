#include "DrawingArea.h"
#include <cmath>

DrawingArea::DrawingArea() {
    set_draw_func(sigc::mem_fun(*this, &DrawingArea::on_draw));
    set_content_width(900);
    set_content_height(720);
}

void DrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height) {
    double x_center = width/2.0;
    double y_center = height/2.0;

    cr->set_source_rgb(1, 1, 1);
    cr->rectangle(0,0, width, height);
    cr->fill();
    cr->set_source_rgb(0, 0, 0.8);
    cr->rectangle(x_center-100, y_center-100, 200, 200);
    cr->fill();

/*    cr->set_line_width(5);

    cr->set_source_rgb(1, 0.0, 0.0);

    cr->move_to(0,0);
    cr->line_to(width, height);
    cr->stroke();*/
}
