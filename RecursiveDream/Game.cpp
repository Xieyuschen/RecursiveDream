#include "Game.h"
#include<SFML/Graphics.hpp>
#include"MenuScreen.h"
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
using namespace Dreamer;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 10.f);
std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();

Game::Game() :window_(sf::VideoMode(Width, Height), "ReDreamer") {}
void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{

		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}
		render();
	}
}
void Game::render() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (color_ == sf::Color::Black)
			color_ = sf::Color::White;
		else
			color_ = sf::Color::Black;

	}

	window_.clear(color_);

	Game::Screen->render(window_);
	window_.display();
}

void Game::handleInput() {
	sf::Event event;
	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}
	Game::Screen->handleInput(window_);
}

void Game::update(sf::Time delta) {
	Game::Screen->update(delta);
}