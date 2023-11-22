#include "BrickFactory.h"


/*
* TODO
* Add console logs for everything implemented tonight.
*/






BrickFactory::BrickFactory() {
	std::cout << "---> BrickFactory::ctor ---> Adding Brick prototypes..." << std::endl;
	//prototypes['S'] = std::make_unique<SoftBrick>();
	//prototypes['M'] = std::make_unique<MediumBrick>();
	//prototypes['H'] = std::make_unique<HardBrick>();
	//prototypes['I'] = std::make_unique<ImpenetrableBrick>();
}

std::unique_ptr<Brick> BrickFactory::createBrick(const char brickId) const {		//Not sure if its char& or char
	std::cout << "---> BrickFactory::createBrick ---> Creating Brick with id: " + brickId << std::endl;


	//TODO fix this with clone method
	
	//auto it = prototypes.find(brickId);
	//if (it != prototypes.end()) {
	//	//Clone the prototype
	//	//return std::make_unique<Brick>(*it->second);
	//}

	std::cout << "---> BrickFactory::createBrick ---! Error creating a brick. Could not find brick by id: " + brickId << std::endl;
	return nullptr;
}