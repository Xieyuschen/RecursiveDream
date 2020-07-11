#include "Wizard.h"
#include"Game.h"
#include<SFML/Graphics.hpp>
using namespace Dreamer;
Wizard::Wizard() 
{
	position_ = sf::Vector2f(0, Game::Height);
	direction_ = Direction::Right;
	rec_.setPosition(position_);
	rec_.setSize(sf::Vector2f(Wizard_Width, Wizard_Height));
	rec_.setOutlineColor(sf::Color::Green);
	rec_.setOutlineThickness(-1.f);
}
void Wizard::move() {
	if (direction_ == Direction::Left) {
		if (position_.x - Wizard_Width > 0) {
			position_.x -= Wizard_Width;
		}
	}
	if (direction_ == Direction::Right) {
		if (position_.x + Wizard_Width)
			position_.x += Wizard_Width;
	}
}
void Wizard::render(sf::RenderWindow& window) {
	window.draw(rec_);
	window.display();
}
void Wizard::handleInput(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction_ = Direction::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction_ = Direction::Right;
	}
}
void Wizard::update(sf::Time delta) {
	move();
}