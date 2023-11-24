#pragma once
#ifndef __PARSE_DATA_H__
#define __PARSE_DATA_H__

#include <string>
#include <vector>

struct LevelData {
	int rowCount;
	int columnCount;
	int rowSpacing;
	int columnSpacing;
	std::string backgroundTexture;
};

struct BrickPositioning {
	std::vector<std::vector<char>> brickPositions;
};

struct BrickData {
	std::string id;
	std::string texture;
	int hitpoints;
	std::string hitSound;
	std::string breakSound;
	int breakScore;
};

struct ParseData
{
	LevelData level;
	std::vector<BrickData> bricks;
	BrickPositioning positions;
};

#endif // !__PARSE_DATA_H__
