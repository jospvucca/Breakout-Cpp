#include "SoftBrick.h"
#include <string>

SoftBrick::SoftBrick(Game& game) : Collidable(game) {

}

SoftBrick::SoftBrick(const std::string& id, const std::string& texture,
	const int hitpoints, const std::string& hitSound,
	const std::string& breakSound, const int breakPoints, Game& game) :
	Brick(id, texture, hitpoints, hitSound, breakSound, breakPoints),
	Collidable(game) {
	std::cout << "---> SoftBrick::ctor(Id: " + id + ", Texture: " + texture +
		", Hitpoints: " + std::to_string(hitpoints) + ", HitSound: " + hitSound +
		", BreakSound: " + breakSound + ", BreakPoints: " + std::to_string(breakPoints) + ")." << std::endl;

	this->id = id;
	this->texture = texture;
	this->hitpoints = hitpoints;
	this->hitSound = hitSound;
	this->breakSound = breakSound;
	this->breakScore = breakPoints;
}

std::unique_ptr<Brick> SoftBrick::clone(Game& game) const {
	return std::make_unique<SoftBrick>(*this);
}

void SoftBrick::displayInfo() const {
	std::cout << "Soft Brick info...(TODO)" << std::endl;
}

void SoftBrick::createCollidable(int x, int y, int w, int h, SDL_Color&& color) {
	std::cout << "---> SoftBrick::createCollidable ---> Creating visual data for SoftBrick..." << std::endl;
	Collidable::setX(x);
	Collidable::setY(y);
	Collidable::setWidth(w);
	Collidable::setHeight(h);
	Collidable::setColor({0, 255, 0 , 255});
}

void SoftBrick::render(SDL_Renderer& renderer) const {
	std::cout << "---> SoftBrick::render ---> Rendering visual data for SoftBrick..." << std::endl;
	Collidable::render(renderer);
}