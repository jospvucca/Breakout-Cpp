#pragma once
#ifndef __BRICK_FACTORY_H__
#define __BRICK_FACTORY_H__

#include "Brick.h"
#include "SoftBrick.h"
#include "MediumBrick.h"
#include "HardBrick.h"
#include "ImpenetrableBrick.h"
#include <unordered_map>

//TODO - decide on singleton option
class BrickFactory {
public:
	BrickFactory();
	std::unique_ptr<Brick> createBrick(const char brickId) const;

private:
	std::unordered_map<char, std::unique_ptr<Brick>> prototypes;
};

#endif // !__BRICK_FACTORY_H__
