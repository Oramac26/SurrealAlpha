#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "fight.h"
#include "places.h"
#include "Display.hpp"

class GameScr :public cScreen, protected fight, public Disp
{
protected:
	std::vector<Place*> places_list;
	Hero* My_Hero;
	int Time_of_day;
public:
	GameScr(sf::RenderWindow *in_win) :Disp(in_win)
	{
		Skills* skill1 = new Skills("agility");
		Skills* skill2 = new Skills("scavenging");
		Skills* skill3 = new Skills("crafting");
		Hero* hero = new Hero;
		My_Hero = hero;
		My_Hero->AddSkill(skill1);
		My_Hero->AddSkill(skill2);
		My_Hero->AddSkill(skill3);
		fight(My_Hero, 0, 20);
		ObjGenerator New_Generator;
		for (int i = 0; i < 6; ++i)
			My_Hero->AddWeapon(New_Generator.WeaponGenerator(20));
		//My_Hero->WeaponChoose(New_Generator.WeaponGenerator(20));
		//My_Hero->MeleeWeaponChoose(New_Generator.WeaponGenerator(20));
		Place* Forest = new Place("Forest",20);
		Place* City = new Place("City",30);
		Place* Tunnels = new Place("Tunnels",40);
		places_list.push_back(Forest);
		places_list.push_back(City);
		places_list.push_back(Tunnels);
		Time_of_day = 8;
	}
	virtual int Run(sf::RenderWindow &win);
	void dispGo(sf::Sprite &image, sf::Event *zdarzenie, std::vector <std::string> &sentence, int *CurrentLoc, int *LocationParameter, int *Hours);
};

#endif