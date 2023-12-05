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
class BrickFactory final {
public:
	static BrickFactory& getInstance(Game& game);
	//std::unique_ptr<Brick> createBrick(const char& brickId);

	std::unique_ptr<Brick> createBrick(const char& brickId, Game& game);
	std::unique_ptr<Brick> cloneBrick(const char& brickId, Game& game) const;

private:
	BrickFactory(Game& game);
	~BrickFactory();

	static BrickFactory* instance;
	std::unordered_map<char, std::unique_ptr<Brick>> prototypes;
};

#endif // !__BRICK_FACTORY_H__
