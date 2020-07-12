#include "GameScreen.h"
using namespace Dreamer;
GameScreen::GameScreen() {
	Wizard w2;
	Block b0(sf::Color::White, sf::Vector2f(300, 100), sf::Vector2f(30, 800));
	Block b1(sf::Color::White, sf::Vector2f(100, 350), sf::Vector2f(100, 30));
	Block b2(sf::Color::White, sf::Vector2f(300, 300), sf::Vector2f(100, 30));
	Block b3(sf::Color::White, sf::Vector2f(300, 200), sf::Vector2f(100, 30));

	Block b4(sf::Color::Black, sf::Vector2f(500, 250), sf::Vector2f(100, 30));
	Block b5(sf::Color::Black , sf::Vector2f(500, 150), sf::Vector2f(100, 30));
	w2.AddBlock(b0);

	currentwizard_.AddBlock(b1);
	currentwizard_.AddBlock(b2);

	currentwizard_.AddBlock(b3);
	currentwizard_.AddBlock(b4);
	currentwizard_.AddBlock(b5);


	wizards_.push_back(w2);
	wizards_.push_back(currentwizard_);

}
void GameScreen::handleInput(sf::RenderWindow& window) {
	wizards_[currentnum].handleInput(window);
}
void GameScreen::update(sf::Time delta) {
	wizards_[currentnum].update(delta);
}
void GameScreen::render(sf::RenderWindow& window) {
	//Come to the next level
	if (wizards_[currentnum].position_.x > 600) {
		++currentnum;
	}
	wizards_[currentnum].render(window);
}