#include "../headers/XmlManager.h"
QList<std::shared_ptr<AbstractItem>> loadXml(const QString &filePath){
    QFile file(filePath);
    QList<std::shared_ptr<AbstractItem>> lib;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Errore apertura file in lettura";
        return lib;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qWarning() << "Errore parsing XML";
        file.close();
        return lib;
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();

    while (!node.isNull()) {
        QDomElement e = node.toElement();
        if (!e.isNull()) {
            if (e.tagName() == "Art") {
                lib.append(fromXmlArt(e));
            } else if (e.tagName() == "Book") {
                lib.append(fromXmlBook(e));
            } else if (e.tagName() == "Movie") {
                lib.append(fromXmlMovie(e));
            } else if (e.tagName() == "Series") {
                lib.append(fromXmlSeries(e));
            } else if (e.tagName() == "Videogame") {
                lib.append(fromXmlVideogame(e));
            }
        }
        node = node.nextSibling();
    }
return lib;
};

std::shared_ptr<Art> fromXmlArt(const QDomElement &element){
    auto item=std::make_shared<Art>();
    item->setTitle(element.firstChildElement("Title").text().toStdString());
    item->setDescription(element.firstChildElement("Description").text().toStdString());
    item->setYear(element.firstChildElement("Year").text().toInt());
    item->setImage(element.firstChildElement("Image").text().toStdString());
    item->setAuthor(element.firstChildElement("Author").text().toStdString());
    item->setSize(element.firstChildElement("Size").text().toStdString());
    item->setStyle(element.firstChildElement("Style").text().toStdString());
    return item;
};

std::shared_ptr<Book> fromXmlBook(const QDomElement &element){
    auto item=std::make_shared<Book>();
    item->setTitle(element.firstChildElement("Title").text().toStdString());
    item->setDescription(element.firstChildElement("Description").text().toStdString());
    item->setYear(element.firstChildElement("Year").text().toInt());
    item->setImage(element.firstChildElement("Image").text().toStdString());
    item->setAuthor(element.firstChildElement("Author").text().toStdString());
    item->setSize(element.firstChildElement("Size").text().toStdString());
    item->setPublisher(element.firstChildElement("Publisher").text().toStdString());
    item->setGenre(element.firstChildElement("Genre").text().toStdString());
    item->setEdition(element.firstChildElement("Author").text().toStdString());
    return item;
};

std::shared_ptr<Movie> fromXmlMovie(const QDomElement &element){
auto item=std::make_shared<Movie>();
    item->setTitle(element.firstChildElement("Title").text().toStdString());
    item->setDescription(element.firstChildElement("Description").text().toStdString());
    item->setYear(element.firstChildElement("Year").text().toInt());
    item->setImage(element.firstChildElement("Image").text().toStdString());
    item->setPublisher(element.firstChildElement("Publisher").text().toStdString());
    item->setGenre(element.firstChildElement("Genre").text().toStdString());
    item->setCast(element.firstChildElement("Cast").text().toStdString());
    item->setDirector(element.firstChildElement("Director").text().toStdString());
    item->setLength(element.firstChildElement("Length").text().toInt());
    return item;
};

std::shared_ptr<Series> fromXmlSeries(const QDomElement &element){
auto item=std::make_shared<Series>();
    item->setTitle(element.firstChildElement("Title").text().toStdString());
    item->setDescription(element.firstChildElement("Description").text().toStdString());
    item->setYear(element.firstChildElement("Year").text().toInt());
    item->setImage(element.firstChildElement("Image").text().toStdString());
    item->setPublisher(element.firstChildElement("Publisher").text().toStdString());
    item->setGenre(element.firstChildElement("Genre").text().toStdString());
    item->setCast(element.firstChildElement("Cast").text().toStdString());
    item->setDirector(element.firstChildElement("Director").text().toStdString());
    item->setSeasons(element.firstChildElement("Seasons").text().toInt());
    item->setEpisodes(element.firstChildElement("Episodes").text().toInt());
    return item;
};

std::shared_ptr<Videogame> fromXmlVideogame(const QDomElement &element){
auto item=std::make_shared<Videogame>();
    item->setTitle(element.firstChildElement("Title").text().toStdString());
    item->setDescription(element.firstChildElement("Description").text().toStdString());
    item->setYear(element.firstChildElement("Year").text().toInt());
    item->setImage(element.firstChildElement("Image").text().toStdString());
    item->setPublisher(element.firstChildElement("Publisher").text().toStdString());
    item->setGenre(element.firstChildElement("Genre").text().toStdString());
    item->setDeveloper(element.firstChildElement("Developer").text().toStdString());
    return item;
};
