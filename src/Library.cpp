#include "../headers/Library.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDomDocument>
#include <QCoreApplication>
#include <QIcon>

Library::Library(QObject* parent) : QAbstractListModel(parent){};

void Library::loadLib(const QList<std::shared_ptr<AbstractItem>>& lista){
    beginResetModel();
    lib=lista;
    endResetModel();
}

std::shared_ptr<AbstractItem> Library::getItem(int i) const{
    if (i>0 && i<lib.size()) return lib[i];
    else return nullptr;
}

int Library::rowCount(const QModelIndex& parent) const{
    if (parent.isValid()) return 0;
    return lib.size();
}

QVariant Library::data(const QModelIndex& index, int role) const{
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
        return QIcon(Path);  // QIcon si integra bene con QListView
    }

    /*case TypeRole:
        ...
    */
    default:
        return QVariant();
    }
}

void Library::addItem(std::shared_ptr<AbstractItem> item){
    lib.append(item);
}


void Library::saveAsJson(const QString& nome) const{
    QJsonArray jsonArray;
    for (const auto& item : lib){
        jsonArray.append(item->toJson());
    }

    QJsonDocument doc(jsonArray);
    QFile file(nome);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}

void Library::saveAsXml(const QString& nome) const{
    QDomDocument doc("MediaLibrary");
    QDomElement root = doc.createElement("Library");
    doc.appendChild(root);

    for (const auto &item : lib) {
        root.appendChild(item->toXml(doc));
    }

    QFile file(nome);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Errore apertura file in scrittura";
        return;
    }

    QTextStream out(&file);
    doc.save(out, 4); // 4 = indentazione
    file.close();
}


