#ifndef ENTITY_H_ 
#define ENTITY_H_ 
#include "weapons.h"

#define MAX_VALUE 100

class Entity
{
protected:
	int health;
	int stamina;
	int level;
	int health_max;
	int stamina_max;
	weapon* weapon_carried;

public:
	Entity(int value) : health(MAX_VALUE*value), health_max(MAX_VALUE*value), stamina_max(MAX_VALUE*value), stamina(MAX_VALUE*value), level(value), weapon_carried(NULL) {};
	Entity(int value, weapon* weapon) : health(MAX_VALUE*value), health_max(MAX_VALUE*value), stamina_max(MAX_VALUE*value), stamina(MAX_VALUE*value), level(value), weapon_carried(weapon) {};
	int ViewHealth() { return health; };
	int ViewStamina() { return stamina; };
	int ViewLevel() { return level; };
	weapon* WeaponParameters(){ return weapon_carried; };
	virtual void ChangeHealth(int value);
	void ChangeStamina(int value);
	void GainLevel();
	void MaxHealthInc();
	void MaxStaminaInc();
	virtual ~Entity() {};
};

#endif