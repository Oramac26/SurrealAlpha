#ifndef PLACES_H_ 
#define PLACES_H_

#include <string>
#include <vector>
#include "generator.h"
#include "hero.h"

class Place
{
protected:
	std::string place_name;
	int place_luck;
	int visits_count;
	std::vector<item*> place_items;
	std::vector<weapon*> place_weapons;
	std::vector<Enemy*> place_enemies;
	RNG number;
public:
	Place(std::string name, int luck);
	void VisitPlace(Hero* myhero, int time, std::vector<std::string> *comunicates);
	void RefillPlace ();
};

#endif