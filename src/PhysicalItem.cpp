#include "../headers/PhysicalItem.h"

PhysicalItem::PhysicalItem(string _title, string _description, unsigned int _year, string _image, string _author, string _size): AbstractItem(_title, _description, _year, _image), author(_author), size(_size){
};

string PhysicalItem::getAuthor() const{
    return this->author;
};

void PhysicalItem::setAuthor(const string& a){
    this->author=a;
};

string PhysicalItem::getSize() const{
    return this->size;
};

void PhysicalItem::setSize(const string& s){
    this->size=s;
};
