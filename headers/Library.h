#ifndef LIBRARY_H
#define LIBRARY_H

#include "AbstractItem.h"
#include <QList>
#include <QAbstractListModel>

class Library : public QAbstractListModel {
    Q_OBJECT
private:
    QList<std::shared_ptr<AbstractItem>> lib;
public:
    enum Roles {                    //ruoli personalizzati
        ImageRole = Qt::UserRole,
        TitleRole = Qt::UserRole+1
    //qualcosa per tipi oggetto
    };

    explicit Library(QObject* parent = nullptr);

    void loadLib(const QList<std::shared_ptr<AbstractItem>>&);
    std::shared_ptr<AbstractItem> getItem(int) const;
    void addItem(std::shared_ptr<AbstractItem>);
    void saveAsJson(const QString&) const;
    void saveAsXml(const QString&) const;

    int rowCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex&,int) const override;

};
#endif
