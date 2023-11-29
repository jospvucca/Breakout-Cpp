#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "State.h"
#include "Scene.h"
#include <SDL.h>
#include <iostream>

class Game final {  //TODO - create game a singleton type with method start(getInstance), possibly static with scene as main guy with additional class with window/renderer(my idea is thats how game engines work behind the scenes) - but i wont have time probably
public:
    Game() = delete;
    Game(const Game&) = delete;     //TODO - forgot to add copy const delete variance and operator = to singletons and others that should not be created that way
    Game& operator=(const Game&) = delete;
    Game& operator=(Game&&) = delete;

    Game(const int width, const int height, const std::string& fontPath, const char* title);       //TODO - dont think font is necessary, this can be changed to only title
	~Game();

    // - Logic related methods
    void loadScene(std::unique_ptr<Scene> scene);                   //This potentionally can be shared_ptr, TODO - decide after code implementation -> it will probably be easier with shared
    SDL_Renderer& getRenderer() const { return *renderer; }
    SDL_Window* getWindow() const { return window; }
    //std::unique_ptr<Scene> getScene() { return scene; }
    int update();

private:
    SDL_Window* window;     //TODO - This and renderer should def be singletons, ensure in later stages of development
    SDL_Renderer* renderer;
    std::unique_ptr<Scene> scene;
    State state;
};

#endif // !__GAME_H__
