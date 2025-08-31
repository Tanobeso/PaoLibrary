#include "../headers/LibraryModel.h"
#include <QCoreApplication>
#include <QIcon>
#include <QDebug>

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
        QString Path = QCoreApplication::applicationDirPath()
        + "/" + QString::fromStdString(item->getImage());

        return QIcon(Path);
    }

    /*case TypeRole:
        ...
    */
    default:
        return QVariant();
    }
}



