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



	this->matrixBrickLayout = matrixBrickLayout;


	//bricksMatrix.resize(rowCount, std::vector<std::unique_ptr<Brick>>(columnCount, nullptr));
	//bricksMatrix.resize(rowCount);
	//for (int i = 0; i < rowCount; i++) {
	//	bricksMatrix[i].resize(columnCount);
	//	for (int j = 0; j < columnCount; j++) {
	//		bricksMatrix[i][j] = std::move(brickFactory.createBrick(matrixBrickLayout[i][j]));
	//	}
	//}
	
	//BrickFactory& brickFactory = BrickFactory::getInstance();
	//std::cout << "Creating Bricks from position: " + LevelConfigstringifyMatrix(matrixBrickLayout) << std::endl << std::endl;


	//bricksMatrixX.resize(rowCount);
	//for (int i = 0; i < rowCount; i++) {
	//	bricksMatrixX[i].resize(columnCount);
	//	for (int j = 0; j < columnCount; j++) {
	//		bricksMatrixX[i][j] = std::move(brickFactory.createBrick(matrixBrickLayout[i][j]));
	//	}
	//}



	//for (size_t i = 0; i < matrixBrickLayout.size(); i++)
	//{
	//	std::vector<char> inlineBrickVector = matrixBrickLayout.at(i);
	//	std::vector<std::unique_ptr<Brick>> inlineBrickResult;

	//	//auto moveIterator = std::make_move_iterator(inlineBrickVector.begin());
	//	for (size_t c = 0; c < inlineBrickVector.size(); c++)
	//	{



	//		//TODO this issue still persists
	//		char brickId = inlineBrickVector.at(c);
	//		std::cout << "Creating Brick with id: " << brickId << std::endl;
	//		//inlineBrickResult.emplace_back(brickFactory.createBrick(inlineBrickVector.at(c)));
	//		//bricksMatrixX[i][c] = std::move(brickFactory.createBrick(inlineBrickVector.at(c)));
	//	}
	//	//bricksMatrix.emplace_back(std::make_move_iterator(inlineBrickResult.begin()), std::make_move_iterator(inlineBrickResult.end()));
	//}

	//std::cout << "---> LevelConfig::ctor ---> Successfully created: " + std::to_string()
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

const int LevelConfig::getNumber() const {
	std::cout << "---> LevelConfig::getNumber ---> Returning Level number: " + number << std::endl;
	return number;
}

const int LevelConfig::getRowCount() const {
	std::cout << "---> LevelConfig::getRowCount ---> Returning Level rowCount: " + rowCount << std::endl;
	return rowCount;
}

const int LevelConfig::getColumnCount() const {
	std::cout << "---> LevelConfig::getColumnCount ---> Returning Level columnCount: " + columnCount << std::endl;
	return columnCount;
}

const int LevelConfig::getRowSpacing() const {
	std::cout << "---> LevelConfig::getRowSpacing ---> Returning Level rowSpacing: " + rowSpacing << std::endl;
	return rowSpacing;
}

const int LevelConfig::getColumnSpacing() const {
	std::cout << "---> LevelConfig::getColumnSpacing ---> Returning Level columnSpacing: " + columnSpacing << std::endl;
	return columnSpacing;
}

const std::string LevelConfig::getBackgroundTexture() const {
	std::cout << "---> LevelConfig::getBackgroundTexture ---> Returning Level backgroundTexture: " + backgroundTexture << std::endl;
	return backgroundTexture;
}

//const std::vector<std::vector<Brick*>> LevelConfig::getBricksMatrix() const {
//	std::cout << "---> LevelConfig::getBricksMatrix ---> Returning Level bricks matrix. " << std::endl;
//	//return bricksMatrix;
//	return std::vector<std::vector<Brick*>>();
//}

const std::vector<std::vector<char>> LevelConfig::getMatrixBrickLayout() const {
	std::cout << "---> LevelConfig::getMatrixBrickLayout ---> Returning Level matrixBrickLayout. " << std::endl;
	return matrixBrickLayout;
}
