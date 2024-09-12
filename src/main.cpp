#include "main.h"
#include "sigc++/functors/mem_fun.h"
#include <gtkmm.h>

void MnemocMain::on_button_quit(){
    set_visible(false);
}

void MnemocMain::on_exit() {
    this->db->graceful_exit();
}

void MnemocMain::load_boxes_from_db() {
    
}

MnemocMain::MnemocMain()
    : m_Button_Quit("Quit"),
    m_VBox_Top(Gtk::Orientation::VERTICAL, 0)
{
    if(!this->db->init()) return;

    this->signal_hide().connect(sigc::mem_fun(*this, &MnemocMain::on_exit));

    this->set_title("Mnemoc");
    this->set_default_size(200, 200);
    this->set_child(m_VBox_Top);

    m_Boxes_DropDown.set_margin(10);

    m_VBox_Top.append(m_Boxes_DropDown);

    m_VBox_Top.append(m_Separator);

    m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,
                &MnemocMain::on_button_quit));
    m_Button_Quit.set_margin(10);
    m_VBox_Top.append(m_Button_Quit);

}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("dev.ninjdai.mnemoc");

    return app->make_window_and_run<MnemocMain>(argc, argv);
}
