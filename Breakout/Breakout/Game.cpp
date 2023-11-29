#include "Game.h"
#include <iostream>
#include <string>

Game::Game(const int width, const int height, const std::string& fontPath, const char* title) : 
	window(nullptr),		//TODO - change to singleton type method getInstance()
	renderer(nullptr),		//TODO - same
	//scene(nullptr),
	state(State::NOT_INITED) {
	std::cout << "---> Game::ctor(For window -> Width: " + std::to_string(width) + ", Height: " + std::to_string(height) + ")." + "TODO: fontPath" << std::endl;
	this->scene = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "---! Game::ctor ---! Error initializing SDL." << SDL_GetError() << std::endl;
	}

	//TODO - initialize text rendering (ttf part of sdl)
	
	std::cout << "---> Game::ctor ---> Creating SDL window with Title: " + std::string(title) + ", Position(x,y): (" +
		std::to_string(SDL_WINDOWPOS_CENTERED) + "," + std::to_string(SDL_WINDOWPOS_CENTERED) + "), Width: " + std::to_string(width) + ", Height: " + std::to_string(height) +
		", Flag type: " + std::to_string(SDL_WINDOW_SHOWN) + "." << std::endl;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cerr << "---! Game::ctor ---! Error creating SDL window." << SDL_GetError() << std::endl;
	}

	std::cout << "---> Game::ctor ---> Creating SDL renderer from SDL Window: " + std::string(SDL_GetWindowTitle(window)) +
		" with rendering tech: " + std::to_string(SDL_RENDERER_ACCELERATED) + "." << std::endl;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		std::cerr << "---! Game::ctor ---! Error initializing SDL renderer." << SDL_GetError() << std::endl;
	}

	//TODO - loadScene
	state = State::INITED;
}

Game::~Game() {
	std::cout << "---> Game::~Game() ---> Cleaning up Game." << std::endl;
	if (renderer != nullptr) {
		SDL_DestroyRenderer(renderer);
	}

	if (window != nullptr) {
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
}

void Game::loadScene(std::unique_ptr<Scene> newScene) {
	std::cout << "---> Game::loadScene ---> Loading new Scene: " + std::to_string(newScene->name) << std::endl;
	if (this->scene != nullptr) {
		std::cout << "---> Game::loadScene ---> Removing old Scene: " + std::to_string(this->scene->name) << std::endl;
		//TODO: destroy old scene
	}

	this->scene = std::move(newScene);
	//TODO - change state
	//TODO - call scene method for starting
}

int Game::update() {
	std::cout << "---> Game::update() ---> TODO" << std::endl;

	if (this->state != State::INITED) {
		std::cerr << "---! Game::update() ---! Error while running the game. Current state id: " + (int)state << std::endl;
	}

	while (this->state == State::RUNNING) {

	}

	return 1;
}