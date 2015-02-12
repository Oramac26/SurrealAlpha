#include "Game.hpp"

#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>

#define BARLENGTH 3.27
#define XALL 894
#define YAGILITY 48
#define YSCAVENGING 81
#define YCRAFTING 113
#define xp 227
#define yp 24


//1 - home, 2 - forest, 3 - city, 4 - tunnels
/*void GameScr::dispWeapon(sf::Texture &w, sf::Sprite &s, sf::Text &text, int parameter, weapon* displayed_weapon)
{
	std::ostringstream ss;
	ss << displayed_weapon->name;
	text.setString(ss.str());
	if (displayed_weapon->range)
	{
		if (*displayed_weapon <= "slingshot") w.loadFromFile("slingshot.png");
		//if (My_Hero->) w.loadFromFile("slingshot.png");
		if (*displayed_weapon <= "bow") w.loadFromFile("bow.png");
		if (*displayed_weapon <= "crossbow") w.loadFromFile("crossbow.png");
		s.setTexture(w);
		s.setPosition(1150, 360);
		text.setPosition(1160, 481);
	}
	else
	{
		if (*displayed_weapon <= "stick") w.loadFromFile("stick.png");
		if (*displayed_weapon <= "knife") w.loadFromFile("knife.png");
		if (*displayed_weapon <= "axe") w.loadFromFile("axe.png");
		s.setTexture(w);
		s.setPosition(1150, 190);
		text.setPosition(1160, 305);
	}
	win->draw(s);
	win->draw(text);
}
*/
void GameScr::dispGo(sf::Sprite &image, sf::Event *zdarzenie, std::vector <std::string> &sentence, int *CurrentLoc, int *LocationParameter, int *Hours)
{
	if (CorrectM(image))
	{
		win->draw(image);
		if (zdarzenie->type == sf::Event::MouseButtonPressed && zdarzenie->mouseButton.button == sf::Mouse::Left)
		{
			if (Time_of_day < 22)
			{
				places_list[*CurrentLoc - 1]->VisitPlace(My_Hero, *Hours, &sentence);
				sentence.push_back("You came back home");
				*CurrentLoc = *LocationParameter;
				Sleep(100);
				*CurrentLoc = 1;
				Time_of_day += *Hours;
			}
			else
			{
				sentence.push_back("It's too late");
				Sleep(100);
				Time_of_day = 8;
			}
		}
	}
}




