#pragma once
#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include"Screen.h"
#include"Wizard.h"
#include"Block.h"
#include<vector>
namespace Dreamer {

	class GameScreen:public Screen
	{
	public:
		GameScreen();
		void handleInput(sf::RenderWindow& window) override;
		void update(sf::Time delta) override;
		void render(sf::RenderWindow& window) override;
	private:
		Wizard currentwizard_;
		std::vector<Wizard> wizards_;
		int currentnum = 0;
	}; 
}
#endif // !GAMESCREEN_H 

