#include "gtkmm.h"

class MainWindow : public Gtk::Window
{
public:    
    // MainWindow();

    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);

    void StartThread();

protected:
    void on_btn_inc_click();
    void on_btn_dec_click();
    void on_btn_start_click();
    void on_btn_toggle_click();
    void show_message();
    
    int _total = 0;
    Glib::ustring _msg;

    GThread *_thread;
    int _threadCounter = 0;

    //void initWindow();

    // buttons
    Gtk::Button *_btnInc;
    Gtk::Button *_btnDec;
    Gtk::Button *_btnStart;
    Gtk::ToggleButton *_btnToggle;

    Gtk::Label *_lblMessage;

    Gtk::Box *_box;
    Glib::RefPtr<Gtk::Builder> _builder;

};
