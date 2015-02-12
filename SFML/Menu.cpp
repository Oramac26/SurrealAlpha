#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Menu.hpp"

#define TIME 220

bool MenuScr::CorrectM(sf::Sprite &s, const sf::RenderWindow &w)
{
	if (
		sf::Mouse::getPosition(w).x > s.getGlobalBounds().left &&
		sf::Mouse::getPosition(w).y > s.getGlobalBounds().top &&
		sf::Mouse::getPosition(w).x < s.getGlobalBounds().left + s.getGlobalBounds().width &&
		sf::Mouse::getPosition(w).y < s.getGlobalBounds().top + s.getGlobalBounds().height
		)
		return 1;
	else
		return 0;
}

MenuScr::MenuScr(){
	options = false;
	mus = true;
	playing = false;
};

int MenuScr::Run(sf::RenderWindow &win){

	bool Running = true;

	sf::Texture obr1, obr2, obr3, obr4, obr5, obr6, obr7, obr8, obr9, obr10, obr11, obr12, obr13, obr14;
	obr1.loadFromFile("bg.jpg");
	obr2.loadFromFile("NewGame.png");
	obr3.loadFromFile("LoadGame.png");
	obr4.loadFromFile("Credits.png");
	obr5.loadFromFile("Exit.png");
	obr6.loadFromFile("Creditscl.png");
	obr7.loadFromFile("NewGamecl.png");
	obr8.loadFromFile("LoadGamecl.png");
	obr9.loadFromFile("Exitcl.png");
	obr10.loadFromFile("optionsnclc.png");
	obr11.loadFromFile("optionsclc.png");
	obr12.loadFromFile("Music.png");
	obr13.loadFromFile("ON.png");
	obr14.loadFromFile("OFF.png");

	sf::Sprite bg, newgame, load, cred, exit, credcl, newgamecl, loadcl, exitcl, opt, optcl, music, on, off;

	bg.setTexture(obr1);
	newgame.setTexture(obr2);
	load.setTexture(obr3);
	cred.setTexture(obr4);
	exit.setTexture(obr5);
	credcl.setTexture(obr6);
	newgamecl.setTexture(obr7);
	loadcl.setTexture(obr8);
	exitcl.setTexture(obr9);
	opt.setTexture(obr10);
	optcl.setTexture(obr11);
	music.setTexture(obr12);
	on.setTexture(obr13);
	off.setTexture(obr14);

	sf::SoundBuffer soundbuffer;
	sf::Music bgsound;
	bgsound.openFromFile("Soundtrack.wav");
	bgsound.setVolume(60);
	bgsound.play();
	bgsound.setPlayingOffset(sf::seconds(TIME));

	while (Running){

		while (win.isOpen())
		{
			sf::Event zdarzenie;
			while (win.pollEvent(zdarzenie))
			{
				if (zdarzenie.type == sf::Event::Closed)
				{
					return (-1);
				}
			}
			win.clear(sf::Color::Transparent);

			newgame.setPosition(100, 350);
			load.setPosition(100, 410);
			opt.setPosition(100, 470);
			cred.setPosition(100, 530);
			exit.setPosition(100, 590);
			newgamecl.setPosition(100, 350);
			loadcl.setPosition(100, 410);
			optcl.setPosition(100, 470);
			credcl.setPosition(100, 530);
			exitcl.setPosition(100, 590);

			on.setPosition(616, 305);
			off.setPosition(731, 305);

			win.draw(bg);
			win.draw(newgame);
			win.draw(load);
			win.draw(opt);
			win.draw(cred);
			win.draw(exit);

			if (options == true) {
				win.draw(music);

				if (CorrectM(on, win) && (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left)) {
					mus = true;
					bgsound.play();
				}
				if (CorrectM(off, win) && (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left)) {
					bgsound.pause();
					mus = false;
				}
				if (mus == true) win.draw(on);
				else win.draw(off);

				if (zdarzenie.type == sf::Event::KeyReleased && zdarzenie.key.code == sf::Keyboard::Escape) options = false;
			}
			else{
				if (CorrectM(newgame, win)) {
					win.draw(newgamecl);
					if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left)
					{
						return (1);
					}
				}
				if (CorrectM(load, win)) {
					win.draw(loadcl);
				}
				if (CorrectM(opt, win)) {
					win.draw(optcl);
					if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left) options = true;
				}
				if (CorrectM(cred, win)) {
					win.draw(credcl);
					if (zdarzenie.type == sf::Event::MouseButtonReleased && zdarzenie.mouseButton.button == sf::Mouse::Left)
					{
						return (2);
					}
				}
				if (CorrectM(exit, win)) {
					win.draw(exitcl);
					if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left) return (-1);
				}
			}
			win.display();
		}
	}
	return (-1);
}