#ifndef DIGITALITEM_H
#define DIGITALITEM_H
#include "AbstractItem.h"

class DigitalItem: public AbstractItem{
private:
	string publisher;
	string genre;
public:
    DigitalItem(string _title, string _description, unsigned int _year, string _image, string _publisher, string _genre);
    DigitalItem()=default;

	string getPublisher() const;
    void setPublisher(const string&);
	string getGenre() const;
    void setGenre(const string&);
};
#endif
