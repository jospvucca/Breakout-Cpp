#pragma once
#ifndef __LEVEL_FACTORY_H__
#define __LEVEL_FACTORY_H__

#include "Level.h"

class LevelFactory {
public:
	//static Level createLevel(const int levelNumber);
	static std::unique_ptr<Level> createLevelFromConfig(const int levelNumber, const LevelConfig& config);
	//Load etc methods
};

#endif // !__LEVEL_FACTORY_H__
