#include "..\headers\Book.h"

Book::Book(string _title, string _description, unsigned int _year, string _author, string _size, string _publisher, string _genre, string _edition): PhysicalItem(_title, _description, _year, _author, _size), publisher(_publisher), genre(_genre), edition(_edition){
};

string Book::getPublisher() const{
    return this->publisher;
};

void Book::setPublisher(string p){
    this->publisher=p;
};

string Book::getGenre() const{
    return this->genre;
};

void Book::setGenre(string g){
    this->genre=g;
};

string Book::getEdition() const{
    return this->edition;
};

void Book::setEdition(string e){
    this->edition=e;
};

QJsonObject Book::toJson() const{
    QJsonObject obj;
    obj["type"]="book";
    obj["title"]=QString::fromStdString(getTitle());
    obj["description"]=QString::fromStdString(getDescription());
    obj["year"]=(int)getYear();
    obj["author"]=QString::fromStdString(getAuthor());
    obj["size"]=QString::fromStdString(getSize());
    obj["publisher"]=QString::fromStdString(getPublisher());
    obj["genre"]=QString::fromStdString(getGenre());
    obj["edition"]=QString::fromStdString(getEdition());
    return obj;
};

QDomElement Book::toXml(QDomDocument &doc) const {
    QDomElement e = doc.createElement("Book");
    e.appendChild(doc.createElement("Title")).appendChild(doc.createTextNode(QString::fromStdString(getTitle())));
    e.appendChild(doc.createElement("Description")).appendChild(doc.createTextNode(QString::fromStdString(getDescription())));
    e.appendChild(doc.createElement("Year")).appendChild(doc.createTextNode(QString::number (getYear())));
    e.appendChild(doc.createElement("Author")).appendChild(doc.createTextNode(QString::fromStdString(getAuthor())));
    e.appendChild(doc.createElement("Size")).appendChild(doc.createTextNode(QString::fromStdString(getSize())));
    e.appendChild(doc.createElement("Publisher")).appendChild(doc.createTextNode(QString::fromStdString(getPublisher())));
    e.appendChild(doc.createElement("Genre")).appendChild(doc.createTextNode(QString::fromStdString(getGenre())));
    e.appendChild(doc.createElement("Edition")).appendChild(doc.createTextNode(QString::fromStdString(getEdition())));
    return e;
}
