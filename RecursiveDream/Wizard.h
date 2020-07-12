#pragma once
#ifndef WIZRD_H
#define WIZRD_H
#include<SFML/Graphics.hpp>
namespace Dreamer {

	enum class Direction {
		Left,Right,Up,Down
	};
	class Wizard
	{
		const int LevelSpeed=8;
		const int VertialSpeed=10;
		const int Wizard_Width=100;
		const int Wizard_Height=100;
	public:
		void update(sf::Time delta);
		void render(sf::RenderWindow& window);
		void handleInput(sf::RenderWindow& window);
		Wizard();
	private:
		//when move left or right,we can use just one cycle to accomplete it.
		void move();
		sf::Vector2f position_;
		Direction direction_;
		sf::RectangleShape rec_;
	};

}

#endif // !WIZRD+H

