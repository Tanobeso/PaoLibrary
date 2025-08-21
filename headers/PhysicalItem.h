#ifndef PHYSICALITEM_H
#define PHYSICALITEM_H
#include "AbstractItem.h"

class PhysicalItem: public AbstractItem{
private:
	string author;
	string size;
public:
    PhysicalItem(string _title, string _description, unsigned int _year, string _image, string _author, string _size);
    PhysicalItem()=default;

	string getAuthor() const;
    void setAuthor(const string&);
	string getSize() const;
    void setSize(const string&);
};
#endif
