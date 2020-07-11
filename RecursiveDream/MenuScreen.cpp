#include "MenuScreen.h"
#include"Game.h"
MenuScreen::MenuScreen() 
{
	font_.loadFromFile("Fonts/game.ttf");
	text_.setFont(font_);
	text_.setString("\n\n\n\n\n\n\n\n\nPress[SPACE] to play"
		"\n\n[D] to learm more");
	title_.setFont(font_);
	title_.setString("CycleDreamer");
	title_.setFillColor(sf::Color::Green);
	title_.setCharacterSize(32);
	title_.setStyle(sf::Text::Bold);

	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	text_.setPosition(Game::Width / 2, Game::Height / 2);

	sf::FloatRect titleBounds = title_.getLocalBounds();
	title_.setOrigin(titleBounds.left + titleBounds.width / 2,
		titleBounds.top + titleBounds.height / 2);
	title_.setPosition(Game::Width / 2, Game::Height / 4);
}
void MenuScreen::render(sf::RenderWindow& window) {
	//when render something,draw or display?
	//I guess draw
	window.draw(title_);
	window.draw(text_);
}
void MenuScreen::handleInput(sf::RenderWindow& window) {

}
void MenuScreen::update(sf::Time delta) {

}