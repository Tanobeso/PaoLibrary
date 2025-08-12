#include "..\headers\library.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>


void Library::addItem(std::shared_ptr<AbstractItem> item){
    lib.append(item);
}

void Library::saveAsJson(const QString& nome){
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
