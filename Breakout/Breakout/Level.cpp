#include "Level.h"

//just for testing
Level::Level() : config(1, 1, 1, 1, 1, "", std::vector<std::vector<std::string>>()) {

}

Level::Level(const LevelConfig& levelConfig) : config(levelConfig) {
	std::cout << "---> Level::ctor(" + levelConfig.ToString() + ".)" << std::endl;
}