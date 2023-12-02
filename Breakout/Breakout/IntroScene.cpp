#include "IntroScene.h"
#include "LevelScene.h"
#include <string>

IntroScene::IntroScene(Game& game) :
	Scene(game),
	nameText(nullptr), 
	controlsText(nullptr),
	spacebarText(nullptr),
	leftArrowText(nullptr),
	rightArrowText(nullptr), 
	playerGameText(nullptr) {
	std::cout << "---> IntroScene::ctor ---> Creating Intro scene: TODO" << std::endl;

	//Creating text textures for rendering text
	nameText = game.createText("Intro Scene");
	controlsText = game.createText("Controls: ");
	spacebarText = game.createText("Press space to play.");
	leftArrowText = game.createText("Press left arrow to move paddle left.");
	rightArrowText = game.createText("Press right arrow to move padde right.");
	playerGameText = game.createText("Hello player!");

	//Texture dimensions - calculated by SDL
	SDL_QueryTexture(nameText, nullptr, nullptr, &nameTextPosition.w, &nameTextPosition.h);
	SDL_QueryTexture(nameText, nullptr, nullptr, &controlsTextPosition.w, &controlsTextPosition.h);
	SDL_QueryTexture(nameText, nullptr, nullptr, &spacebarTextPosition.w, &spacebarTextPosition.h);
	SDL_QueryTexture(nameText, nullptr, nullptr, &leftArrowTextPosition.w, &leftArrowTextPosition.h);
	SDL_QueryTexture(nameText, nullptr, nullptr, &rightArrowTextPosition.w, &rightArrowTextPosition.h);
	SDL_QueryTexture(nameText, nullptr, nullptr, &playerGameTextPosition.w, &playerGameTextPosition.h);

	//Calculating center of the window
	int windowWidth, windowHeight;
	SDL_GetWindowSize(game.getWindow(), &windowWidth, &windowHeight);
	int windowCenterX = windowWidth / 2;
	int windowCenterY = windowHeight / 2;

	//TODO - align text in center
	  // assign texts at the center of the screen.
	#define CENTER(rect) (rect.x = windowCenterX - (rect.w / 2));
	CENTER(nameTextPosition);
	CENTER(controlsTextPosition);
	CENTER(spacebarTextPosition);
	CENTER(leftArrowTextPosition);
	CENTER(rightArrowTextPosition);
	CENTER(playerGameTextPosition);


	// assign vertical positions for each texture.
	int slotHeight = (windowHeight / 10);
	nameTextPosition.y = slotHeight;
	controlsTextPosition.y = static_cast<int>(2.5 * slotHeight);
	spacebarTextPosition.y = (3 * slotHeight);
	leftArrowTextPosition.y = static_cast<int>(3.5 * slotHeight);
	rightArrowTextPosition.y = (4 * slotHeight);
	playerGameTextPosition.y = (6 * slotHeight);
}

IntroScene::~IntroScene() {
	std::cout << "---> IntroScene::~IntroScene ---> Destroying Intro Scene." << std::endl;
	
	if (nameText != nullptr) {
		SDL_DestroyTexture(nameText);
	}
	if (nameText != nullptr) {
		SDL_DestroyTexture(controlsText);
	}
	if (nameText != nullptr) {
		SDL_DestroyTexture(spacebarText);
	}
	if (nameText != nullptr) {
		SDL_DestroyTexture(leftArrowText);
	}
	if (nameText != nullptr) {
		SDL_DestroyTexture(rightArrowText);
	}
	if (nameText != nullptr) {
		SDL_DestroyTexture(playerGameText);
	}
}

void IntroScene::update(float dt) {
	//std::cout << "---> IntroScene::update ---> TODO" << std::endl;
}

void IntroScene::render() const {
	//std::cout << "---> IntroScene::render ---> TODO" << std::endl;
	  // get a reference to the SDL renderer.
	auto& renderer = game.getRenderer();

	// draw all texts on the buffer.
	SDL_RenderCopy(&renderer, nameText, nullptr, &nameTextPosition);
	SDL_RenderCopy(&renderer, controlsText, nullptr, &controlsTextPosition);
	SDL_RenderCopy(&renderer, spacebarText, nullptr, &spacebarTextPosition);
	SDL_RenderCopy(&renderer, leftArrowText, nullptr, &leftArrowTextPosition);
	SDL_RenderCopy(&renderer, rightArrowText, nullptr, &rightArrowTextPosition);
	SDL_RenderCopy(&renderer, playerGameText, nullptr, &playerGameTextPosition);
}

void IntroScene::enter() const {
	std::cout << "---> IntroScene::enter ---> TODO" << std::endl;
}

void IntroScene::exit() const {
	std::cout << "---> IntroScene::exit ---> TODO" << std::endl;
}

//TODO - it should probably be better to have GameStateManager with KeyInputManager as parents to game, so when in update of game a key is pressed, it doesnt call this method but method in managers, and it loads a new scene
void IntroScene::onKeyUp(SDL_KeyboardEvent& event) {
	std::cout << "---> IntroScene::onKeyUp ---> Key event happened: " + event.keysym.sym << std::endl;

	//TODO - refine logic for key presses, for now only load new scene
	switch (event.keysym.sym) {
	case SDLK_p:
		std::cout << "---> IntroScene::onKeyUp ---> Key P pressed: " + std::to_string(event.keysym.sym) + ". Should load playable scene with level." << std::endl;
		game.loadScene(std::make_shared<LevelScene>(game));
		break;

	default:
		std::cout << "---> IntroScene::onKeyUp ---> No action expected on key pressed: " + event.keysym.sym << std::endl;
		break;
	}
}

void IntroScene::onKeyDown(SDL_KeyboardEvent& event) {

}