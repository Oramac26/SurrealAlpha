#ifndef CREDITS_HPP_INCLUDED
#define CREDITS_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class CreditsScr :public cScreen{
public:
	virtual int Run(sf::RenderWindow &win);
};

#endif