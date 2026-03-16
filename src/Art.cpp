#include "../headers/Art.h"
Art::Art(string _title, string _description, unsigned int _year, string _image, string _author, string _size, string _style) : PhysicalItem(_title, _description, _year, _image, _author, _size), style(_style){
};

string Art::getStyle() const{
    return this->style;
};

void Art::setStyle(const string& s){
    this->style=s;
};

QJsonObject Art::toJson() const{
    QJsonObject obj;
    obj["type"]="art";
    obj["title"]=QString::fromStdString(getTitle());
    obj["description"]=QString::fromStdString(getDescription());
    obj["year"]=(int)getYear();
    obj["image"]=QString::fromStdString(getImage());
    obj["author"]=QString::fromStdString(getAuthor());
    obj["size"]=QString::fromStdString(getSize());
    obj["style"]=QString::fromStdString(getStyle());
    return obj;
};

QDomElement Art::toXml(QDomDocument &doc) const {
    QDomElement e = doc.createElement("Art");
    e.appendChild(doc.createElement("Title")).appendChild(doc.createTextNode(QString::fromStdString(getTitle())));
    e.appendChild(doc.createElement("Description")).appendChild(doc.createTextNode(QString::fromStdString(getDescription())));
    e.appendChild(doc.createElement("Year")).appendChild(doc.createTextNode(QString::number (getYear())));
    e.appendChild(doc.createElement("Image")).appendChild(doc.createTextNode(QString::fromStdString(getImage())));
    e.appendChild(doc.createElement("Author")).appendChild(doc.createTextNode(QString::fromStdString(getAuthor())));
    e.appendChild(doc.createElement("Size")).appendChild(doc.createTextNode(QString::fromStdString(getSize())));
    e.appendChild(doc.createElement("Style")).appendChild(doc.createTextNode(QString::fromStdString(getStyle())));
    return e;
}

void Art::accept(ItemVisitor& visitor) {
    visitor.visitArt(*this);
}
