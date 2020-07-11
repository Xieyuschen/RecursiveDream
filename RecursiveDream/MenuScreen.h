#pragma once
#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include<SFML/Graphics.hpp>
#include"Screen.h"
class MenuScreen:public Screen 
{
public:
	MenuScreen();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;

private:
	
	sf::Font font_;
	sf::Text title_;
	sf::Text text_;
};

#endif

