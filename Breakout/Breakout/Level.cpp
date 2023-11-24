#include "Level.h"

Level::Level(const LevelConfig& levelConfig) : config(levelConfig) {
	std::cout << "---> Level::ctor(" + levelConfig.ToString() + ".)" << std::endl;
}

std::unique_ptr<Level> Level::instantiate(const LevelConfig& levelConfig) {
	std::cout << "---> Level::instantiate ---> Creating instance with config: " + levelConfig.ToString() << std::endl;
	return std::make_unique<Level>(Level(levelConfig));
	//return std::make_unique<Level>(levelConfig);
}