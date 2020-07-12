#include "GameScreen.h"
using namespace Dreamer;
GameScreen::GameScreen() {

	Block b1(sf::Color::White, sf::Vector2f(200, 400), sf::Vector2f(100, 30));
	Block b2(sf::Color::White, sf::Vector2f(300, 300), sf::Vector2f(100, 30));

	Block b3(sf::Color::White, sf::Vector2f(400, 200), sf::Vector2f(100, 30));
	Block b4(sf::Color::Black, sf::Vector2f(500, 100), sf::Vector2f(100, 30));
	wizard_.AddBlock(b1);
	wizard_.AddBlock(b2);
	wizard_.AddBlock(b3);
	wizard_.AddBlock(b4);
}
void GameScreen::handleInput(sf::RenderWindow& window) {
	wizard_.handleInput(window);
}
void GameScreen::update(sf::Time delta) {
	wizard_.update(delta);
}
void GameScreen::render(sf::RenderWindow& window) {
	
	wizard_.render(window);
}