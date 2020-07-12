#include "Block.h"
using namespace Dreamer;
Block::Block(sf::Color color, sf::Vector2f position, sf::Vector2f large)
	:color_(color), position_(position), large_(large),rec_(large_) {
	rec_.setPosition(position_);
	rec_.setFillColor(color_);
}
void Block::render(sf::RenderWindow& window) {
	window.draw(rec_);

}

bool Block::ChenkPosition(sf::Vector2f position) {
	if (position.x > position_.x && position.x<position_.x + large_.x
		&& position.y>position_.y && position.y < position_.y + large_.y) {
		return false;
	}
	else return true;
}