#ifndef LIBRARYFILTERMODEL_H
#define LIBRARYFILTERMODEL_H
#include <QSortFilterProxyModel>

class LibrarySearchFilterModel : public QSortFilterProxyModel {
    Q_OBJECT
private:
    QString titleFilter;

public:
    explicit LibrarySearchFilterModel(QObject* =nullptr);

    void setTitleFilter(const QString&);
    //filtro tipi

protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;

};

class LibraryTypeFilterModel : public QSortFilterProxyModel {
    Q_OBJECT
private:
    QString typeFilter;

public:
    explicit LibraryTypeFilterModel(QObject* =nullptr);

    void setTypeFilter(const QString&);

protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;

};

#endif // LIBRARYFILTERMODEL_H
