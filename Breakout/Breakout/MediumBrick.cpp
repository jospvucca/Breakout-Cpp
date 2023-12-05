#include "MediumBrick.h"
#include <string>

MediumBrick::MediumBrick(Game& game) : Collidable(game) {

}

MediumBrick::~MediumBrick() {
	Collidable::~Collidable();
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

std::unique_ptr<Brick> MediumBrick::clone(Game& game) {
	BrickData brickData;
	for (int i = 0; i < game.getParseData().bricks.size(); i++) {
		if (game.getParseData().bricks.at(i).id.starts_with('M')) {
			brickData = game.getParseData().bricks.at(i);
		}
	}

	this->id = brickData.id;
	this->texture = brickData.texture;
	this->hitpoints = brickData.hitpoints;
	this->hitSound = brickData.breakSound;
	this->breakSound = brickData.breakSound;
	this->breakScore = brickData.breakScore;

	return std::make_unique<MediumBrick>(*this);
}

void MediumBrick::displayInfo() const {
	std::cout << "Medium Brick info...(TODO)" << std::endl;
}

void const MediumBrick::decreaseHitpoints() {
	hitpoints.value()--;

	if (hitpoints.value() <= 0) {
		this->~MediumBrick();
	}
}

void MediumBrick::createCollidable(int x, int y, int w, int h, SDL_Color&& color) {
	std::cout << "---> MediumBrick::createCollidable ---> Creating visual data for MediumBrick..." << std::endl;
	Collidable::setX(x);
	Collidable::setY(y);
	Collidable::setWidth(w);
	Collidable::setHeight(h);
	Collidable::setColor({0, 0, 255, 255});
}

const Collidable& MediumBrick::getCollidable() const {
	return *this;
}

void MediumBrick::render(SDL_Renderer& renderer) const {
	//std::cout << "---> MediumBrick::render ---> Rendering visual data for MediumBrick..." << std::endl;
	Collidable::render(renderer);
}