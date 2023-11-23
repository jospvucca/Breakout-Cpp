#pragma once
#ifndef __LEVEL_FACTORY_H__
#define __LEVEL_FACTORY_H__

#include "Level.h"

class LevelFactory {
public:
	static Level createLevel(const int levelNumber);
	//Load etc methods
};

#endif // !__LEVEL_FACTORY_H__
