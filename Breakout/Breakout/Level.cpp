#include "Level.h"

Level::Level(const LevelConfig& levelConfig) : config(levelConfig) {
	std::cout << "---> Level::ctor(" + levelConfig.ToString() + ".)" << std::endl;
}