#ifndef ITEM_H_ 
#define ITEM_H_

#include <string>

struct item
{
	std::string item_type;
	int number;
	item & operator+(item&);
	item(int value, std::string name) : item_type(name), number(value) {};
	item() {};
};


#endif