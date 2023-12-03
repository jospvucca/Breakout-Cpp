#pragma once
#ifndef __BALL_H__
#define __BALL_H__

#include "Movable.h"

class Ball final : public Movable {
public:
	Ball(Game& game);
	//~Ball();

	void reset();
	void update(float dt);

	void increaseVelocity(float v);
	float getInitialVelocity() const { return initialVelocity; }

private:
	float initialVelocity;
	float incrementVelocity;
};

#endif // !__BALL_H__
