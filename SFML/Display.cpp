#include "Display.hpp"

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

bool Disp::CorrectM(sf::Sprite &s)
{
	if (
		sf::Mouse::getPosition(*win).x > s.getGlobalBounds().left &&
		sf::Mouse::getPosition(*win).y > s.getGlobalBounds().top &&
		sf::Mouse::getPosition(*win).x < s.getGlobalBounds().left + s.getGlobalBounds().width &&
		sf::Mouse::getPosition(*win).y < s.getGlobalBounds().top + s.getGlobalBounds().height
		)
		return 1;
	else
		return 0;
}

void Disp::dispSkill(int x, int y, sf::Texture &skill, sf::Text &text, sf::Sprite &s, int bar, int lvl)
{
	std::ostringstream ss;
	ss << lvl;
	text.setString(ss.str());
	skill.loadFromFile("Barcut.png", sf::IntRect(0, 0, BARLENGTH*bar, 7));
	s.setTexture(skill);
	s.setPosition(x + 12, y + 5);
	text.setPosition(x, y);
	win->draw(text);
	win->draw(s);
}

void Disp::dispParameter(sf::Text &text, int lvl, int x, int y)
{
	std::ostringstream ss;
	ss << lvl;
	text.setString(ss.str());
	text.setPosition(x, y);
	win->draw(text);
}
//1 - home, 2 - forest, 3 - city, 4 - tunnels
void Disp::dispLoc(sf::Texture &loc, sf::Sprite &s, int parameter)
{
	if (parameter == 1) loc.loadFromFile("home.png");
	if (parameter == 2) loc.loadFromFile("forest.png");
	if (parameter == 3) loc.loadFromFile("city.png");
	if (parameter == 4) loc.loadFromFile("tunnels.png");
	s.setTexture(loc);
	s.setPosition(17, 35);
	win->draw(s);
}
void Disp::dispWeapon(sf::Texture &w, sf::Sprite &s, sf::Text &text, int parameter, weapon* displayed_weapon)
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
void Disp::dispHours(sf::Text &text, int hours)
{
	std::ostringstream ss;
	ss << hours;
	text.setString(ss.str());
	text.setPosition(592, 541);
	win->draw(text);
}
void Disp::dispChoice(sf::Text &text, int parameter)
{
	if (parameter == 2) text.setString("forest");
	if (parameter == 3) text.setString("city");
	if (parameter == 4) text.setString("tunnels");
	text.setPosition(592, 501);
	win->draw(text);
}

void Disp::dispSentence(sf::Text &text, std::vector <std::string> &sentence)
{
	if (sentence.size()>10){
		sentence.erase(sentence.begin());
	}

	for (int i = 0; i<sentence.size(); i++)
	{
		std::ostringstream s2;
		s2 << sentence[i];
		text.setString(s2.str());
		text.setPosition(432, 19 + (i * 20));
		win->draw(text);
	}
}

void Disp::dispButton(sf::Sprite &image, sf::Event *zdarzenie, int value, int *parameter, int sign)
{
	if (CorrectM(image))
	{
		win->draw(image);
		if (zdarzenie->type == sf::Event::MouseButtonPressed && zdarzenie->mouseButton.button == sf::Mouse::Left)
		{
			if (*parameter*sign<value*sign) *parameter = *parameter + sign;
			Sleep(70);
		}
	}
}
void Disp::dispTime(sf::Text &textH, sf::Text &textM, int hours, int minutes)
{
	std::ostringstream Hours;
	std::ostringstream Minutes;
	Hours << hours;
	Minutes << minutes;
	if (minutes == 0) Minutes << 00;
	textH.setString(Hours.str());
	textM.setString(Minutes.str());
	textH.setPosition(30, 181);
	textM.setPosition(71, 181);
	win->draw(textH);
	win->draw(textM);
}



void Disp::dispThing(sf::Sprite &image, sf::Event *zdarzenie, std::vector <std::string> &sentence, std::string com)
{
	if (CorrectM(image))
	{
		win->draw(image);
		std::ostringstream ss;
		ss << com;
		if (zdarzenie->type == sf::Event::MouseButtonPressed && zdarzenie->mouseButton.button == sf::Mouse::Left)
		{
			sentence.push_back(ss.str());
			Sleep(100);
		}
	}
}

void Disp::SetFont(sf::Text &text,sf::Font &font,int size){
	text.setFont(font);
	text.setCharacterSize(size);
	text.setColor(sf::Color::White);
}