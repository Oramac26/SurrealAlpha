#ifndef CSCREEN_HPP_INCLUDED
#define CSCREEN_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class cScreen
{
public:
	virtual int Run(sf::RenderWindow &win) = 0;
};

#endif