int GameScr::Run(sf::RenderWindow &window){

	bool Running = true, com = true, done = false;
	int MeleeParameter = 1, RangedParameter = 1, Hours = 2, LocationParameter = 2, CurrentLoc = 1;
	std::vector <std::string> sentence;
	std::string new_sentence, SkillName;

	sf::Texture obr1, obr2, obr3, obr4, skill, loc, weap, obr5, obr6, obr7, obr8;
	obr1.loadFromFile("MainScr.png");
	obr2.loadFromFile("Inventoryclc.png");
	obr3.loadFromFile("Goclc.png");
	obr4.loadFromFile("Hideoutclc.png");
	obr5.loadFromFile("ArrowUp.png");
	obr6.loadFromFile("ArrowDown.png");
	obr7.loadFromFile("Plus.png");
	obr8.loadFromFile("Minus.png");

	sf::Sprite bg, inv, go, hide, bar, bar2, bar3, location, weapon, ArrowUpR, ArrowDownR, ArrowUpM, ArrowDownM, plus, minus, plusLoc, minusLoc;
	bg.setTexture(obr1);
	inv.setTexture(obr2);
	go.setTexture(obr3);
	hide.setTexture(obr4);
	ArrowUpR.setTexture(obr5);
	ArrowDownR.setTexture(obr6);
	ArrowUpM.setTexture(obr5);
	ArrowDownM.setTexture(obr6);
	plus.setTexture(obr7);
	minus.setTexture(obr8);
	plusLoc.setTexture(obr7);
	minusLoc.setTexture(obr8);

	minusLoc.setPosition(514, 498);
	plusLoc.setPosition(730, 498);

	minus.setPosition(514, 538);
	plus.setPosition(730, 538);

	ArrowUpR.setPosition(1090, 420);
	ArrowDownR.setPosition(1090, 464);
	ArrowUpM.setPosition(1090, 241);
	ArrowDownM.setPosition(1090, 285);

	inv.setPosition(781, 627);
	go.setPosition(505, 574);
	hide.setPosition(199, 626);

	sf::Font font;
	font.loadFromFile("28.ttf");
	sf::Text level, communicate, parameter, Sname, weaponname, weaponname2, TextH, Choice, TimeH, TimeM;

	SetFont(TimeH, font, 30);
	SetFont(TimeM, font, 30);
	SetFont(Choice, font, 30);
	SetFont(TextH, font, 30);
	SetFont(weaponname, font, 15);
	SetFont(weaponname2, font, 15);
	SetFont(Sname, font, 15);
	SetFont(level, font, 15);
	SetFont(communicate, font, 15);
	SetFont(parameter, font, 25);

	sf::Event zdarzenie;
	sf::Event *adres_zdarzenia = &zdarzenie;
	while (Running){

		while (win->pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::Escape) return (0);
			if (zdarzenie.type == sf::Event::Closed)
			{
				return (-1);
			}
		}

		win->draw(bg);

		dispSkill(XALL, YAGILITY, skill, level, bar, My_Hero->FindSkill("agility")->SkillPercent(), My_Hero->FindSkill("agility")->ViewSkillLevel());
		dispSkill(XALL, YSCAVENGING, skill, level, bar2, My_Hero->FindSkill("scavenging")->SkillPercent(), My_Hero->FindSkill("scavenging")->ViewSkillLevel());
		dispSkill(XALL, YCRAFTING, skill, level, bar3, 60, My_Hero->FindSkill("crafting")->ViewSkillLevel());
		dispParameter(parameter, My_Hero->ViewHealth(), xp, yp);
		dispParameter(parameter, My_Hero->ViewStamina(), xp, yp + 30);
		dispLoc(loc, location, CurrentLoc);
		dispWeapon(weap, weapon, weaponname, MeleeParameter, My_Hero->CarriedMeleeWeapon(MeleeParameter));
		dispWeapon(weap, weapon, weaponname2, RangedParameter, My_Hero->CarriedRangedWeapon(RangedParameter));
		dispHours(TextH, Hours);
		dispChoice(Choice, LocationParameter);
		dispTime(TimeH, TimeM, Time_of_day, 00);

		if (com == true)
		{
			sentence.push_back("welcome to surreal alpha 01");
			com = false;
		}

		dispSentence(communicate, sentence);
		dispButton(ArrowUpR, adres_zdarzenia, My_Hero->WeaponNumber(), &RangedParameter, 1);
		dispButton(ArrowDownR, adres_zdarzenia, 1, &RangedParameter, -1);
		dispButton(ArrowUpM, adres_zdarzenia, My_Hero->WeaponNumber(), &MeleeParameter, 1);
		dispButton(ArrowDownM, adres_zdarzenia, 1, &MeleeParameter, -1);
		dispButton(plus, adres_zdarzenia, 8, &Hours, 1);
		dispButton(minus, adres_zdarzenia, 2, &Hours, -1);
		dispButton(minusLoc, adres_zdarzenia, 2, &LocationParameter, -1);
		dispButton(plusLoc, adres_zdarzenia, 4, &LocationParameter, 1);
		dispGo(go, adres_zdarzenia, sentence, &CurrentLoc, &LocationParameter, &Hours);
		std::string weapon_parameters;
		weapon_parameters += My_Hero->CarriedMeleeWeapon()->name + " " + std::to_string(My_Hero->CarriedMeleeWeapon()->damage) + " DMG";
		dispThing(inv, adres_zdarzenia, sentence, weapon_parameters);
		dispThing(hide, adres_zdarzenia, sentence, "You have eaten something");

		win->display();
	}

	return (-1);
}
