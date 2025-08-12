#ifndef ART_H
#define ART_H
#include "PhysicalItem.h"


class Art: public PhysicalItem{
private:
	string style;
public:
	Art(string _title, string _description, unsigned int _year, string _author, string _size, string _style);

	string getStyle() const;
	void setStyle(string);

    QJsonObject toJson() const override;
    QDomElement toXml(QDomDocument &doc) const override;
};
#endif
