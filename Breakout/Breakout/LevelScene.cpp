#include "LevelScene.h"
#include "BrickFactory.h"
//
//#define SLOT_WIDTH 16		//TODO - This should be revisited once we have number of bricks in a row
//#define SLOT_HEIGHT 45


// The divisor of the slot width related to window client area width.
#define SLOT_WIDTH_DIVISOR  6
// the divisor of the slot height related to window client area width.
#define SLOT_HEIGHT_DIVISOR 45

//I dislike that i have to pass game to every object, perhaps it would be better to remove the game param from object ctor
LevelScene::LevelScene(Game& game) :
	Scene(game),
	leftWall(game),
	rightWall(game),
	topWall(game),
	ball(game),
	paddle(game),
	outOfBoundsArea(game)
	/*TODO add bricks and rules from levelFactory*/{
	std::cout << "---> LevelScene::ctor(game) ----> Creating LevelScene." << std::endl;

	//Retriving window size from game
	int windowWidth, windowHeight;
	SDL_GetWindowSize(game.getWindow(), &windowWidth, &windowHeight);
	int windowHalfWidth = (windowWidth / 2);
	int windowHalfHeight = (windowHeight / 2);

	auto slotWidthDivisor = game.getLevelConfig().getColumnCount();
	auto slotHeightDivisor = game.getLevelConfig().getRowCount();
	auto slotSpacing = game.getLevelConfig().getRowSpacing();

	// precalculate some relative size definitions.
	auto slotWidth = (windowWidth / slotWidthDivisor) - SLOT_WIDTH_DIVISOR;
	auto slotHeight = (windowWidth / SLOT_HEIGHT_DIVISOR);
	auto slotHalfWidth = (slotWidth / 2);
	auto slotHalfHeight = (slotHeight / 2);
	auto digitHeight = (slotHeight * 5);
	//auto slotSpacing = (windowWidth - (2 * slotHeight) - (14 * slotWidth)) / 13;

	//Position obstruction elements
	leftWall.setX(0);
	leftWall.setY(0);
	leftWall.setWidth(slotHeight);		//TODO - This whole initial values should be revisited once we have number of bricks in a row
	leftWall.setHeight(windowHeight);

	rightWall.setX(windowWidth - slotHeight);
	rightWall.setY(0);
	rightWall.setWidth(slotHeight);
	rightWall.setHeight(windowHeight);

	topWall.setX(0);
	topWall.setY(0);
	topWall.setWidth(windowWidth);
	topWall.setHeight(slotHeight);

	ball.setX(windowHalfWidth - slotHalfHeight);
	ball.setY(windowHalfHeight - slotHalfHeight);
	ball.setWidth(slotHeight);
	ball.setHeight(slotHeight);

	paddle.setColor({ 0, 255, 255 , 255 });
	paddle.setVelocity((static_cast<float>(windowHeight) / 1350.0f));
	paddle.setX(windowHalfWidth - slotHalfWidth);
	paddle.setY(windowHeight - 100);
	paddle.setWidth(slotWidth);
	paddle.setHeight(slotHeight);

	//Initialize Bricks - TODO!!!

	//Position out of bounds area
	outOfBoundsArea.setX(0);
	outOfBoundsArea.setY(windowHeight + slotHeight);
	outOfBoundsArea.setWidth(windowWidth);
	outOfBoundsArea.setHeight(1000);	//Can be whatever



	/*
	TESTING BRICKS IMPORT WITH OTHER PARAMETERS
	*/

	auto x = slotWidth;
	auto y = slotHeight * 5 + digitHeight + slotSpacing;

	//auto bricksMatrix = this->game.getLevelConfig().getBricksMatrix();
	//for (int i = 0; i < this->game.getLevelConfig().getBricksMatrix().size(); i++) {
	//	for (int j = 0; j < this->game.getLevelConfig().getBricksMatrix()[i].size(); i++) {
	//		//auto brick = bricksMatrix[i][j];
	//		this->game.getLevelConfig().getBricksMatrix()[i][j]->createCollidable(x, y, slotWidth, slotHeight, {255, 0, 0, 255});

	//		x += slotWidth + slotSpacing;
	//	}
	//	y += slotHeight + slotSpacing;
	//}




	BrickFactory& brickFactory = BrickFactory::getInstance(game);

	bricksMatrixX = std::vector<std::vector<std::unique_ptr<Brick>>>();
	auto bricksLayout = this->game.getLevelConfig().getMatrixBrickLayout();
	for (int i = 0; i < bricksLayout.size(); i++) {

		std::vector<std::unique_ptr<Brick>> bricksVector;
		for (int j = 0; j < bricksLayout[i].size(); j++) {
			if (game.getLevelConfig().getMatrixBrickLayout().at(i).at(j) != '_') {
			bricksVector.emplace_back(std::move(brickFactory.createBrick(bricksLayout.at(i).at(j), game)));
			}
			else {
				bricksVector.emplace_back(nullptr);
			}
		}

		bricksMatrixX.emplace_back(std::move(bricksVector));
	}

	for (int i = 0; i < bricksMatrixX.size(); i++) {
		x = slotWidth;
		for (int j = 0; j < bricksMatrixX[i].size(); j++) {
			if (bricksMatrixX[i][j] != nullptr) {
				bricksMatrixX[i][j]->createCollidable(x, y, slotWidth, slotHeight, { 255, 0, 0, 255 });
			}
			x += slotWidth + slotSpacing;
		}

		y += slotHeight + slotSpacing;
	}

	auto tt = x;

	//BrickFactory& brickFactory = BrickFactory::getInstance();
	//std::cout << "Creating Bricks from position: " + LevelConfigstringifyMatrix(matrixBrickLayout) << std::endl << std::endl;

	//bricksMatrixX.resize(rowCount);
	//for (int i = 0; i < this->game(); i++) {
	//	//bricksMatrixX[i].resize(columnCount);
	//	for (int j = 0; j < columnCount; j++) {
	//		bricksMatrixX[i][j] = std::move(brickFactory.createBrick(matrixBrickLayout[i][j]));
	//	}
	//}
	// 
	// 
	//this->brickMatrixX = std::vector<std::vector<std::unique_ptr<Brick>>>();
	//this->brickMatrixX.push_back(std::vector<std::unique_ptr<Brick>>());
	//this->brickMatrixX[0].emplace_back(std::move(brickFactory.createBrick((this->game.getLevelConfig().getMatrixBrickLayout().at(0).at(0)))));
}

