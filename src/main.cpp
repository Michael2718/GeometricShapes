#include <gtkmm-4.0/gtkmm/application.h>
#include <iostream>
#include "Window.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.example");
    //g_application_new(nullptr, G_APPLICATION_FLAGS_NONE);
    return app->make_window_and_run<Window>(argc, argv);
}
