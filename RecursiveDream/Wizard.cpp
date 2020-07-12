#include "Wizard.h"
#include"Game.h"
#include<SFML/Graphics.hpp>
#include"Block.h"
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

	Block b1(sf::Color::White, sf::Vector2f(200,400 ), sf::Vector2f(100, 30));
	Block b2(sf::Color::White, sf::Vector2f(300, 300), sf::Vector2f(100, 30));

	Block b3(sf::Color::White, sf::Vector2f(400,200 ), sf::Vector2f(100, 30));

	blocks.push_back(b1);
	blocks.push_back(b2);
	blocks.push_back(b3);
}
void Wizard::move() {
	if (state_ == State::Jumping && lefttime > 0) {
		int nextpalce= position_.y - JumpDistance;
		bool flag = true;
		for (auto item : blocks) {
			flag = item.ChenkPosition(sf::Vector2f(position_.x, nextpalce));
			if (!flag)break;
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
		for (auto item : blocks) {
			flag = item.ChenkPosition(sf::Vector2f(position_.x, nextpalce));
			if (!flag)break;
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
	for (auto item : blocks) {
		item.render(window);
	}
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		sf::RectangleShape rec(sf::Vector2f(680, 480));
		rec.setFillColor(sf::Color::White);
		window.draw(rec);
		window.display();
	}
}
void Wizard::update(sf::Time delta) {
}
bool Wizard::CheckBoundary(int y) {
	if (y >= 450) {
		return false;
	}
	return true;
}