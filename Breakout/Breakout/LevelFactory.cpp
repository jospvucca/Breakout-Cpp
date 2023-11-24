#include "LevelFactory.h"
#include <string>

Level LevelFactory::createLevel(const int levelNumber) {
	std::cout << "---> LevelFactory::createLevel ---> Creating level: " + std::to_string(levelNumber) + " TODO... missing logic." << std::endl;
	//LevelConfig lc = LevelConfig(levelNumber, 1, 1, 1, 1, "", std::vector<std::vector<std::string>>());
	return Level();
}