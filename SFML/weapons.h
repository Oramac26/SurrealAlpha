#ifndef WEAPONS_H_
#define WEAPONS_H_ 

#include <string>

struct weapon
{
	std::string name;
	int damage;
	int mass;
	int speed;
	bool range;
	weapon(std::string in_name, int in_dmg, int in_speed, bool in_range, int in_mass)
	{
		name = in_name;
		damage = in_dmg;
		speed = in_speed;
		range = in_range;
		mass = in_mass;
	}
	 bool operator<=(const std::string&);

};


#endif