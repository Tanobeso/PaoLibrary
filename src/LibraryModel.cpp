#include "../headers/LibraryModel.h"
#include <QCoreApplication>
#include <QIcon>
#include <QDebug>
#include "../headers/Art.h"
#include "../headers/Book.h"
#include "../headers/Movie.h"
#include "../headers/Series.h"
#include "../headers/Videogame.h"
#include<QPainter>


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

bool LibraryModel::removeRow(int row, const QModelIndex& parent) {
    if (parent.isValid())
        return false;
    if (row < 0 || row >= lib.size())
        return false;
    beginRemoveRows(parent, row, row);
    lib.removeAt(row);
    endRemoveRows();
    return true;
}

bool LibraryModel::addRow(std::shared_ptr<AbstractItem> item) {
    int row = lib.size();
    beginInsertRows(QModelIndex(), row, row);
    lib.append(item);
    endInsertRows();
    return true;
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
        QString path = QString::fromStdString(item->getImage());
        QPixmap pixmap;
        if (path.isEmpty() || !pixmap.load(path)){
            pixmap.load("resources/default.jpg");
        }
        // Vari fix per sitemare le dimensioni immagini
        QSize iconSize(120, 160);
        QPixmap scaled = pixmap.scaled(iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QPixmap fixed(iconSize);
        fixed.fill(Qt::transparent);
        QPainter painter(&fixed);
        QPoint center(
            (iconSize.width() - scaled.width()) / 2,
            (iconSize.height() - scaled.height()) / 2);
        painter.drawPixmap(center, scaled);
        painter.end();

        return QIcon(fixed);
    }

    // Filtro per tipo tramite cast per evitare getType come richiesto

    case TypeRole:
        if (dynamic_cast<Art*>(const_cast<AbstractItem*>(item.get())))
            return "Art";
        else if (dynamic_cast<Book*>(const_cast<AbstractItem*>(item.get())))
            return "Book";
        else if (dynamic_cast<Movie*>(const_cast<AbstractItem*>(item.get())))
            return "Movie";
        else if (dynamic_cast<Series*>(const_cast<AbstractItem*>(item.get())))
            return "Series";
        else if (dynamic_cast<Videogame*>(const_cast<AbstractItem*>(item.get())))
            return "Videogame";
        else return QVariant();

    case ReturnVariantRole:
        return QVariant::fromValue(item.get());

    default:
        return QVariant();
    }
}




