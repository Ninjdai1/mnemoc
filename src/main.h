#ifndef MAIN_H
#define MAIN_H

#include "data.h"
#include "database.h"
#include <gtkmm/dropdown.h>
#include <gtkmm/popovermenu.h>
#include <gtkmm/separator.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <vector>

class MnemocMain : public Gtk::Window
{
    public:
        MnemocMain();

    protected:
        Database *db;
        std::vector<Box> boxes;

        void load_boxes_from_db();

        //Signal handlers:
        void on_button_quit();
        void on_exit();

        //Member widgets:
        Gtk::Box m_VBox_Top;
        Gtk::PopoverMenu m_Popover_Menu;

        Gtk::DropDown m_Boxes_DropDown;

        Gtk::Separator m_Separator;
        Gtk::Button m_Button_Quit;
};

#endif // MAIN_H
