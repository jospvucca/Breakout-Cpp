#include "HardBrick.h"
#include <string>

HardBrick::HardBrick(const std::string& id, const std::string& texture,
	const int hitpoints, const std::string& hitSound,
	const std::string& breakSound, const int breakPoints) : Brick(id, texture, hitpoints, hitSound, breakSound, breakPoints) {
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

std::unique_ptr<Brick> HardBrick::clone() const {
	return std::make_unique<HardBrick>(*this);
}

void HardBrick::displayInfo() const {
	std::cout << "---> Hard Brick info...(TODO)" << std::endl;
}