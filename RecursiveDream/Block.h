#pragma once
#ifndef BLOCK_H
#define BLOCK_H
#include<SFML/Graphics.hpp>

namespace Dreamer {
	class Block
	{
	public:
		void render(sf::RenderWindow& window);
		Block(sf::Color color, sf::Vector2f position, sf::Vector2f large);

		//if the position input is emited in block,return false
		bool ChenkPosition(sf::Vector2f position);
	public:
		sf::Color color_;
		sf::Vector2f position_;
		//first refers to width,second is height
		sf::Vector2f large_;
		sf::RectangleShape rec_;
	};
}
#endif // !BLOCK_H



