#pragma once
#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL.h>

class Window {
public:
	Window(const char* title, int width, int height);
	~Window();

	void HandleEvents();
	void Clear();
	void Render();
	void Present();

private:
	SDL_Window* window;		//This should be singleton
	SDL_Renderer* renderer;
};

#endif // !__WINDOW_H__
