#ifndef LIBRARYFILTERMODEL_H
#define LIBRARYFILTERMODEL_H
#include <QSortFilterProxyModel>

class LibraryFilterModel : public QSortFilterProxyModel {
    Q_OBJECT
private:
    QString titleFilter;

public:
    explicit LibraryFilterModel(QObject* =nullptr);

    void setTitleFilter(const QString&);
    //filtro tipi

protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;

};

#endif // LIBRARYFILTERMODEL_H
