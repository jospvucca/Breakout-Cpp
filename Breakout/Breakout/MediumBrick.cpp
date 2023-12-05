#include "MediumBrick.h"
#include <string>

MediumBrick::MediumBrick(Game& game) : Collidable(game) {

}

MediumBrick::MediumBrick(const std::string& id, const std::string& texture,
	const int hitpoints, const std::string& hitSound,
	const std::string& breakSound, const int breakPoints, Game& game) :
	Brick(id, texture, hitpoints, hitSound, breakSound, breakPoints),
	Collidable(game) {
	std::cout << "---> MediumBrick::ctor(Id: " + id + ", Texture: " + texture +
		", Hitpoints: " + std::to_string(hitpoints) + ", HitSound: " + hitSound +
		", BreakSound: " + breakSound + ", BreakPoints: " + std::to_string(breakPoints) + ")." << std::endl;

	this->id = id;
	this->texture = texture;
	this->hitpoints = hitpoints;
	this->hitSound = hitSound;
	this->breakSound = breakSound;
	this->breakScore = breakPoints;
}

std::unique_ptr<Brick> MediumBrick::clone(Game& game) const {
	return std::make_unique<MediumBrick>(*this);
}

void MediumBrick::displayInfo() const {
	std::cout << "Medium Brick info...(TODO)" << std::endl;
}

void MediumBrick::createCollidable(int x, int y, int w, int h, SDL_Color&& color) {
	std::cout << "---> MediumBrick::createCollidable ---> Creating visual data for MediumBrick..." << std::endl;
	Collidable::setX(x);
	Collidable::setY(y);
	Collidable::setWidth(w);
	Collidable::setHeight(h);
	Collidable::setColor({0, 0, 255, 255});
}

void MediumBrick::render(SDL_Renderer& renderer) const {
	std::cout << "---> MediumBrick::render ---> Rendering visual data for MediumBrick..." << std::endl;
	Collidable::render(renderer);
}