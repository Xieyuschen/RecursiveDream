#include "Wizard.h"
#include"Game.h"
#include<SFML/Graphics.hpp>
using namespace Dreamer;
Wizard::Wizard() 
{
	position_ = sf::Vector2f(0,380);
	direction_ = Direction::Right;
	rec_.setPosition(position_);
	rec_.setSize(sf::Vector2f(Wizard_Width, Wizard_Height));
	rec_.setOutlineColor(sf::Color::Green);
	rec_.setOutlineThickness(-1.f);
}
void Wizard::move() {

}
void Wizard::render(sf::RenderWindow& window) {
	//this function maybe useless
	window.clear();
	window.draw(rec_);
	window.display();
}
void Wizard::handleInput(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction_ = Direction::Left;
		position_.x -= Wizard_Width;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction_ = Direction::Right;
		position_.x += Wizard_Height;
	}
	rec_.setPosition(position_);

}
void Wizard::update(sf::Time delta) {
	move();
}