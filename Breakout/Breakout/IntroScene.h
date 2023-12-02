#pragma once
#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "Scene.h"
#include "Game.h"

class IntroScene final : public Scene {
public:
	IntroScene() = default;
	IntroScene(Game& game);
	~IntroScene();

	void update(float dt) override;
	void render() const override;
	void enter() const override;
	void exit() const override;
	void onKeyUp(SDL_KeyboardEvent& event) override;
	void onKeyDown(SDL_KeyboardEvent& event) override;

private:
    SDL_Texture* nameText;
    SDL_Texture* controlsText;
    SDL_Texture* spacebarText;
    SDL_Texture* leftArrowText;
    SDL_Texture* rightArrowText;
    SDL_Texture* playerGameText;

    SDL_Rect nameTextPosition;
    SDL_Rect controlsTextPosition;
    SDL_Rect spacebarTextPosition;
    SDL_Rect leftArrowTextPosition;
    SDL_Rect rightArrowTextPosition;
    SDL_Rect playerGameTextPosition;
};

#endif // !__INTRO_SCENE_H__
