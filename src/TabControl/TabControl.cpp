#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->tabControl1.set_size_request(370, 250);
    fixed.add(this->tabControl1);
    fixed.child_property_x(this->tabControl1) = 10;
    fixed.child_property_y(this->tabControl1) = 10;

    this->tabControl1.insert_page(this->tabPage1, "tabPage1", 0);
    this->tabControl1.insert_page(this->tabPage2, "tabPage2", 1);
    this->tabControl1.insert_page(this->tabPage3, "tabPage3", 2);

    this->set_title("TabControl example");
    this->set_size_request(390, 270);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Notebook tabControl1;
  Frame tabPage1;
  Frame tabPage2;
  Frame tabPage3;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
