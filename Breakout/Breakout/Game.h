#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "State.h"
#include "Scene.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "LevelConfig.h"
#include "ParseData.h"

class Game final {  //TODO - create game a singleton type with method start(getInstance), possibly static with scene as main guy with additional class with window/renderer(my idea is thats how game engines work behind the scenes) - but i wont have time probably
public:
    Game() = default;
    Game(const Game&) = delete;     //TODO - forgot to add copy const delete variance and operator = to singletons and others that should not be created that way
    Game(Game&&) = delete;
    Game& operator=(const Game&) = delete;
    Game& operator=(Game&&) = delete;

    Game(const int width, const int height, const char* fontPath, const char* title, const LevelConfig& levelConfig, const ParseData& levelParseData);
	~Game();

    void loadScene(std::shared_ptr<Scene> scene);
    SDL_Renderer& getRenderer() const { return *renderer; }
    SDL_Window* getWindow() const { return window; }
    std::shared_ptr<Scene> getScene() { return scene; }
    int update();

    SDL_Texture* createText(const std::string& text);

    const LevelConfig getLevelConfig() const { return std::move(levelConfig); }
    ParseData getParseData() { return parseData; }

private:
    SDL_Window* window;     //TODO - This and renderer should def be singletons, ensure in later stages of development
    SDL_Renderer* renderer;
    std::shared_ptr<Scene> scene;
    State state;

    TTF_Font* font;

    unsigned long currentTickMillis;
    unsigned long previousTickMillis;
    unsigned long deltaTime;

    LevelConfig levelConfig;
    ParseData parseData;
};

#endif // !__GAME_H__
