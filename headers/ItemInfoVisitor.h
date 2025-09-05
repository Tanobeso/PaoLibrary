#ifndef ITEMINFOVISITOR_H
#define ITEMINFOVISITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "../headers/ItemVisitor.h"

class ItemInfoVisitor: public ItemVisitor{
private:
    QWidget* infoWidget;
    QVBoxLayout* infoLayout;
public:
    QWidget* getWidget();
    virtual void visitArt(Art&);
    virtual void visitBook(Book&);
    virtual void visitMovie(Movie&);
    virtual void visitSeries(Series&);
    virtual void visitVideogame(Videogame&);
    void infoSetup(AbstractItem&);
};
#endif // ITEMINFOVISITOR_H
