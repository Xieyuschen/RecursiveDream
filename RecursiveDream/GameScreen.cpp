#include "GameScreen.h"
using namespace Dreamer;
GameScreen::GameScreen() {
	Block b(sf::Color::White, sf::Vector2f(0, 0), sf::Vector2f(100, 20));
	blocks.push_back(b);
}
void GameScreen::handleInput(sf::RenderWindow& window) {
	wizard_.handleInput(window);
}
void GameScreen::update(sf::Time delta) {
	wizard_.update(delta);
}
void GameScreen::render(sf::RenderWindow& window) {
	for (auto item : blocks) {
		item.render(window);
	}
	wizard_.render(window);
}