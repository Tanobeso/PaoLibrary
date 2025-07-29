#ifndef PHYSICALITEM_H
#define PHYSICALITEM_H
#include "AbstractItem.h"

class PhysicalItem: public AbstractItem{
private:
	string author;
	string size;
public:
	PhysicalItem(string _title, string _description, unsigned int _year, string _author, string _size);
	
	string getAuthor() const;
	void setAuthor(string);
	string getSize() const;
	void setSize(string);
};
#endif
