#include "hero.h"


Skills* Hero::FindSkill(std::string name)
{
	if (SkillNumber() > 0)
	{
		for (int i = 0; i < skill_list.size(); i++)
		{
			if (skill_list[i]->ViewName() == name)
			{
				return skill_list[i];
			}
		}
		return 0;
	}
	else return 0;
}


weapon* Hero::CarriedMeleeWeapon(int weapon_number)
{
	int j = 0;
	int i;
	for (i = 0; j < weapon_number; i++)
	{
		if (i >= weapon_list.size())
			i = 0;
		if (!weapon_list[i]->range)
			j++;
	}
	carried_melee_weapon = weapon_list[i - 1];
	return weapon_list[i-1];
};


weapon* Hero::CarriedMeleeWeapon()
{
	return carried_melee_weapon;
};

weapon* Hero::CarriedRangedWeapon(int weapon_number)
{
	int j = 0;
	int i;
	for (i = 0; j < weapon_number; ++i)
	{
		if (i >= weapon_list.size())
			i = 0;
		if (weapon_list[i]->range)
			j++;
	}
	weapon_carried = weapon_list[i - 1];
	return weapon_list[i-1];
};

//Hero::Hero()
//{
	//sick = false;
	//sleep = false; 
	//carried_melee_weapon = new weapon("bare", 1, 10, false, 1); ;
	//level_exp = 0;
	//level_exp_req = (skill_list.size()+1) * 10;
	//level_parameter = 0;
//}
void Hero::HeroExpInc(int value)
{
	level_exp = level_exp + value;
	if (level_exp > level_exp_req)
	{
		level_exp = level_exp - level_exp_req;
		HeroExpReqInc();
		GainLevel();
		ReplenishHP();
		ReplenishStamina();
	}
}

void Hero::HeroExpReqInc()
{
	level_exp_req = level_exp_req + skill_list.size()*level;
}

void Hero::AddItem(item* new_item)
{
	item_list.push_back(new_item);
}

void Hero::ReplenishHP()
{
	health = health_max;
}

void Hero::ReplenishStamina()
{
	stamina = stamina_max;
}
