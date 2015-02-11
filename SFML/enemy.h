#ifndef ENEMY_H_ 
#define ENEMY_H_ 
#include "Entity.h"


class Enemy: public Entity
{
protected:
	std::string name;
public:
	//Enemy() {};
	Enemy(int value, weapon* weapon, std::string name) : name(name), Entity(value, weapon){};
	virtual ~Enemy() {};
};

#endif