#pragma once
#ifndef __PARSE_DATA_H__
#define __PARSE_DATA_H__

#include <iostream>
#include <vector>

struct ParseData
{
	LevelData level;
	std::vector<BrickData> bricks;
	BrickPositioning positions;
};

struct LevelData {
	int rowCount;
	int columnCount;
	int rowSpacing;
	int columnSpacing;
	std::string backgroundTexture;
};

struct BrickData {
	std::string id;
	std::string texture;
	int hitpoints;
	std::string hitSound;
	int breakScore;
};

struct BrickPositioning {
	std::vector<std::vector<char>> brickPositions;
};

#endif // !__PARSE_DATA_H__
