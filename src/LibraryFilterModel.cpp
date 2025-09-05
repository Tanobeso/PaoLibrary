#include "../headers/LibraryFilterModel.h"
#include "../headers/LibraryModel.h"

LibrarySearchFilterModel::LibrarySearchFilterModel(QObject *parent): QSortFilterProxyModel(parent) {}

void LibrarySearchFilterModel::setTitleFilter(const QString& s){
    titleFilter=s;
    invalidateFilter();
}

bool LibrarySearchFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    QString title = sourceModel()->data(index, LibraryModel::TitleRole).toString();

    // filtro titolo (case insensitive)
    if (!titleFilter.isEmpty() &&
        !title.contains(titleFilter, Qt::CaseInsensitive)) {
        return false;
    }

    return true;
}

LibraryTypeFilterModel::LibraryTypeFilterModel(QObject *parent): QSortFilterProxyModel(parent) {}

void LibraryTypeFilterModel::setTypeFilter(const QString& s){
    typeFilter=s;
    invalidateFilter();
}

bool LibraryTypeFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    QString type = sourceModel()->data(index, LibraryModel::TypeRole).toString();

    // filtro tipo
    if (typeFilter.isEmpty())
        return true;
    else{
        return type.contains(typeFilter);

    }

}
