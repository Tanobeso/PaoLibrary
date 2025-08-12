#include "..\headers\Art.h"
Art::Art(string _title, string _description, unsigned int _year, string _author, string _size, string _style) : PhysicalItem(_title, _description, _year, _author, _size), style(_style){
};

string Art::getStyle() const{
    return this->style;
};

void Art::setStyle(string s){
    this->style=s;
};

QJsonObject Art::toJson() const{
    QJsonObject obj;
    obj["type"]="art";
    obj["title"]=QString::fromStdString(getTitle());
    obj["description"]=QString::fromStdString(getDescription());
    obj["year"]=(int)getYear();
    obj["author"]=QString::fromStdString(getAuthor());
    obj["size"]=QString::fromStdString(getSize());
    obj["style"]=QString::fromStdString(getStyle());
    return obj;
};
