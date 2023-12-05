#include "ImpenetrableBrick.h"
#include <string>

ImpenetrableBrick::ImpenetrableBrick(Game& game) : Collidable(game) {

}

ImpenetrableBrick::ImpenetrableBrick(const std::string& id, const std::string& texture,
	const std::string& hitSound, Game& game) :
	Brick(id, texture, std::nullopt, hitSound, std::nullopt, std::nullopt),
	Collidable(game) {
	std::cout << "---> ImpenetrableBrick::ctor(Id: " + id + ", Texture: " + texture +
		", HitSound: " + hitSound + ")." << std::endl;

	this->id = id;
	this->texture = texture;
	this->hitpoints = std::nullopt;
	this->hitSound = hitSound;
	this->breakSound = std::nullopt;
	this->breakScore = std::nullopt;
}

std::unique_ptr<Brick> ImpenetrableBrick::clone(Game& game) {
	BrickData brickData;
	for (int i = 0; i < game.getParseData().bricks.size(); i++) {
		if (game.getParseData().bricks.at(i).id.starts_with('I')) {
			brickData = game.getParseData().bricks.at(i);
		}
	}

	this->id = brickData.id;
	this->texture = brickData.texture;
	this->hitpoints = brickData.hitpoints;
	this->hitSound = brickData.breakSound;
	this->breakSound = brickData.breakSound;
	this->breakScore = brickData.breakScore;

	return std::make_unique<ImpenetrableBrick>(*this);
}

void ImpenetrableBrick::displayInfo() const {
	std::cout << "Impenetrable Brick info...(TODO)" << std::endl;
}

void const ImpenetrableBrick::decreaseHitpoints() {

}

void ImpenetrableBrick::createCollidable(int x, int y, int w, int h, SDL_Color&& color) {
	std::cout << "---> ImpenetrableBrick::createCollidable ---> Creating visual data for ImpenetrableBrick..." << std::endl;
	Collidable::setX(x);
	Collidable::setY(y);
	Collidable::setWidth(w);
	Collidable::setHeight(h);
	Collidable::setColor({128, 128, 128, 255});
}

const Collidable& ImpenetrableBrick::getCollidable() const {
	return *this;
}

void ImpenetrableBrick::render(SDL_Renderer& renderer) const {
	//std::cout << "---> ImpenetrableBrick::render ---> Rendering visual data for ImpenetrableBrick..." << std::endl;
	Collidable::render(renderer);
}