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
	if (direction_ == Direction::Right) {
		int nextplace = position_.x + Wizard_Width;
		bool flag = true;
		for (auto item : blocks_) {
			if (item.color_ != GColor) {

				flag = item.ChenkPosition(sf::Vector2f(nextplace, position_.y));
				if (!flag)break;
			}
		}
		if (flag) {
			position_.x = nextplace;
		}
	}
	if (direction_ == Direction::Left) {
		int nextplace = position_.x - Wizard_Width;
		bool flag = true;
		for (auto item : blocks_) {
			if (item.color_ != GColor) {

				flag = item.ChenkPosition(sf::Vector2f(nextplace, position_.y));
				if (!flag)break;
			}
		}
		if (flag) {
			position_.x = nextplace;
		}
	}
	if (state_ == State::Jumping && lefttime > 0) {
		int nextpalce= position_.y - JumpDistance;
		bool flag = true;
		for (auto item : blocks_) {
			if (item.color_ != GColor) {
				flag = item.ChenkPosition(sf::Vector2f(position_.x, nextpalce));
				if (!flag)break;
			}

		}
		if (flag) {
			--lefttime;
			position_.y = nextpalce;
		}
		else
		{
			state_ = State::Falling;
		}
		if (lefttime == 0) {
			state_ = State::Falling;
		}
	}
	if (state_ == State::Falling) {
		int temp = position_.y + JumpDistance;
		int nextpalce = position_.y + JumpDistance;
		bool flag = true;
		for (auto item : blocks_) {
			if (item.color_ != GColor) {
				flag = item.ChenkPosition(sf::Vector2f(position_.x, nextpalce));
				if (!flag)break;
			}

		}
		if (flag) {
			position_.y = nextpalce;
		}
		else {
			state_ = State::Grounding;
		}
		if (CheckBoundary(temp)) {
			position_.y = temp;
		}
		else
		{
			state_ = State::Grounding;
		}

	}
}
void Wizard::render(sf::RenderWindow& window) {
	//this function maybe useless
	//window.clear();
	for (auto item : blocks_) {
		item.render(window);
	}
	rec_.setTexture(&tex_);
	window.draw(rec_);
	//window.display();
}
void Wizard::handleInput(sf::RenderWindow& window) {
	move();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction_ = Direction::Left;
		position_.x -= Wizard_Width;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction_ = Direction::Right;
		//position_.x += Wizard_Height;
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
}
bool Wizard::CheckBoundary(int y) {
	if (y >= 450) {
		return false;
	}
	return true;
}
void Wizard::AddBlock(Block block) {
	blocks_.push_back(block);
}
Wizard& Wizard::operator=(Wizard& w) {
	Wizard temp(w);
	return temp;
}
