#include "GameScreen.h"
#include"Game.h"

using namespace Dreamer;
GameScreen::GameScreen() {

	Block b0(sf::Color::White, sf::Vector2f(300, 100), sf::Vector2f(30, 800));
	Block b1(sf::Color::White, sf::Vector2f(100, 350), sf::Vector2f(100, 30));
	Block b2(sf::Color::White, sf::Vector2f(300, 300), sf::Vector2f(100, 30));
	Block b3(sf::Color::White, sf::Vector2f(300, 200), sf::Vector2f(100, 30));

	Block fin1(sf::Color::Cyan, sf::Vector2f(500, 0), sf::Vector2f(100, 100));
	Block b4(sf::Color::Black, sf::Vector2f(400, 250), sf::Vector2f(100, 30));
	Block b5(sf::Color::Black , sf::Vector2f(400, 150), sf::Vector2f(100, 30));

	blocks_.push_back(b1);
	blocks_.push_back(b2);
	blocks_.push_back(b3);
	blocks_.push_back(b4);


}
void GameScreen::handleInput(sf::RenderWindow& window) {
	wizard_.handleInput(window);
}
void GameScreen::update(sf::Time delta) {
	move();
	wizard_.update(delta);

}
void GameScreen::move() {

	if (wizard_.direction_ == Direction::Right) {
		int nextplace = wizard_.position_.x + wizard_.Wizard_Width;
		bool flag = true;
		for (auto item : blocks_) {
			if (item.color_ != GColor) {
				flag = item.ChenkPosition(sf::Vector2f(nextplace,wizard_.position_.y));
				if (!flag)break;
			}
		}
		if (flag) {
			wizard_.position_.x = nextplace;
		}
	}
	if (wizard_.direction_ == Direction::Left) {
		int nextplace = wizard_.position_.x - wizard_.Wizard_Width;
		bool flag = true;
		for (auto item : blocks_) {
			if (item.color_ != GColor) {

				flag = item.ChenkPosition(sf::Vector2f(nextplace, wizard_.position_.y));
				if (!flag)break;
			}
		}
		if (flag) {
			wizard_.position_.x = nextplace;
		}
	}
	if (wizard_.state_ == State::Jumping && wizard_.lefttime > 0) {
		int nextpalce = wizard_.position_.y - wizard_.JumpDistance;
		bool flag = true;
		for (auto item : blocks_) {
			if (item.color_ != GColor) {
				flag = item.ChenkPosition(sf::Vector2f(wizard_.position_.x, nextpalce));
				if (!flag)break;
			}

		}
		if (flag) {
			--wizard_.lefttime;
			wizard_.position_.y = nextpalce;
		}
		else
		{
			wizard_.state_ = State::Falling;
		}
		if (wizard_.lefttime == 0) {
			wizard_.state_ = State::Falling;
		}
	}
	if (wizard_.state_ == State::Falling) {
		int temp = wizard_.position_.y + wizard_.JumpDistance;
		int nextpalce = wizard_.position_.y + wizard_.JumpDistance;
		bool flag = true;
		for (auto item : blocks_) {
			if (item.color_ != GColor) {
				flag = item.ChenkPosition(sf::Vector2f(wizard_.position_.x, nextpalce));
				if (!flag)break;
			}

		}
		if (flag) {
			wizard_.position_.y = nextpalce;
		}
		else {
			wizard_.state_ = State::Grounding;
		}
		if (wizard_.CheckBoundary(temp)) {
			wizard_.position_.y = temp;
		}
		else
		{
			wizard_.state_ = State::Grounding;
		}

	}

	wizard_.rec_.setPosition(wizard_.position_);
}
void GameScreen::render(sf::RenderWindow& window) {
	//Come to the next level
	try {
		if (wizard_.position_.x > 600) {
			//Move into next game level
		}
		for (auto item : blocks_) {
			item.render(window);
		}
		wizard_.render(window);
	}
	catch(std::exception){
		window.close();
	}

}
void GameScreen::AddBlock(Block block) {
	blocks_.push_back(block);
}