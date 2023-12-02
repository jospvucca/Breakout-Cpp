#include "Movable.h"
#include <string>
#include <cmath>

Movable::Movable(Game& game) : Collidable(game), directionX(0.0f), directionY(0.0f), velocity(0.0f) {
	std::cout << "---> Movable::ctor(game) ---> Creating Movable Object." << std::endl;
}

void Movable::move(float dt) {
	//std::cout << "---> Movable::move ---> Moving object by: " + std::to_string(dt) + "." << std::endl;

	//Defining epsilon for float comparison
	static const auto epsilon = 0.0001f;

	//Update the position of the Object on x-axis
	if (std::fabs(directionX) > epsilon) {
		float diff = dt * directionX * velocity;
		rect.x += diff;		//TODO - cast to int
		cbX += diff;
	}

	//Update the position of the Object on y-axis
	if (std::fabs(directionY) > epsilon) {
		float diff = dt * directionY * velocity;
		rect.y += diff;		//TODO - cast to int
		cbY += diff;
	}
}