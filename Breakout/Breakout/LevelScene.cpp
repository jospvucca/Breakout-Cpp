#include "LevelScene.h"

#define SLOT_WIDTH 10		//TODO - This should be revisited once we have number of bricks in a row
#define SLOT_HEIGHT 10

//I dislike that i have to pass game to every object, perhaps it would be better to remove the game param from object ctor
LevelScene::LevelScene(Game& game) : Scene(game), leftWall(game), rightWall(game), topWall(game), outOfBoundsArea(game) {
	std::cout << "---> LevelScene::ctor(game) ----> Creating LevelScene." << std::endl;

	//Retriving window size from game
	int windowWidth, windowHeight;
	SDL_GetWindowSize(game.getWindow(), &windowWidth, &windowHeight);

	//Position obstruction elements
	leftWall.setX(0);
	leftWall.setY(0);
	leftWall.setWidth(SLOT_HEIGHT);		//TODO - This should be revisited once we have number of bricks in a row
	leftWall.setHeight(windowHeight);

	rightWall.setX(windowWidth - SLOT_HEIGHT);
	rightWall.setY(0);
	rightWall.setWidth(SLOT_HEIGHT);
	rightWall.setHeight(windowHeight);

	topWall.setX(0);
	topWall.setY(0);
	topWall.setWidth(windowWidth);
	topWall.setHeight(SLOT_HEIGHT);

	//Initialize Bricks - TODO!!!

	//Position out of bounds area
	outOfBoundsArea.setX(0);
	outOfBoundsArea.setY(windowHeight + SLOT_HEIGHT);
	outOfBoundsArea.setWidth(windowWidth);
	outOfBoundsArea.setHeight(windowHeight);	//Can be whatever
}

LevelScene::~LevelScene() {
	std::cout << "---> LevelScene::~LevelScene ---> Destroying LevelScene..." << std::endl;
	Scene::~Scene();
}

void LevelScene::update(float dt) const {
	std::cout << "---> LevelScene::update ---> TODO" << std::endl;
}

void LevelScene::render() const {
	std::cout << "---> LevelScene::render ---> rendering all scene elements." << std::endl;

	//Render each element one by one
	SDL_Renderer& renderer = game.getRenderer();
	leftWall.render(renderer);
	rightWall.render(renderer);
	topWall.render(renderer);

	//After adding new elements continue
}

void LevelScene::enter() const {
	std::cout << "---> LevelScene::enter ---> TODO" << std::endl;
}

void LevelScene::exit() const {
	std::cout << "---> LevelScene::exit ---> TODO" << std::endl;
}

void LevelScene::onKeyDown(SDL_KeyboardEvent& event) const {
	std::cout << "---> LevelScene::onKeyDown ---> TODO" << std::endl;
}

void LevelScene::onKeyUp(SDL_KeyboardEvent& event) const {
	std::cout << "---> LevelScene::onKeyUp ---> TODO" << std::endl;
}

void LevelScene::endGame() {
	std::cout << "---> LevelScene::endgame ---> TODO" << std::endl;
}

void LevelScene::refreshScore() {
	std::cout << "---> LevelScene::refreshScore ---> TODO" << std::endl;
}