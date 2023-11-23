#include "ImpenetrableBrick.h"
#include <string>

ImpenetrableBrick::ImpenetrableBrick(const std::string& id, const std::string& texture,
	const std::string& hitSound) : Brick(id, texture, std::nullopt, hitSound, std::nullopt, std::nullopt) {
	std::cout << "---> ImpenetrableBrick::ctor(Id: " + id + ", Texture: " + texture +
		", HitSound: " + hitSound + ")." << std::endl;

	this->id = id;
	this->texture = texture;
	this->hitpoints = std::nullopt;
	this->hitSound = hitSound;
	this->breakSound = std::nullopt;
	this->breakScore = std::nullopt;
}

std::unique_ptr<Brick> ImpenetrableBrick::clone() const {
	return std::make_unique<ImpenetrableBrick>(*this);
}

void ImpenetrableBrick::displayInfo() const {
	std::cout << "Impenetrable Brick info...(TODO)" << std::endl;
}