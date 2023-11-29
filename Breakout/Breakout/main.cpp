// Breakout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "XMLParser.h"
#include "XMLFiles.h"
#include "LevelFactory.h"
#include <iostream>
#include "Game.h"
#include "Window.h"


//Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_Window* window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);

	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);
	//SDL_Delay(3000);

    std::cout << "File name: " + std::string(XMLFiles::LEVEL_ONE) << std::endl;

    int levelCounter = 1;

    XMLParser xmlParser(XMLFiles::LEVEL_ONE);
    ParseData levelConfigData = xmlParser.parseData();
    LevelConfig config = LevelConfig(levelCounter, levelConfigData.level.rowCount, levelConfigData.level.columnCount,
        levelConfigData.level.rowSpacing, levelConfigData.level.columnSpacing, levelConfigData.level.backgroundTexture, levelConfigData.positions.brickPositions);

    std::unique_ptr<Level> currentLevel = LevelFactory::createLevelFromConfig(1, config);
    
    std::cout << "Hello World!\n";

	Game game = Game(600, 480, "nullptr", "Breakout");
	while (game.run()) {

	}


	//SDL_QUIT();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


/*

Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Hack to get window to stay up
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

*/