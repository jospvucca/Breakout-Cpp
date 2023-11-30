#include "Collidable.h"

Collidable::Collidable(Game& game) : Drawable(game), enabled(true), cbX(0), cbY(0) {
	std::cout << "---> Collidable:ctor(game) ---> Creating a Collidable Object." << std::endl;
}

bool Collidable::onCollision(const Collidable& other) const {
	std::cout << "Collidable::onCollision ---> TODO" << std::endl;

	return true;
}

void Collidable::setX(const int x) {
	std::cout << "---> Collidable::setX ---> TODO" << std::endl;
}

void Collidable::setY(const int y) {
	std::cout << "---> Collidable::setY ---> TODO" << std::endl;
}

void Collidable::setWidth(const int width) {
	std::cout << "---> Collidable::setWidth ---> TODO" << std::endl;
}

void Collidable::setHeight(const int height) {
	std::cout << "---> Collidable::setHeight ---> TODO" << std::endl;
}