LevelScene::~LevelScene() {
	std::cout << "---> LevelScene::~LevelScene ---> Destroying LevelScene..." << std::endl;
	Scene::~Scene();
}

void LevelScene::update(float dt) {
	//std::cout << "---> LevelScene::update ---> TODO" << std::endl;
	paddle.update(dt);
	ball.update(dt);
}

void LevelScene::render() const {
	//std::cout << "---> LevelScene::render ---> rendering all scene elements." << std::endl;

	//Render each element one by one
	SDL_Renderer& renderer = game.getRenderer();
	leftWall.render(renderer);
	rightWall.render(renderer);
	topWall.render(renderer);

	ball.render(renderer);
	paddle.render(renderer);

	//After adding new elements continue

	for (int i = 0; i < bricksMatrixX.size(); i++) {
		for (int j = 0; j < bricksMatrixX[i].size(); j++) {
			if (bricksMatrixX[i][j] != nullptr) {
				bricksMatrixX[i][j]->render(renderer);
			}
		}
	}
}

void LevelScene::enter() const {
	std::cout << "---> LevelScene::enter ---> TODO" << std::endl;
}

void LevelScene::exit() const {
	std::cout << "---> LevelScene::exit ---> TODO" << std::endl;
}

void LevelScene::onKeyDown(SDL_KeyboardEvent& event) {
	std::cout << "---> LevelScene::onKeyDown ---> TODO" << std::endl;

	switch (event.keysym.sym) {
	case SDLK_LEFT:
		paddle.setDirectionX(-1.0f);
		break;
	case SDLK_RIGHT:
		paddle.setDirectionX(1.0f);
		break;
	//case SDLK_SPACE:
	//	if (std::fabs(mBall.getVelocity()) < 0.00001f && !mBall.isVisible()) {
	//		mBall.setVelocity(mBall.getInitialVelocity());
	//		mBall.setVisible(true);
	//	}
		break;
	}
}

void LevelScene::onKeyUp(SDL_KeyboardEvent& event) {
	std::cout << "---> LevelScene::onKeyUp ---> TODO" << std::endl;

	switch (event.keysym.sym) {
	case SDLK_LEFT:
		if (std::fabs(paddle.getDirectionX() + 1.0f) < 0.00001f) {
			paddle.setDirectionX(0.0f);
		}
		break;
	case SDLK_RIGHT:
		if (std::fabs(paddle.getDirectionX() - 1.0f) < 0.00001f) {
			paddle.setDirectionX(0.0f);
		}
		break;
	//case SDLK_SPACE:
	//	break;
	}
}

void LevelScene::resetBallAndPaddle() {
	std::cout << "---> LevelScene::resetBallAndPaddle ---> Reseting to original position..." << std::endl;
	ball.reset();
	paddle.reset();
}

void LevelScene::endGame() {
	std::cout << "---> LevelScene::endgame ---> TODO" << std::endl;
}

void LevelScene::refreshScore() {
	std::cout << "---> LevelScene::refreshScore ---> TODO" << std::endl;
}

const Collidable& LevelScene::getBrickCollidableByLocation(int i, int j) {
	return this->bricksMatrixX.at(i).at(j)->getCollidable();
}
