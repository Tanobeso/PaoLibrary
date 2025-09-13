#include "../headers/Videogame.h"

Videogame::Videogame(string _title, string _description, unsigned int _year, string _image, string _publisher, string _genre, string _developer) : DigitalItem(_title, _description, _year, _image, _publisher, _genre), developer(_developer){
};

string Videogame::getDeveloper() const{
    return this->developer;
};

void Videogame::setDeveloper(const string& d){
    this->developer=d;
};

QJsonObject Videogame::toJson() const{
    QJsonObject obj;
    obj["type"]="videogame";
    obj["title"]=QString::fromStdString(getTitle());
    obj["description"]=QString::fromStdString(getDescription());
    obj["year"]=(int)getYear();
    obj["image"]=QString::fromStdString(getImage());
    obj["publisher"]=QString::fromStdString(getPublisher());
    obj["genre"]=QString::fromStdString(getGenre());
    obj["developer"]=QString::fromStdString(getDeveloper());
    return obj;
};

QDomElement Videogame::toXml(QDomDocument &doc) const {
    QDomElement e = doc.createElement("Videogame");
    e.appendChild(doc.createElement("Title")).appendChild(doc.createTextNode(QString::fromStdString(getTitle())));
    e.appendChild(doc.createElement("Description")).appendChild(doc.createTextNode(QString::fromStdString(getDescription())));
    e.appendChild(doc.createElement("Year")).appendChild(doc.createTextNode(QString::number (getYear())));
    e.appendChild(doc.createElement("Image")).appendChild(doc.createTextNode(QString::fromStdString(getImage())));
    e.appendChild(doc.createElement("Publisher")).appendChild(doc.createTextNode(QString::fromStdString(getPublisher())));
    e.appendChild(doc.createElement("Genre")).appendChild(doc.createTextNode(QString::fromStdString(getGenre())));
    e.appendChild(doc.createElement("Developer")).appendChild(doc.createTextNode(QString::fromStdString(getDeveloper())));
    return e;
}

void Videogame::accept(ItemVisitor& visitor) {
    visitor.visitVideogame(*this);
}
