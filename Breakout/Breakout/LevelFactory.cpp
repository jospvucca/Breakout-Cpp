#include "LevelFactory.h"
#include "BrickFactory.h"
#include <string>

std::unique_ptr<Level> LevelFactory::createLevelFromConfig(const int levelNumber, const LevelConfig& config) {
	std::cout << "---> LevelFactory::createLevel ---> Creating level: " + std::to_string(levelNumber) + " from config: " + config.ToString() + "." << std::endl;

	std::unique_ptr<Level> level{};
	level->instantiate(config);
	//return std::make_unique<Level>(std::move(level));
	return std::move(level);
}

//std::unique_ptr<Level> addBricks(std::unique_ptr<Level>)