#include "../headers/LibraryFilterModel.h"
#include "../headers/Library.h"

LibraryFilterModel::LibraryFilterModel(QObject *parent): QSortFilterProxyModel(parent) {}

void LibraryFilterModel::setTitleFilter(const QString& s){
    titleFilter=s;
    invalidateFilter();
}

bool LibraryFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    QString title = sourceModel()->data(index, Library::TitleRole).toString();

    // filtro titolo (case insensitive)
    if (!titleFilter.isEmpty() &&
        !title.contains(titleFilter, Qt::CaseInsensitive)) {
        return false;
    }

    // filtro tipi da fare

    return true;
}
