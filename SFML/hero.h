#ifndef HERO_H_ 
#define HERO_H_

#include "weapons.h"
#include "entity.h"
#include "skills.h"
#include "item.h"
#include <vector>



class Hero : public Entity
{
protected:
	bool sick;
	bool sleep;
	int level_exp;
	int level_exp_req;
	//unsigned int level_parameter;
	std::vector<weapon*> weapon_list;
	std::vector<Skills*> skill_list;
	weapon* carried_melee_weapon;
	std::vector<item*> item_list; // temprary option
	int weapon_number;


public:
	//Hero() : Entity(1) {};
	Hero() : Entity(1), sick(false), sleep(false) 
	{
		level_exp = 0;
		level_exp_req = (skill_list.size() + 1) * 10;
	};
	bool ViewSick() { return sick; };
	bool ViewSleep() { return sleep; };
	//bool WeaponRange(){ return weapon_carried->range; };
	void AddWeapon(weapon* New_weapon) { weapon_list.push_back(New_weapon); };
	void AddSkill(Skills* New_skill) { skill_list.push_back(New_skill); };
	int SkillNumber() { return skill_list.size(); };
	Skills* FindSkill(std::string name);
	item* FindItem(std::string name);
	weapon* CarriedMeleeWeapon(int weapon_number);
	weapon* CarriedMeleeWeapon();
	weapon* CarriedRangedWeapon(int weapon_number);
	void WeaponChoose(weapon* CarriedWeapon) { weapon_carried = CarriedWeapon; };
	void WeaponChoose();
	void MeleeWeaponChoose(weapon* CarriedMeleeWeapon) { carried_melee_weapon = CarriedMeleeWeapon; };
	void MeleeWeaponChoose();
	void HeroExpInc(int value);
	void AddItem(item* new_item);
	int WeaponNumber() { return weapon_list.size(); };
	void ReplenishHP();
	void ReplenishStamina();
	void HeroExpReqInc();
	~Hero() {};
};

#endif