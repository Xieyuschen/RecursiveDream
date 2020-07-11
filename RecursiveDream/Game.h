#pragma once
#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Screen.h"
namespace Dreamer {
	class Game
	{
	public:
		static const int Width = 640;
		static const int Height = 480;
		Game();
		void run();

		void handleInput();
		void update(sf::Time delta);
		void render();

		static std::shared_ptr<Screen> Screen;

	private:
		sf::RenderWindow window_;
		static const sf::Time TimePerFrame;

	};
}


#endif // !GAME_H


