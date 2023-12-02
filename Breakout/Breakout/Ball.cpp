#include "Ball.h"

Ball::Ball(Game& game) : Movable(game) {
	std::cout << "---> Ball::ctor(game) ---> Created Ball Object." << std::endl;

	//TODO - Set initial velocity and direction

	reset();
}

void Ball::reset() {
	std::cout << "---> Ball::reset ---> Reseting Ball to original position with Direction: ... and Velocity: ..." << std::endl;

	int windowWidth, windowHeight;
	SDL_GetWindowSize(game.getWindow(), &windowWidth, &windowHeight);

	//Position Ball in the middle
	setX(windowWidth / 2);		//Needs small adjustments
	setY(windowHeight / 2);

	//TODO - add direction and velocity
}

void Ball::update(float dt) {
	//std::cout << "---> Ball::update ---> TODO." << std::endl;
}