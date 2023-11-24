#include "LevelConfig.h"
#include <string>

LevelConfig::LevelConfig(const int levelNumber, const int rows, const int columns,
	const int rowSpacing, const int columnSpacing,
	const std::string backgroundTexture, const std::vector<std::vector<char>> matrixBrickLayout) {
	std::cout << "---> LevelConfig::ctor ---> For level: " + std::to_string(levelNumber) + ", RowCount: " + std::to_string(rows) + ", ColumnCount: " + std::to_string(columns) +
		", RowSpacing: " + std::to_string(rowSpacing) + ", ColumnSpacing: " + std::to_string(columnSpacing) +
		", BackgroundTexture: " + backgroundTexture + ", Brick Layout: (TODO!) "<< std::endl;
	number = levelNumber;
	rowCount = rows;
	columnCount = columns;

	this->rowSpacing = rowSpacing;
	this->columnSpacing = columnSpacing;
	this->backgroundTexture = backgroundTexture;

	bricksMatrix.resize(rowCount, std::vector<Brick*>(columnCount, nullptr));

	//TODO: for matrixBrickLayout create Bricks in correct positions
	std::cout << "---> LevelConfig::ctor ---> Successfully created LevelConfig: " + this->ToString() << std::endl;
}

const std::string LevelConfig::ToString() const {
	return "TODO: implement ToString() for LevelConfig class!!";
}
