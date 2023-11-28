#include "BrickFactory.h"


/*
* TODO
* Add console logs for everything implemented tonight.
*/

BrickFactory* BrickFactory::instance = nullptr;

BrickFactory& BrickFactory::getInstance() {
	std::cout << "---> BrickFactory::getInstance ---> returning Singleton BrickFactory." << std::endl;
	if (instance == nullptr) {
		std::cout << "---> BrickFactory::getInstance() ---> Instance of a BrickFactory does not exist. Creating new BrickFactory..." << std::endl;
		instance = new BrickFactory();
	}

	return *instance;
}

BrickFactory::BrickFactory() {
	std::cout << "---> BrickFactory::ctor ---> Adding Brick prototypes..." << std::endl;
	prototypes['S'] = std::make_unique<SoftBrick>();
	prototypes['M'] = std::make_unique<MediumBrick>();
	prototypes['H'] = std::make_unique<HardBrick>();
	prototypes['I'] = std::make_unique<ImpenetrableBrick>();
}

std::unique_ptr<Brick> BrickFactory::createBrick(const char& brickId) {		//Not sure if its char& or char
	std::cout << "---> BrickFactory::createBrick ---> Creating Brick with id: " + brickId << std::endl;
	
	auto it = prototypes.find(brickId);
	if (it != prototypes.end()) {
		//Clone the prototype
		//This will probably need parameters, but its fine for now
		return it->second->clone();
	}

	std::cout << "---> BrickFactory::createBrick ---! Error creating a brick. Could not find brick by id: " + brickId << std::endl;
	return nullptr;
}

BrickFactory::~BrickFactory() {
	std::cout << "---> BrickFactory::~BrickFactory ---> Destroying BrickFactory instance..." << std::endl;
	delete instance;
}