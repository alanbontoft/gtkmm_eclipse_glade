#include "mainwindow.h"
#include <iostream>

using namespace std;


MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), _builder(refGlade)
{

	// get widgets from glade names
    _builder->get_widget("btnInc", _btnInc);
    _builder->get_widget("btnDec", _btnDec);
    _builder->get_widget("btnStart", _btnStart);
    _builder->get_widget("btnToggle", _btnToggle);
    _builder->get_widget("lblMessage",_lblMessage);

    // connect signals
    _btnInc->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_inc_click));
    _btnDec->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_dec_click));
    _btnStart->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_start_click));
    _btnToggle->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_btn_toggle_click));

}

/*
    Handler for increase button click
*/
void MainWindow::on_btn_inc_click()
{
    _total++;

    show_message();
}

/*
    Handler for decrease button click
*/
void MainWindow::on_btn_dec_click()
{
    if (_total > 0)
    {
        _total--;
        show_message();
    }
}

/*
    Handler for reset button click
*/
void MainWindow::on_btn_start_click()
{

	if (_total != 0)
    {
        _total = 0;
        show_message();
    }

    StartThread();
}

void MainWindow::on_btn_toggle_click()
{
    cout << "Toggle State: " << _btnToggle->get_active() << endl;
}

/*
    Update label with message
*/
void MainWindow::show_message()
{
    _msg = Glib::ustring::sprintf("Total =  %d", _total);

    cout << _msg << endl;

    _lblMessage->set_text(_msg);
}

void* thread_function(void *param)
{
	int id = *(int*)param;
	int count = 0;

	while(count < 10)
	{
		cout << "Thread " << id << " = " << count++ << endl;
		if (count != 10) sleep(id);
	}

	cout << Glib::ustring::sprintf("Thread %d complete", id) << endl;

	return nullptr;
}

void MainWindow::StartThread()
{
	_threadCounter++;
	Glib::ustring s = Glib::ustring::sprintf("Thread %d", _threadCounter);
	_thread = g_thread_new(s.c_str(), thread_function, &_threadCounter);
}
