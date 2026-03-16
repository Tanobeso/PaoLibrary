#include "../headers/AbstractItem.h"

AbstractItem::AbstractItem(string _title, string _description, unsigned int _year, string _image) : title(_title), description(_description), year(_year), image(_image){
};

string AbstractItem::getTitle() const{
    return this->title;
};

void AbstractItem::setTitle(const string& t){
    this->title=t;
};

string AbstractItem::getDescription() const{
    return this->description;
};

void AbstractItem::setDescription(const string& d){
    this->description=d;
};

unsigned int AbstractItem::getYear() const{
    return this->year;
};

void AbstractItem::setYear(const unsigned int& y){
    this->year=y;
};

string AbstractItem::getImage() const{
    return this->image;
};

void AbstractItem::setImage(const string& i){
    this->image=i;
};
