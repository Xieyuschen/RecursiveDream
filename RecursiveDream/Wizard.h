#pragma once
#ifndef WIZRD_H
#define WIZRD_H
#include<SFML/Graphics.hpp>
#include"Block.h"
namespace Dreamer {

	enum class Direction {
		Left,Right,Up,Down
	};
	enum class State {
		Jumping,Falling,Grounding
	};
	class Wizard
	{
	public:
		const int LevelSpeed=8;
		const int VertialSpeed=10;
		const int Wizard_Width=10;
		const int Wizard_Height=10;
		const int JumpCycleTimes = 10;
		const int JumpDistance = Wizard_Height*2;
	public:
		void update(sf::Time delta);
		void render(sf::RenderWindow& window);
		void handleInput(sf::RenderWindow& window);
		bool CheckBoundary(int y);
		//void AddBlock(Block block);
		sf::Vector2f position_;
		//Wizard& operator=(Wizard& w);
		Wizard();

		//they're wrap in another class and never exposed to user
	public:
		//when move left or right,we can use just one cycle to accomplete it.
		void move();
		State state_;
		int lefttime = -1;
		Direction direction_;
		sf::RectangleShape rec_;
		sf::Texture tex_;

	};

}

#endif // !WIZRD+H

