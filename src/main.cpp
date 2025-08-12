#include "..\headers\mainwindow.h"
#include "..\headers\library.h"
#include <QApplication>
#include "..\headers\Book.h"
#include "..\headers\Art.h"

int main(int argc, char *argv[])
{
    Library lib;
    auto libro = std::make_shared<Book>("pippo", "a", 1, "autore", "size", "publisher", "genre", "edition");
    auto art = std::make_shared<Art>("pippo", "a", 1, "autore", "size", "style");
    lib.addItem(libro);
    lib.addItem(art);
    lib.saveAsJson("test");
    QApplication a(argc, argv);
    std::string stringa("Pippo");
    MainWindow mainwindow;
    mainwindow.resize(1024,512);
    mainwindow.show();
    return a.exec();

}
