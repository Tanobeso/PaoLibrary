#ifndef ITEMINFOVISITOR_H
#define ITEMINFOVISITOR_H

#include "../headers/ItemVisitor.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class ItemInfoVisitor: public QObject, public ItemVisitor{
    Q_OBJECT
private:
    QWidget* infoWidget;
    QVBoxLayout* layout;
    QHBoxLayout* itemLayout;
    QVBoxLayout* infoLayout;
    QPixmap imagePixmap;
    QList<QWidget*> editList;
    QMap<QWidget*, QString> valoriOriginali;
    AbstractItem* editItem; //da passare a EditVisitor per salvare modifiche
    QLabel* imageLabel;
    QString currentImage;
    QPushButton* btnBrowse;
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
    void buttonSetup();
private slots:
    void onBackHome();
    void onEdit();
    void onCancel();
    void onSave();
    void onBrowse();
signals:
    void home();
    void deleteRequest();
};
#endif // ITEMINFOVISITOR_H
