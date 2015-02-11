#ifndef OBJ_GENERATOR_H_ 
#define OBJ_GENERATOR_H_

#include <string>
#include <vector>
#include "item.h"
#include "weapons.h"
#include "RNG.h"
#include "enemy.h"

class ObjGenerator
{
protected:
	std::vector<std::string> good_prefix;
	std::vector<std::string> bad_prefix;
	std::vector<std::string> ranged_weapon_names;
	std::vector<std::string> melee_weapon_names;
	std::vector<std::string> item_names;
	std::vector<std::string> enemy_names;
	RNG number;
public:
	ObjGenerator();
	item* ItemGenerator(int seed); 
	weapon* WeaponGenerator(int seed);
	Enemy* EnemyGenerator(int seed);
};


#endif