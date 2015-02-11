#include "generator.h"

item* ObjGenerator::ItemGenerator(int seed)
{
	//RNG number;
	item* new_item = new item(number.BigRange(seed), item_names[number.NumberFromTo(0, item_names.size()-1)]);
	return new_item;
}

weapon* ObjGenerator::WeaponGenerator(int seed)
{
	//RNG number;
	weapon* new_weapon;
	if (number.FortuneLoop(1, 60))
	{
		if (number.FortuneLoop(1))
			new_weapon = new weapon(good_prefix[number.NumberFromTo(0, good_prefix.size()-1)] + melee_weapon_names[number.NumberFromTo(0, melee_weapon_names.size()-1)], number.SmallRange(seed), number.SmallRange(10), false, number.SmallRange(10));
		else
			new_weapon = new weapon(good_prefix[number.NumberFromTo(0, good_prefix.size()-1)] + ranged_weapon_names[number.NumberFromTo(0, ranged_weapon_names.size()-1)], number.SmallRange(seed), number.SmallRange(10), true, number.SmallRange(10));
	}
	else
	{
		if (number.FortuneLoop(1))
			new_weapon = new weapon(bad_prefix[number.NumberFromTo(0, bad_prefix.size()-1)] + melee_weapon_names[number.NumberFromTo(0, melee_weapon_names.size()-1)], number.SmallRange(10), number.SmallRange(5), false, number.SmallRange(5));
		else
			new_weapon = new weapon(bad_prefix[number.NumberFromTo(0, bad_prefix.size()-1)] + ranged_weapon_names[number.NumberFromTo(0, ranged_weapon_names.size()-1)], number.SmallRange(10), number.SmallRange(5), true, number.SmallRange(5));
	}
	return new_weapon;
}

Enemy* ObjGenerator::EnemyGenerator(int seed)
{
	//RNG number;
	Enemy* new_enemy = new Enemy(seed, WeaponGenerator(seed * 10), bad_prefix[number.NumberFromTo(0, bad_prefix.size() - 1)] + enemy_names[number.NumberFromTo(0, enemy_names.size() - 1)]);
	return new_enemy;
}

ObjGenerator::ObjGenerator()
{
	good_prefix = { "good ", "nice ", "superb ", "sublime ", "powerful " };
	bad_prefix = { "awful ", "bad ", "dreadful ", "horrible " };
	ranged_weapon_names = { "slingshot", "bow", "crossbow" };
	melee_weapon_names = { "stick", "knife", "axe" };
	item_names = { "materials", "food", "weapon parts" };
	enemy_names = { "monster", "zombie", "creature", "infected" };
}