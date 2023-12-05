#include "HardBrick.h"
#include <string>
#include <algorithm>

HardBrick::HardBrick(Game& game) : Collidable(game) {

}

HardBrick::~HardBrick() {
	Collidable::~Collidable();
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

std::unique_ptr<Brick> HardBrick::clone(Game& game) {

	BrickData brickData;
	for (int i = 0; i < game.getParseData().bricks.size(); i++) {
		if (game.getParseData().bricks.at(i).id.starts_with('H')) {
			//brickData = std::copy<BrickData>(game.getParseData().bricks.at(i));
			this->id = game.getParseData().bricks.at(i).id;
			this->texture = game.getParseData().bricks.at(i).texture;
			this->hitpoints = game.getParseData().bricks.at(i).hitpoints;
			this->hitSound = game.getParseData().bricks.at(i).breakSound;
			this->breakSound = game.getParseData().bricks.at(i).breakSound;
			this->breakScore = game.getParseData().bricks.at(i).breakScore;
		}
	}

	if (!brickData.hitpoints) {
		auto d = brickData;
	}

	//this->id = brickData.id;
	//this->texture = brickData.texture;
	//this->hitpoints = brickData.hitpoints;
	//this->hitSound = brickData.breakSound;
	//this->breakSound = brickData.breakSound;
	//this->breakScore = brickData.breakScore;

	return std::make_unique<HardBrick>(*this);
}

void HardBrick::displayInfo() const {
	std::cout << "---> Hard Brick info...(TODO)" << std::endl;
}

void const HardBrick::decreaseHitpoints() {
	hitpoints.value()--;
	std::cout << hitpoints.value() << std::endl;

	if (hitpoints.value() <= 0) {
		this->setColor({ 0, 0, 0, 0 });
		this->~HardBrick();
	}
}

void HardBrick::createCollidable(int x, int y, int w, int h, SDL_Color&& color) {
	std::cout << "---> HardBrick::createCollidable ---> Creating visual data for HardBrick..." << std::endl;
	Collidable::setX(x);
	Collidable::setY(y);
	Collidable::setWidth(w);
	Collidable::setHeight(h);
	Drawable::setColor({255, 0, 0, 255});
}

const Collidable& HardBrick::getCollidable() const {
	return *this;
}


void HardBrick::render(SDL_Renderer& renderer) const {
	//std::cout << "---> HardBrick::render ---> Rendering visual data for HardBrick..." << std::endl;
	Drawable::render(renderer);
}