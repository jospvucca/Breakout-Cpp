#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Game.h"
#include <SDL.h>

//TODO - change name to GameObject
class Object {
public:
	Object(Game& gameRef) : game(gameRef), rect({ 0, 0, 0, 0 }) {}
	virtual ~Object() = default;

	int getX() const { return rect.x; }
	int getY() const { return rect.y; }
	int getWidth() const { return rect.w; }
	int getHeight() const { return rect.h; }

	virtual void setX(const int x) { rect.x = x; }
	virtual void setY(const int y) { rect.y = y; }
	virtual void setWidth(const int w) { rect.w = w; }
	virtual void setHeight(const int h) { rect.h = h; }

protected:
	Game& game;
	SDL_Rect rect;
};

#endif // !__OBJECT_H__
