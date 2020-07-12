#include "GameScreen.h"
using namespace Dreamer;
GameScreen::GameScreen() {

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