#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuScr :public cScreen
{
private:
	bool options, mus, playing;
public:
	MenuScr();
	virtual int Run(sf::RenderWindow &win);
	bool CorrectM(sf::Sprite &s, const sf::RenderWindow &w);
};

#endif