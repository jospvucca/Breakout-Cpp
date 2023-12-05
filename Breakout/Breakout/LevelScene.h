#pragma once
#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "Scene.h"
#include "Collidable.h"
#include "Ball.h"
#include "Paddle.h"
//#include "LevelFactory.h"

class LevelScene final : public Scene {
public:
	LevelScene(Game& game);
	~LevelScene();

	void update(float dt) override;
	void render() const override;
	void enter() const override;
	void exit() const override;
	void onKeyDown(SDL_KeyboardEvent& event) override;
	void onKeyUp(SDL_KeyboardEvent& event) override;

	const Collidable& getLeftWall() const { return leftWall; }
	const Collidable& getRightWall() const { return rightWall; }
	const Collidable& getTopWall() const { return topWall; }

	const Ball& getBall() const { return ball; }
	const Paddle& getPaddle() const { return paddle; }

	const Collidable& getOutOfBoundsArea() { return outOfBoundsArea; }

	void resetBallAndPaddle();
	void endGame();	//TODO - change location

private:
	void refreshScore();

private:
	Collidable leftWall;
	Collidable rightWall;
	Collidable topWall;

	Ball ball;
	Paddle paddle;

	Collidable outOfBoundsArea;

	std::vector<std::vector<std::unique_ptr<Brick>>> bricksMatrixX;
};

#endif // !__LEVEL_SCENE_H__
