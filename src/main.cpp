#include "../headers/MainWindow.h"
#include "../headers/Library.h"
#include <QApplication>
#include "../headers/JsonManager.h"

int main(int argc, char *argv[])
{
    Library lib;
    /*auto libro = std::make_shared<Book>("Il Signore Degli Spinelli", "a", 1, "autore", "size", "publisher", "genre", "edition");
    auto art = std::make_shared<Art>("Pittrice", "a", 1, "autore", "size", "style");
    auto movie = std::make_shared<Movie>("Dune", "a", 1, "publisher", "genre", "cast", "director", 1);
    auto series = std::make_shared<Series>("Piggly Winks", "a", 1, "publisher", "genre", "cast", "director", 1, 2);
    auto videogame = std::make_shared<Videogame>("Clair Obscur", "a", 1, "publisher", "genre", "developer");

    lib.addItem(libro);
    lib.addItem(art);
    lib.addItem(movie);
    lib.addItem(series);
    lib.addItem(videogame);
    lib.saveAsJson("test.json");*/
    lib=loadJson("test.json");
    lib.saveAsXml("test.xml");
    QApplication a(argc, argv);
    std::string stringa("Pippo");
    MainWindow mainwindow;
    mainwindow.resize(1024,512);
    mainwindow.show();
    return a.exec();

}
