#include "DrawingArea.h"
#include <cmath>

DrawingArea::DrawingArea() {
    set_draw_func(sigc::mem_fun(*this, &DrawingArea::on_draw));
    set_content_width(900);
    set_content_height(768);
    set_size_request(900, 768);
}

void DrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height) {
    double center_x = width/2.0;
    double center_y = height/2.0;

    // Background
    cr->set_source_rgb(1, 1, 1);
    cr->rectangle(0,0, width, height);
    cr->fill();

    cr->set_source_rgb(0, 0, 0.8);
    cr->rectangle(center_x,center_y, 200, 200);
    cr->fill();

/*    // Axis
    cr->set_source_rgb(0, 0, 0);
    cr->set_line_width(1);
    cr->move_to(x_center,0);
    cr->line_to(x_center, height);
    cr->move_to(0,y_center);
    cr->line_to(width, y_center);
    cr->stroke();*/
}
