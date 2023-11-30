#include "IntroScene.h"
#include <string>

IntroScene::IntroScene() {
	std::cout << "---> IntroScene::ctor ---> Creating Intro scene: TODO" << std::endl;
}

IntroScene::~IntroScene() {
	std::cout << "---> IntroScene::~IntroScene ---> Destroying Intro Scene." << std::endl;
	//TODO - destroy textures connected to the scene
}

void IntroScene::update(float dt) const {
	std::cout << "---> IntroScene::update ---> TODO" << std::endl;
}

void IntroScene::render() const {
	std::cout << "---> IntroScene::render ---> TODO" << std::endl;
}

void IntroScene::enter() const {
	std::cout << "---> IntroScene::enter ---> TODO" << std::endl;
}

void IntroScene::exit() const {
	std::cout << "---> IntroScene::exit ---> TODO" << std::endl;
}

//TODO - it should probably be better to have GameStateManager with KeyInputManager as parents to game, so when in update of game a key is pressed, it doesnt call this method but method in managers, and it loads a new scene
void IntroScene::onKeyUp(SDL_KeyboardEvent& event) const {
	std::cout << "---> IntroScene::onKeyUp ---> Key event happened: " + event.keysym.sym << std::endl;

	//TODO - refine logic for key presses, for now only load new scene
	switch (event.keysym.sym) {
	case SDLK_p:
		std::cout << "---> IntroScene::onKeyUp ---> Key P pressed: " + std::to_string(event.keysym.sym) + ". Should load playable scene with level." << std::endl;
		break;

	default:
		std::cout << "---> IntroScene::onKeyUp ---> No action expected on key pressed: " + event.keysym.sym << std::endl;
		break;
	}
}

void IntroScene::onKeyDown(SDL_KeyboardEvent& event) const {

}