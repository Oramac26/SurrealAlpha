#include "item.h"

item & item::operator+(item& it)
{
	if (item_type == it.item_type)
		number = number + it.number;
	return *this;
}