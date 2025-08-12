#ifndef LIBRARY_H
#define LIBRARY_H

#include "AbstractItem.h"
#include <string>
#include <qlist>
using std::string;

class Library{
private:
    QList<std::shared_ptr<AbstractItem>> lib;
public:
    void addItem(std::shared_ptr<AbstractItem>);
    void removeItem();
    void saveAsJson(const QString&) const;
    void saveAsXml(const QString&) const;
};
#endif
