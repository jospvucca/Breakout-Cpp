#include "Collidable.h"

Collidable::Collidable(Game& game) :
	Drawable(game),
	enabled(true),
	extendedX(0),
	extendedY(0),
	cbX(0),
	cbY(0) {
	std::cout << "---> Collidable:ctor(game) ---> Creating a Collidable Object." << std::endl;
}

Collidable::~Collidable() {
	Drawable::~Drawable();
}

bool Collidable::onCollision(const Collidable& other) const {
	//std::cout << "Collidable::onCollision ---> TODO" << std::endl;

	if (!this->enabled && !other.enabled) {
		std::cout << "---> Collidable::onCollision ---> Object is not enabled." << std::endl;
		return false;
	}

	//auto test1 = cbX;
	//auto test2 = other.cbX;
	//auto test3 = cbX - other.cbX;
	//auto test4 = extendedX;
	//auto test5 = other.extendedX;
	//auto test6 = test4 + test5;

	bool x = std::abs(cbX - other.cbX) < (extendedX + other.extendedX);
	bool y = std::abs(cbY - other.cbY) < (extendedY + other.extendedY);

	return x && y;
}

void Collidable::setX(const int x) {
	std::cout << "---> Collidable::setX ---> TODO" << std::endl;
	cbX -= (rect.x - x);
	Object::setX(x);
}

void Collidable::setY(const int y) {
	std::cout << "---> Collidable::setY ---> TODO" << std::endl;
	cbY -= (rect.y - y);
	Object::setY(y);
}

void Collidable::setWidth(const int width) {
	std::cout << "---> Collidable::setWidth ---> TODO" << std::endl;
	extendedX = width / 2;
	cbX = rect.x + extendedX;
	Object::setWidth(width);
}

void Collidable::setHeight(const int height) {
	std::cout << "---> Collidable::setHeight ---> TODO" << std::endl;
	extendedY = height / 2;
	cbY = rect.y + extendedY;
	Object::setHeight(height);
}