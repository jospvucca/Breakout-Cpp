#pragma once
#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "Brick.h"
#include <iostream>
#include <vector>

//TODO: consider implementing Level as Base
class Level {
public:
	Level(const int levelNumber, const int rows, const int columns, 
		const int rowSpacing, const int columnSpacing,
		const std::string backgroundTexture, const std::vector<std::vector<std::string>> matrixBrickLayout);
	const std::string ToString() const;
private:
	int number;		//Defining what level is loaded
	int rowCount;
	int columnCount;
	int rowSpacing;
	int columnSpacing;
	std::string backgroundTexture;

	//std::vector<std::vector<Brick>> bricksMatrix;	//Consider using std::optional<Brick> for cleaner representation of empty place, opther option is using '_' to represent empty brick - it can lead to more classes(base) created
};

#endif // !__LEVEL_H__
