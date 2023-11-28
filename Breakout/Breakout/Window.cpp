#include "Window.h"
#include <iostream>

Window::Window(const char* title, int width, int height) {
	std::cout << "TODO: switch to singleton." << std::endl;

	//Window
	if (this->window == nullptr) {
		std::cout << "---> Window::ctor() ---> Instance of a Window does not exist. Creating new Window..." << std::endl;

		this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if (!this->window) {
			std::cerr << "---! Window::ctor() ---! Error creating SDL window." << SDL_GetError() << std::endl;
		}
	}

	//Renderer - should this be its own class?    ---> I dislike this implementation, I would def change it to either both be part of the game class or each own class
	std::cout << "TODO: switch to singleton." << std::endl;
	if (this->renderer == nullptr) {
		std::cout << "---> Window::ctor() ---> Instance of SDL_Renderer does not exist. Creating new renderer..." << std::endl;

		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!this->renderer) {
			std::cerr << "---! Window::ctor() ---! Error creating SDL renderer." << SDL_GetError() << std::endl;
		}
	}
}

Window::~Window() {
	std::cout << "---> Window::~Window() ---> Cleaning up Window." << std::endl;
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void Window::HandleEvents() {
	std::cout << "---> Window::HandleEvents() ---> TODO." << std::endl;
}

void Window::Clear() {
	std::cout << "---> Window::Clear() ---> TODO." << std::endl;
}

void Window::Render() {
	std::cout << "---> Window::Render() ---> TODO." << std::endl;
}

void Window::Present() {
	std::cout << "---> Window::Present() ---> TODO." << std::endl;
}