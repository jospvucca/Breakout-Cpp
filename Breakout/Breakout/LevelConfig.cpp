#include "LevelConfig.h"
#include "BrickFactory.h"
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

	//bricksMatrix.resize(rowCount, std::vector<std::unique_ptr<Brick>>(columnCount, nullptr));
	bricksMatrix.resize(rowCount);

	
	BrickFactory& brickFactory = BrickFactory::getInstance();
	std::cout << "Creating Bricks from position: " + LevelConfigstringifyMatrix(matrixBrickLayout) << std::endl << std::endl;

	for (size_t i = 0; i < matrixBrickLayout.size(); i++)
	{
		std::vector<char> inlineBrickVector = matrixBrickLayout.at(i);
		std::vector<std::unique_ptr<Brick>> inlineBrickResult;

		auto moveIterator = std::make_move_iterator(inlineBrickVector.begin());
		for (size_t c = 0; c < inlineBrickVector.size(); c++)
		{



			//TODO this issue still persists


			inlineBrickResult.emplace_back((brickFactory.createBrick(inlineBrickVector.at(c))));
		}
		//bricksMatrix.emplace_back(std::make_move_iterator(inlineBrickResult.begin()), std::make_move_iterator(inlineBrickResult.end()));
	}

	std::cout << "---> LevelConfig::ctor ---> Successfully created LevelConfig: " + this->ToString() << std::endl;
}

const std::string LevelConfig::ToString() const {
	return std::string("---> LevelConfig::ToString ---> Number: " + std::to_string(number) + ", RowCount: " + std::to_string(rowCount) +
		", ColumnCount: " + std::to_string(columnCount) + ", RowSpacing: " + std::to_string(rowSpacing) + ", ColumnSpacing: " + std::to_string(columnSpacing) +
		", BackgroundTexture: " + backgroundTexture + " TODO MISSING BRICKS");
}

//TESTING
std::string LevelConfig::LevelConfigstringifyMatrix(const std::vector<std::vector<char>>& matrix) {
	std::string result;

	for (const auto& row : matrix) {
		for (char character : row) {
			result += character;
			// Add a space or another separator if needed between characters
			// result += ' ';
		}
		// Add a newline or another separator if needed between rows
		result += '\n';
	}

	return result;
}