#include "Drawable.h"
#include <string>

Drawable::Drawable(Game& game) : Object(game), color({ 255, 255, 255, 255 }), visible(true) {
	std::cout << "---> Drawable::ctor(game) ---> Creating a Drawable Object." << std::endl;
}

Drawable::~Drawable() {
	Object::~Object();
}

void Drawable::render(SDL_Renderer& renderer) const {
	//std::cout << "---> Drawable::render ---> Rendering rectangle with color: (" +
	//	std::to_string(color.r) + "," + std::to_string(color.g) + "," + std::to_string(color.b) + "," + std::to_string(color.a) + ")." << std::endl;
	if (visible) {
		SDL_SetRenderDrawColor(&renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(&renderer, &rect);
	}
}