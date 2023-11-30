#pragma once
#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "Scene.h"

class IntroScene final : public Scene {
public:
	IntroScene();
	~IntroScene();

	void update(float dt) const override;
	void render() const override;
	void enter() const override;
	void exit() const override;
	void onKeyUp(SDL_KeyboardEvent& event) const override;
	void onKeyDown(SDL_KeyboardEvent& event) const override;

private:
};

#endif // !__INTRO_SCENE_H__
