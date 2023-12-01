#pragma once
#ifndef __PADDLE_H__
#define __PADDLE_H__

#include "Movable.h"

class Paddle final : public Movable {
public:
	Paddle(Game& game);
	//~Paddle();

	void reset();
	void update(float dt);

private:

};

#endif // !__PADDLE_H__
