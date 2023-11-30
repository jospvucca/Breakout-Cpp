#pragma once
#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "Scene.h"
#include "Collidable.h"
//#include "LevelFactory.h"

class LevelScene final : public Scene {
public:
	LevelScene(Game& game);
	~LevelScene();

	void update(float dt) const override;
	void render() const override;
	void enter() const override;
	void exit() const override;
	void onKeyDown(SDL_KeyboardEvent& event) const override;
	void onKeyUp(SDL_KeyboardEvent& event) const override;

	void endGame();	//TODO - change location

private:
	void refreshScore();

private:
	Collidable leftWall;
	Collidable rightWall;
	Collidable topWall;

	Collidable outOfBoundsArea;
};

#endif // !__LEVEL_SCENE_H__
