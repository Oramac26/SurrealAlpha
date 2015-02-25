#include "places.h"
#include "RNG.h"
#include "fight.h"


#define MAX_ITEM_HOLD 5

Place::Place(std::string name, int luck)
{
	ObjGenerator ItemGenrator;
	//RNG number;
	visits_count = 0;
	place_name = name;
	place_luck = number.BigRange(luck);
	for (int i = 0; i < MAX_ITEM_HOLD; ++i)
	{
		place_items.push_back(ItemGenrator.ItemGenerator(place_luck * 2));
		place_weapons.push_back(ItemGenrator.WeaponGenerator(place_luck));
		place_enemies.push_back(ItemGenrator.EnemyGenerator(visits_count + 2));
	}
}

void Place::RefillPlace()
{
	ObjGenerator ItemGenrator;
	place_luck = number.BigRange(visits_count + place_luck);
	for (int i = 0; i < MAX_ITEM_HOLD; ++i)
	{
		place_items.push_back(ItemGenrator.ItemGenerator(place_luck * 2));
		place_weapons.push_back(ItemGenrator.WeaponGenerator(place_luck));
		place_enemies.push_back(ItemGenrator.EnemyGenerator(visits_count + 2));
	}

}

void Place::VisitPlace(Hero* myhero, int time, std::vector<std::string> *comunicates)
{
	std::string comuinicate("You found ");
	//RNG number;
	if ((place_items.size() < 2) || (place_weapons.size() < 2) || (place_enemies.size() < 2))
		RefillPlace();
	int vector_pos;
	visits_count++;
	for (int i = 0; i < time; ++i)
	{
		if (number.FortuneLoop(myhero->FindSkill("scavenging")->ViewSkillLevel(), 70))
		{
			vector_pos = number.NumberFromTo(0, place_items.size() - 1);
			item* new_item = place_items[vector_pos];
			comuinicate += std::to_string(new_item->number) + " " + new_item->item_type;
			comunicates->push_back(comuinicate);
			myhero->FindSkill("scavenging")->SkillExpInc(20);
			myhero->HeroExpInc(number.SmallRange(5));
			place_items.erase(place_items.begin() + vector_pos);
		}
		comuinicate = "You found ";
		if (number.FortuneLoop(myhero->FindSkill("scavenging")->ViewSkillLevel(), 90))
		{
			vector_pos = number.NumberFromTo(0, place_weapons.size() - 1);
			weapon* new_weapon = place_weapons[vector_pos];
			myhero->AddWeapon(new_weapon);
			comuinicate += new_weapon->name;
			comunicates->push_back(comuinicate);
			myhero->FindSkill("scavenging")->SkillExpInc(40);
			myhero->HeroExpInc(number.SmallRange(20));
			place_weapons.erase(place_weapons.begin() + vector_pos);
		}
		comuinicate = "You found ";
		if (number.FortuneLoop(1, 90))
		{
			vector_pos = number.NumberFromTo(0, place_enemies.size() - 1);
			fight new_fight;
			new_fight.SetFighters(myhero, place_enemies[vector_pos]);
			new_fight.Main_Fight(comunicates);
			if (!place_enemies[vector_pos]->IsAlive())
				place_enemies.erase(place_enemies.begin() + vector_pos);
			if (!myhero->IsAlive())
				comunicates->push_back("You died");
		}
	}
}