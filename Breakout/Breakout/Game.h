#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>

class Game final {
public:
	Game();
	~Game();
};

//NOTE - i tried with initialization of game and window in main but it did not work(needs more fixing)

#endif // !__GAME_H__
