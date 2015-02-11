#ifndef CREDITS_HPP_INCLUDED
#define CREDITS_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class CreditsScr :public cScreen{
private:
	bool options, mus, playing;
public:
	virtual int Run(sf::RenderWindow &win);
};


int CreditsScr::Run(sf::RenderWindow &win)
{
	bool Running = true;





	return (-1);
}

#endif