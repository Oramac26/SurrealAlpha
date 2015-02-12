#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Credits.hpp"

int CreditsScr::Run(sf::RenderWindow &win)
{
	sf::Texture obr1;
	obr1.loadFromFile( "Creditsbg.png" );

	sf::Sprite bg;
	bg.setTexture(obr1);


	bool Running = true;
	sf::Event zdarzenie;
	while (Running){

		while (win.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::Escape) return (0);
			if (zdarzenie.type == sf::Event::Closed)
			{
				return (-1);
			}
		}

		win.draw(bg);
		win.display();
	}

	return (-1);
}