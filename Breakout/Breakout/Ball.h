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


};

#endif // !__BALL_H__
