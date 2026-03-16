#ifndef ITEMEDITVISITOR_H
#define ITEMEDITVISITOR_H
#include "ItemVisitor.h"
#include <QWidget>

class ItemEditVisitor : public ItemVisitor{
private:
    QList<QString> modifiche;
public:
    ItemEditVisitor(QList<QString>&);
    virtual void visitArt(Art& art);
    virtual void visitBook(Book& book);
    virtual void visitMovie(Movie& movie);
    virtual void visitSeries(Series& series);
    virtual void visitVideogame(Videogame& videogame);
};

#endif // ITEMEDITVISITOR_H
