#include "../headers/Library.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDomDocument>


void Library::addItem(std::shared_ptr<AbstractItem> item){
    lib.append(item);
}

Library& Library::operator=(const QList<std::shared_ptr<AbstractItem>>& newItems) {
    lib = newItems;
    return *this;
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


