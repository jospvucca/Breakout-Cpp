#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include <SDL.h>
#include <iostream>

class Game;

class Scene {
public:
	Scene() = default;
	Scene(Game& game) : game(game) {};
	virtual ~Scene() = default;

	virtual void update(float dt) = 0;
	virtual void render() const = 0;
	virtual void enter() const = 0;
	virtual void exit() const = 0;
	
	virtual void onKeyDown(SDL_KeyboardEvent& event) {};
	virtual void onKeyUp(SDL_KeyboardEvent& event) = 0;

	int name;	//should be string or not exist

//protected:
	Game& game;
};

#endif // !__SCENE_H__
