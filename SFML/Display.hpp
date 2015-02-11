#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

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
#include "weapons.h"

class Disp
{
protected:
	sf::RenderWindow *win;
public:
	Disp(sf::RenderWindow *win):win(win) {};
	bool CorrectM(sf::Sprite &s);
	void dispSkill(int x, int y, sf::Texture &skill, sf::Text &text, sf::Sprite &s, int bar, int lvl);
	void dispParameter(sf::Text &text, int lvl, int x, int y);
	//1 - home, 2 - forest, 3 - city, 4 - tunnels
	void dispLoc(sf::Texture &loc, sf::Sprite &s, int parameter);
	void dispWeapon(sf::Texture &w, sf::Sprite &s, sf::Text &text, int parameter, weapon* displayed_weapon);
	void dispHours(sf::Text &text, int hours);
	void dispChoice(sf::Text &text, int parameter);
	void dispSentence(sf::Text &text, std::vector <std::string> &sentence);
	void dispButton(sf::Sprite &image, sf::Event *zdarzenie, int value, int *parameter, int sign);
	void dispTime(sf::Text &textH, sf::Text &textM, int hours, int minutes);
	//void dispGo(sf::Sprite &image, sf::Event *zdarzenie, std::vector <std::string> &sentence, int *CurrentLoc, int *LocationParameter);
	void dispThing(sf::Sprite &image, sf::Event *zdarzenie, std::vector <std::string> &sentence, std::string com);
	void SetFont(sf::Text &text, sf::Font &font, int size);
};

#endif