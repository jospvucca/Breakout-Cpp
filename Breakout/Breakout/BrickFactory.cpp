#include "BrickFactory.h"


/*
* TODO
* Add console logs for everything implemented tonight.
*/






BrickFactory::BrickFactory() {
	prototypes['S'] = std::make_unique<SoftBrick>();
	prototypes['M'] = std::make_unique<MediumBrick>();
	prototypes['H'] = std::make_unique<HardBrick>();
	prototypes['I'] = std::make_unique<ImpenetrableBrick>();
}

std::unique_ptr<Brick> BrickFactory::createBrick(const char brickId) const {		//Not sure if its char& or char
	auto it = prototypes.find(brickId);
	if (it != prototypes.end()) {
		//Clone the prototype
		return std::make_unique<Brick>(*it->second);
	}

	return nullptr;
}