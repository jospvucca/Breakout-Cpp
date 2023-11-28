#include "Game.h"
#include <iostream>

Game::Game() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "---! Game::ctor() ---! SDL Initialization failed." << SDL_GetError() << std::endl;
	}

	std::cout << "---> Game::ctor() ---> SDL Initialized successfully." << std::endl;
}

Game::~Game() {
	SDL_Quit();
	std::cout << "---> Game::~Game() ---> SDL successfully cleaned up." << std::endl;
}