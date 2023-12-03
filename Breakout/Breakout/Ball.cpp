#include "Ball.h"
#include "LevelScene.h"
#include <array>

//TODO - move this to Calculate.cpp as static
inline std::array<float, 2> normalize(const std::array<float, 2>& value) {
	auto length = std::sqrt(std::pow(value[0], 2) + std::pow(value[1], 2));
	return { static_cast<float>(value[0] / length), static_cast<float>(value[1] / length) };
}

inline bool equals(const SDL_Color& c1, const SDL_Color& c2) {
	return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.b;
}

inline std::array<float, 2> initialDirection() {
	switch ((std::rand() * 10) % 3) {
	case 0:
		return normalize({ 0.f, 1.f });
	case 1:
		return normalize({ 0.5f, 0.5f });
	case 2:
	default:
		return normalize({ -0.5f, 0.5f });
	}
}

Ball::Ball(Game& game) : Movable(game), initialVelocity(0.0f) {
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

	//Add initial direction and velocity
	std::array<float, 2> direction = initialDirection();
	initialVelocity = (windowHeight / 2370.f);
	incrementVelocity = (windowHeight / 6330.f);

	setVelocity(0.0f);
	setDirectionX(direction[0]);
	setDirectionY(direction[1]);

	this->increaseVelocity(incrementVelocity);		//TODO - there is still work with colliders and velocity
}

void Ball::update(float dt) {
	//std::cout << "---> Ball::update ---> TODO." << std::endl;

	//Retrive scene for object references
	std::shared_ptr<LevelScene> scene = std::dynamic_pointer_cast<LevelScene>(game.getScene());
	if (scene == nullptr) {
		std::cerr << "---! Paddle::update ---! Error with finding the game scene." << std::endl;
	}

	const Collidable& leftWall = scene->getLeftWall();
	if (directionX < 0.0f && this->onCollision(leftWall)) {
		setDirectionX(-getDirectionX());
		return;												//TODO - check if its okay to use returns like this
	}

	const Collidable& rightWall = scene->getRightWall();
	if (directionX > 0.0f && this->onCollision(rightWall)) {
		setDirectionX(-getDirectionX());
		return;
	}

	const Collidable& topWall = scene->getTopWall();
	if (directionY < 0.0f && this->onCollision(topWall)) {
		setDirectionY(-getDirectionY());
		return;
	}

	const Paddle& paddle = scene->getPaddle();
	if (directionX > 0.0f && this->onCollision(paddle)) {
		float xDiff = static_cast<float>(cbX - paddle.getCollisionBoxX());

		std::array<float, 2> newDirection = std::array<float, 2>();
		newDirection[0] = (xDiff / ((static_cast<float>(paddle.getWidth())) / 2.f));
		newDirection[1] = -getDirectionY();
		newDirection = normalize(newDirection);
		setDirectionX(newDirection[0]);
		setDirectionY(newDirection[1]);
		return;
	}

	if (directionX > 0.0f && this->onCollision(scene->getOutOfBoundsArea())) {
		scene->endGame();
		return;
	}

	//TODO - brick hits
	this->move(dt);
}

void Ball::increaseVelocity(float v) {
	this->setVelocity(this->getVelocity() + v);
}