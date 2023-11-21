#include "Level.h"

Level::Level(const int levelNumber, const int rows, const int columns,
	const int rowSpacing, const int columnSpacing,
	const std::string backgroundTexture, const std::vector<std::vector<std::string>> matrixBrickLayout) {
	std::cout << "---> Level::ctor ---> For level " + levelNumber << std::endl;
	number = levelNumber;
	rowCount = rows;
	columnCount = columns;

	this->rowSpacing = rowSpacing;
	this->columnSpacing = columnSpacing;
	this->backgroundTexture = backgroundTexture;

	bricksMatrix.resize(rowCount, std::vector<Brick>(columnCount));

	//TODO: for matrixBrickLayout create Bricks in correct positions
	std::cout << "---> Level::ctor ---> Successfully created Level: " + this->ToString() << std::endl;
}

const std::string Level::ToString() const
{
	return "TODO: implement ToString() for Level class!!";
}
