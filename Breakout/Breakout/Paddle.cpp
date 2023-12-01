#include "Paddle.h"

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
	std::cout << "---> Paddle::update ---> TODO." << std::endl;

	//enable movement
	move(dt);

	//TODO - check walls
}