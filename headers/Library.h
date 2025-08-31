#ifndef LIBRARY_H
#define LIBRARY_H

#include "AbstractItem.h"
#include <QList>

class Library{
protected:
    QList<std::shared_ptr<AbstractItem>> lib;

public:
    virtual void loadLib(const QList<std::shared_ptr<AbstractItem>>&);
    std::shared_ptr<AbstractItem> getItem(int) const;
    void addItem(std::shared_ptr<AbstractItem>);
    void saveAsJson(const QString&) const;
    void saveAsXml(const QString&) const;
    //size?
};

#endif // LIBRARY_H
