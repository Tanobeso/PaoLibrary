#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H
#include <string>
#include <QJsonObject>
#include <QDomDocument>
#include "ItemVisitor.h"

using std::string;

class AbstractItem{
private:
    string title;
    string description;
	unsigned int year;
    string image;
public:
    AbstractItem(string _title, string _description, unsigned int _year, string _image);
    AbstractItem()=default;
	virtual ~AbstractItem()=default;
	
	string getTitle() const;
    void setTitle(const string&);
	string getDescription() const;
    void setDescription(const string&);
	unsigned int getYear() const;
    void setYear(const unsigned int&);
    string getImage() const;
    void setImage(const string&);

    virtual QJsonObject toJson() const = 0;
    virtual QDomElement toXml(QDomDocument &doc) const = 0;

    virtual void accept(ItemVisitor& visitor)=0;
};
#endif
