#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H
#include <string>
#include <QJsonObject>
#include <QDomDocument>

using std::string;

class AbstractItem{
private:
    string title;
    string description;
	unsigned int year;
public:
    AbstractItem(string _title, string _description, unsigned int _year);
	virtual ~AbstractItem()=default;
	
	string getTitle() const;
	void setTitle(string);
	string getDescription() const;
	void setDescription(string);
	unsigned int getYear() const;
	void setYear(unsigned int);

    virtual QJsonObject toJson() const = 0;
    virtual QDomElement toXml(QDomDocument &doc) const = 0;
};
#endif
