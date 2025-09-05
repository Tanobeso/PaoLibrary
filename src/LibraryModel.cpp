#include "../headers/LibraryModel.h"
#include <QCoreApplication>
#include <QIcon>
#include <QDebug>
#include "../headers/Art.h"
#include "../headers/Book.h"
#include "../headers/Movie.h"
#include "../headers/Series.h"
#include "../headers/Video.h"


LibraryModel::LibraryModel(QObject* parent) : QAbstractListModel(parent){};

void LibraryModel::loadLib(const QList<std::shared_ptr<AbstractItem>>& lista){
    beginResetModel();
    lib=lista;
    endResetModel();
}

int LibraryModel::rowCount(const QModelIndex& parent) const{
    if (parent.isValid()) return 0;
    return lib.size();
}

QVariant LibraryModel::data(const QModelIndex& index, int role) const{
    if (!index.isValid() || index.row() >= lib.size())
        return QVariant();

    const auto& item = lib.at(index.row());

    switch (role) {
    case Qt::DisplayRole:
    case TitleRole:
        return QString::fromStdString(item->getTitle());

    case Qt::DecorationRole:
    case ImageRole: {
        return QIcon(QString::fromStdString(item->getImage()));
    }

    // Filtro per tipo tramite cast per evitare getType come richiesto

    case TypeRole:
        if (dynamic_cast<Art*>(const_cast<AbstractItem*>(item.get())))
            return "Art";
        if (dynamic_cast<Book*>(const_cast<AbstractItem*>(item.get())))
            return "Book";
        if (dynamic_cast<Movie*>(const_cast<AbstractItem*>(item.get())))
            return "Movie";
        if (dynamic_cast<Series*>(const_cast<AbstractItem*>(item.get())))
            return "Series";
        if (dynamic_cast<Video*>(const_cast<AbstractItem*>(item.get())))
            return "Video";
    default:
        return QVariant();
    }
}




