#include "weapons.h"

bool weapon::operator<=(const std::string& s)
{
	int i = 0;
	int string_check;
	std::string temp_string;
	if (this->name.size() > s.size())
	{
		while (this->name[i] != ' ')
			i++;
		temp_string = this->name.substr(i+1, this->name.size());
		if (temp_string == s)
			return true;
		else
			return false;
	}
}