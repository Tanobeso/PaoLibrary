#include "../headers/DigitalItem.h"

DigitalItem::DigitalItem(string _title, string _description, unsigned int _year, string _image, string _publisher, string _genre) : AbstractItem(_title, _description, _year, _image), publisher(_publisher), genre(_genre){
};

string DigitalItem::getPublisher() const{
    return this->publisher;
};

void DigitalItem::setPublisher(const string& p){
    this->publisher=p;
};

string DigitalItem::getGenre() const{
    return this->genre;
};

void DigitalItem::setGenre(const string& g){
    this->genre=g;
};
