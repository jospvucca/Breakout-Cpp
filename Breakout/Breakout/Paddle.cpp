#include "Paddle.h"
#include "LevelScene.h"

Paddle::Paddle(Game& game) : Movable(game) {
	std::cout << "---> Paddle::ctor(game) ---> Created Paddle Object." << std::endl;
}

void Paddle::reset() {
	std::cout << "---> Paddle::reset ---> Moving Paddle to starting position..." << std::endl;
	
	int windowWidth;
	SDL_GetWindowSize(game.getWindow(), &windowWidth, nullptr);

	//Move to original position
	rect.x = (windowWidth / 2);		//This needs to be moved a bit
	//TODO - adjust collider position
}

void Paddle::update(float dt) {
	//std::cout << "---> Paddle::update ---> TODO." << std::endl;

	//Get current scene and cast it as LevelScene(paddle only exists in that scene)
	std::shared_ptr<LevelScene> scene = std::dynamic_pointer_cast<LevelScene>(game.getScene());
	if (scene == nullptr) {
		std::cerr << "---! Paddle::update ---! Error with finding the game scene." << std::endl;
	}

	//enable movement
	move(dt);

	//check walls collision
	if (directionX < 0.0f) {
		const Collidable& leftWall = scene->getLeftWall();
		if (leftWall.onCollision(*this)) {
			rect.x = leftWall.getX() + leftWall.getExtendedX() * 2;
			cbX = rect.x + extendedX;
		}
	}
	else if (directionX > 0.0f) {
		const Collidable& rightWall = scene->getRightWall();
		if (rightWall.onCollision(*this)) {
			rect.x = rightWall.getX() - this->extendedX * 2;
			cbX = rect.x + extendedX;
		}
	}
	else {
		//std::cout << "---> Paddle::update ---> paddle is still." << std::endl;
	}
}