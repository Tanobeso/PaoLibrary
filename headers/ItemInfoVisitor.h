#ifndef ITEMINFOVISITOR_H
#define ITEMINFOVISITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "../headers/ItemVisitor.h"

class ItemInfoVisitor: public QObject, public ItemVisitor{
    Q_OBJECT
private:
    QWidget* infoWidget;
    QVBoxLayout* layout;
    QHBoxLayout* itemLayout;
    QVBoxLayout* infoLayout;
    QPixmap imagePixmap;
public:
    explicit ItemInfoVisitor(QObject* = nullptr);
    ~ItemInfoVisitor();
    QWidget* getWidget() const;
    virtual void visitArt(Art&);
    virtual void visitBook(Book&);
    virtual void visitMovie(Movie&);
    virtual void visitSeries(Series&);
    virtual void visitVideogame(Videogame&);
    void infoSetup(AbstractItem&);
    void buttonSetup(AbstractItem&);
private slots:
    void onBackHome();
signals:
    void home();
};
#endif // ITEMINFOVISITOR_H
