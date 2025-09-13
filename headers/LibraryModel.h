#ifndef LIBRARYMODEL_H
#define LIBRARYMODEL_H

#include "Library.h"
#include <QAbstractListModel>

class LibraryModel : public QAbstractListModel, public Library  {
    Q_OBJECT
public:
    enum Roles {                    //ruoli personalizzati
        ImageRole = Qt::UserRole,
        TitleRole = Qt::UserRole+1,
        TypeRole = Qt::UserRole+2,
        ReturnVariantRole = Qt::UserRole+3
    };

    explicit LibraryModel(QObject* parent = nullptr);

    void loadLib(const QList<std::shared_ptr<AbstractItem>>&) override;
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex&,int) const override;
    bool removeRow(int row, const QModelIndex& parent = QModelIndex());

};
#endif
