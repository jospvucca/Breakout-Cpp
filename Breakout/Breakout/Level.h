#pragma once
#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "LevelConfig.h"

class Level {
public:
	Level();	//just for testing
private:
	Level(const LevelConfig& levelConfig);
	const LevelConfig config;
};

#endif // !__LEVEL_H__
