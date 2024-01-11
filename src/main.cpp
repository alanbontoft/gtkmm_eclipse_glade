#include <gtkmm.h>
#include "mainwindow.h"
#include <iostream>

int main (int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv);

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();

    try
	{
    	builder->add_from_file("gui.glade"); //note: glade file needs to be in app working directory
	}
	catch(const Glib::FileError& ex)
	{
		std::cout << "FileError: " << ex.what() << std::endl;
		return 1;
	}

	// Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("gui.glade");

	MainWindow *win = 0;
	builder->get_widget_derived("mainWindow", win);

    return app->run(*win);
}
