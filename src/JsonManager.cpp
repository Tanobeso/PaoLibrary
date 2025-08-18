#include "../headers/JsonManager.h"

//Caricamento da Json della libreria

QList<std::shared_ptr<AbstractItem>> loadJson(const QString &filePath) {
    QList<std::shared_ptr<AbstractItem>> lib;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Errore nell'apertura del file:" << file.errorString();
        return lib;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Errore di parsing JSON:" << parseError.errorString();
        return lib;
    }

    if (!doc.isArray()) {
        qWarning() << "Il file JSON non contiene un array";
        return lib;
    }

    QJsonArray array = doc.array();
    for (const QJsonValue &val : array) {
        if (val.isObject()) {
            QJsonObject obj=val.toObject();
            QString type = obj["type"].toString();

            if(type=="art"){
                lib.append(fromJsonArt(obj));
            }
            else if(type=="book"){
                lib.append(fromJsonBook(obj));
            }
            else if(type=="movie"){
                lib.append(fromJsonMovie(obj));
            }
            else if(type=="series"){
                lib.append(fromJsonSeries(obj));
            }
            else if(type=="videogame"){
                lib.append(fromJsonVideogame(obj));
            }
        }
    }

    return lib;
}

//Funzioni da json ad item

std::shared_ptr<Art> fromJsonArt(QJsonObject& obj){
    auto item=std::make_shared<Art>();
    item->setTitle(obj["title"].toString().toStdString());
    item->setDescription(obj["description"].toString().toStdString());
    item->setYear(obj["year"].toInt());
    item->setAuthor(obj["author"].toString().toStdString());
    item->setSize(obj["size"].toString().toStdString());
    item->setStyle(obj["style"].toString().toStdString());
    return item;
};
std::shared_ptr<Book> fromJsonBook(QJsonObject& obj){
    auto item=std::make_shared<Book>();
    item->setTitle(obj["title"].toString().toStdString());
    item->setDescription(obj["description"].toString().toStdString());
    item->setYear(obj["year"].toInt());
    item->setAuthor(obj["author"].toString().toStdString());
    item->setSize(obj["size"].toString().toStdString());
    item->setPublisher(obj["publisher"].toString().toStdString());
    item->setGenre(obj["genre"].toString().toStdString());
    item->setEdition(obj["edition"].toString().toStdString());
    return item;
};
std::shared_ptr<Movie> fromJsonMovie(QJsonObject& obj){
    auto item=std::make_shared<Movie>();
    item->setTitle(obj["title"].toString().toStdString());
    item->setDescription(obj["description"].toString().toStdString());
    item->setYear(obj["year"].toInt());
    item->setPublisher(obj["publisher"].toString().toStdString());
    item->setGenre(obj["genre"].toString().toStdString());
    item->setCast(obj["cast"].toString().toStdString());
    item->setDirector(obj["director"].toString().toStdString());
    item->setLength(obj["length"].toInt());
    return item;
};
std::shared_ptr<Series> fromJsonSeries(QJsonObject& obj){
    auto item=std::make_shared<Series>();
    item->setTitle(obj["title"].toString().toStdString());
    item->setDescription(obj["description"].toString().toStdString());
    item->setYear(obj["year"].toInt());
    item->setPublisher(obj["publisher"].toString().toStdString());
    item->setGenre(obj["genre"].toString().toStdString());
    item->setCast(obj["cast"].toString().toStdString());
    item->setDirector(obj["director"].toString().toStdString());
    item->setSeasons(obj["seasons"].toInt());
    item->setEpisodes(obj["episodes"].toInt());
    return item;
};
std::shared_ptr<Videogame> fromJsonVideogame(QJsonObject& obj){
    auto item=std::make_shared<Videogame>();
    item->setTitle(obj["title"].toString().toStdString());
    item->setDescription(obj["description"].toString().toStdString());
    item->setYear(obj["year"].toInt());
    item->setPublisher(obj["publisher"].toString().toStdString());
    item->setGenre(obj["genre"].toString().toStdString());
    item->setDeveloper(obj["developer"].toString().toStdString());
    return item;
};
