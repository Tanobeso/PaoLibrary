#include "..\headers\mainwindow.h"
#include "..\headers\test_widget.h"

MainWindow::MainWindow(std::string& stringa){
    Test_widget* widget = new Test_widget(stringa);
    widget->show();
    setCentralWidget (widget);
};
