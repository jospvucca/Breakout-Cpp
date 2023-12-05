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

std::unique_ptr<Brick> ImpenetrableBrick::clone(Game& game) const {
	return std::make_unique<ImpenetrableBrick>(*this);
}

void ImpenetrableBrick::displayInfo() const {
	std::cout << "Impenetrable Brick info...(TODO)" << std::endl;
}

void ImpenetrableBrick::createCollidable(int x, int y, int w, int h, SDL_Color&& color) {
	std::cout << "---> ImpenetrableBrick::createCollidable ---> Creating visual data for ImpenetrableBrick..." << std::endl;
	Collidable::setX(x);
	Collidable::setY(y);
	Collidable::setWidth(w);
	Collidable::setHeight(h);
	Collidable::setColor({128, 128, 128, 255});
}

void ImpenetrableBrick::render(SDL_Renderer& renderer) const {
	std::cout << "---> ImpenetrableBrick::render ---> Rendering visual data for ImpenetrableBrick..." << std::endl;
	Collidable::render(renderer);
}