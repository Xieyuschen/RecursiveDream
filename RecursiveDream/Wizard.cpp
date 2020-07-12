#include "Wizard.h"
#include"Game.h"
#include<SFML/Graphics.hpp>
using namespace Dreamer;
Wizard::Wizard() 
{
	position_ = sf::Vector2f(0,380);
	direction_ = Direction::Right;
	state_ = State::Grounding;
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
	if (state_ == State::Jumping && lefttime > 0) {
		position_.y -= JumpDistance;
		--lefttime;
		if (lefttime == 0) {
			state_ = State::Falling;
		}
	}
	if (state_ == State::Falling) {
		int temp= position_.y + JumpDistance;
		if (CheckBoundary(temp)) {
			position_.y = temp;
		}
		else
		{
			state_ = State::Grounding;
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction_ = Direction::Left;
		position_.x -= Wizard_Width;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction_ = Direction::Right;
		position_.x += Wizard_Height;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (state_ == State::Grounding) {
			state_ = State::Jumping;
			lefttime = JumpCycleTimes;
			position_.y -= JumpDistance;
			--lefttime;
		}
	}
	rec_.setPosition(position_);

}
void Wizard::update(sf::Time delta) {
	move();
}
bool Wizard::CheckBoundary(int y) {
	if (y >= 450) {
		return false;
	}
	return true;
}