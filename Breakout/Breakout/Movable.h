#pragma once
#ifndef __MOVABLE_H__
#define __MOVABLE_H__

#include "Collidable.h"

class Movable : public Collidable {
public:
	Movable(Game& game);
	virtual ~Movable() = default;

	void move(float dt);
	float getDirectionX() const { return directionX; }
	float getDirectionY() const { return directionY; }
	float getVelocity() const { return velocity; }

	void setDirectionX(float x) { directionX = x; }
	void setDirectionY(float y) { directionY = y; }
	void setVelocity(float v) { velocity = v; }

protected:
	float directionX;
	float directionY;
	float velocity;
};

#endif // !__MOVABLE_H__
