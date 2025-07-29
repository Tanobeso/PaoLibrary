#include "..\headers\AbstractItem.h"

AbstractItem::AbstractItem(string _title, string _description, unsigned int _year) : title(_title), description(_description), year(_year){
};

string AbstractItem::getTitle() const{
    return this->title;
};

void AbstractItem::setTitle(string t){
    this->title=t;
};

string AbstractItem::getDescription() const{
    return this->description;
};

void AbstractItem::setDescription(string d){
    this->description=d;
};

unsigned int AbstractItem::getYear() const{
    return this->year;
};

void AbstractItem::setYear(unsigned int y){
    this->year=y;
};
