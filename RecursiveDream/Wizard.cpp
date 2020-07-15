#include "Wizard.h"
#include"Game.h"
#include<SFML/Graphics.hpp>
#include"Block.h"
#include"Game.h"
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
	tex_.loadFromFile("../Images/Rperson.png");
}
void Wizard::move() {
}
void Wizard::render(sf::RenderWindow& window) {
	//this function maybe useless
	//window.clear();
	rec_.setTexture(&tex_);
	window.draw(rec_);
	//window.display();
}
void Wizard::handleInput(sf::RenderWindow& window) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction_ = Direction::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction_ = Direction::Right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (state_ == State::Grounding) {
			state_ = State::Jumping;
			lefttime = JumpCycleTimes;
		}
	}
	//本函数只处理了输入的内容，不对其他的做任何修改
	/*rec_.setPosition(position_);*/
	
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

