#include "Game.h"
#include "IntroScene.h"
#include <iostream>
#include <string>
#include <chrono>

//TODO - move this method as static to Calculate.cpp with <chrono>
inline unsigned long currentMillis() {
	return static_cast<unsigned long>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

//TODO - use LevelFactory and Config
Game::Game(const int width, const int height, const char* fontPath, const char* title, const LevelConfig& levelConfig) : 
	window(nullptr),		//TODO - change to singleton type method getInstance()
	renderer(nullptr),		//TODO - same
	scene(nullptr),
	state(State::NOT_INITED),
	font(nullptr),
	currentTickMillis(0l),
	previousTickMillis(0l),
	deltaTime(0l),
	 levelConfig(levelConfig) {
	std::cout << "---> Game::ctor(For window -> Width: " + std::to_string(width) + ", Height: " + std::to_string(height) + ")." + "TODO: fontPath" << std::endl;
	this->scene = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "---! Game::ctor ---! Error initializing SDL." << SDL_GetError() << std::endl;
		return;
	}

	if (TTF_Init() < 0) {
		std::cerr << "---! Game::ctor ---! Error initializing TTL." << SDL_GetError() << std::endl;
		return;
	}
	
	//Creating SDL window
	std::cout << "---> Game::ctor ---> Creating SDL window with Title: " + std::string(title) + ", Position(x,y): (" +
		std::to_string(SDL_WINDOWPOS_CENTERED) + "," + std::to_string(SDL_WINDOWPOS_CENTERED) + "), Width: " + std::to_string(width) + ", Height: " + std::to_string(height) +
		", Flag type: " + std::to_string(SDL_WINDOW_SHOWN) + "." << std::endl;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cerr << "---! Game::ctor ---! Error creating SDL window." << SDL_GetError() << std::endl;
		return;
	}

	//Creating SDL renderer
	std::cout << "---> Game::ctor ---> Creating SDL renderer from SDL Window: " + std::string(SDL_GetWindowTitle(window)) +
		" with rendering tech: " + std::to_string(SDL_RENDERER_ACCELERATED) + "." << std::endl;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cerr << "---! Game::ctor ---! Error initializing SDL renderer." << SDL_GetError() << std::endl;
		return;
	}

	//Create font from file
	font = TTF_OpenFont(fontPath, 24);
	if (font == nullptr) {
		std::cerr << "---! Game::ctor ---! Error creating text font: " << TTF_GetError() << std::endl;
		return;
	}

	//// initialize random.
	//srand((unsigned int)time(NULL));

	//loadScene(std::make_shared<IntroScene>(*this));		- it makes more sense to put this here but its bugged for now
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

void Game::loadScene(std::shared_ptr<Scene> newScene) {
	std::cout << "---> Game::loadScene ---> Loading new Scene: " + std::to_string(newScene->name) << std::endl;
	if (this->scene != nullptr) {
		std::cout << "---> Game::loadScene ---> Removing old Scene: " + std::to_string(this->scene->name) << std::endl;

		this->scene->exit();			//TODO: destroy old scene inside the exit method
	}

	this->scene = newScene;
	this->scene->enter();
	//state = State::RUNNING;
	//TODO - call scene method for starting
}

int Game::update() {
	//std::cout << "---> Game::update() ---> TODO" << std::endl;

	if (this->state != State::INITED) {
		std::cerr << "---! Game::update() ---! Error while running the game. Current state id: " + (int)state << std::endl;
		return -1;
	}

	SDL_Event event;
	if (this->state == State::INITED) {
		std::cout << "---> Game::update() ---> Initializing start() part of the loop." << std::endl;


		loadScene(std::make_shared<IntroScene>(*this));	//This doesnt seem right, def should not include IntroScene here
		state = State::RUNNING;

	}

	while (this->state == State::RUNNING) {
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				state = State::STOPPED;
				break;
			case SDL_KEYDOWN:
				scene->onKeyDown(event.key);
				break;
			case SDL_KEYUP:
				scene->onKeyUp(event.key);
				break;
			default:
				std::cout << "---> Game::update() ---> Event happened: " + std::string(event.text.text) << std::endl;
				break;
			}
		}

		//Calculating tick for updates of game elements
		//Calculating the delta between curr and prev tick in milliseconds.
		currentTickMillis = currentMillis();
		unsigned long dt = (currentTickMillis - previousTickMillis);
		previousTickMillis = currentTickMillis;

		//update delta time and call update method
		deltaTime += dt;
		static const float FPS = (10001 / 601);
		if (deltaTime >= FPS) {
			this->scene->update(static_cast<float>(FPS));
			deltaTime -= FPS;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		scene->render();
		SDL_RenderPresent(renderer);
	}

	return 0;
}

//TODO - not yet tested
SDL_Texture* Game::createText(const std::string& text)
{
	// create a surface which contains the desired text.
	SDL_Color color{ 0xbb, 0xbb, 0xbb, 0xff };
	auto surface = TTF_RenderText_Blended(font, text.c_str(), color);
	if (surface == nullptr) {
		std::cerr << "Unable to create a surface with a text: " << TTF_GetError() << std::endl;
		return nullptr;
	}

	// create a texture from the text surface.
	auto texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr) {
		std::cerr << "Unable to create texture from a text surface: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	return texture;
}