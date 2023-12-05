#include "HardBrick.h"
#include <string>

HardBrick::HardBrick(Game& game) : Collidable(game) {

}

HardBrick::HardBrick(const std::string& id, const std::string& texture,
	const int hitpoints, const std::string& hitSound,
	const std::string& breakSound, const int breakPoints,
	Game& game) :
	Brick(id, texture, hitpoints, hitSound, breakSound, breakPoints), 
	Collidable(game) {
	std::cout << "---> HardBrick::ctor(Id: " + id + ", Texture: " + texture +
		", Hitpoints: " + std::to_string(hitpoints) + ", HitSound: " + hitSound +
		", BreakSound: " + breakSound + ", BreakPoints: " + std::to_string(breakPoints) + ")." << std::endl;

	this->id = id;
	this->texture = texture;
	this->hitpoints = hitpoints;
	this->hitSound = hitSound;
	this->breakSound = breakSound;
	this->breakScore = breakPoints;
}

std::unique_ptr<Brick> HardBrick::clone(Game& game) const {
	return std::make_unique<HardBrick>(*this);
}

void HardBrick::displayInfo() const {
	std::cout << "---> Hard Brick info...(TODO)" << std::endl;
}

void HardBrick::createCollidable(int x, int y, int w, int h, SDL_Color&& color) {
	std::cout << "---> HardBrick::createCollidable ---> Creating visual data for HardBrick..." << std::endl;
	Collidable::setX(x);
	Collidable::setY(y);
	Collidable::setWidth(w);
	Collidable::setHeight(h);
	Drawable::setColor({255, 0, 0, 255});
}

void HardBrick::render(SDL_Renderer& renderer) const {
	std::cout << "---> HardBrick::render ---> Rendering visual data for HardBrick..." << std::endl;
	Drawable::render(renderer);
}