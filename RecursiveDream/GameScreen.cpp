#include "GameScreen.h"
using namespace Dreamer;
GameScreen::GameScreen() {
	Wizard w2;
	Block b0(sf::Color::White, sf::Vector2f(300, 100), sf::Vector2f(30, 800));

	currentwizard_.AddBlock(b0);

	wizards_.push_back(currentwizard_);
	wizards_.push_back(w2);
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