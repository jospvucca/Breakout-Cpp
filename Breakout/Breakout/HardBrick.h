#pragma once
#ifndef __HARD_BRICK_H__
#define __HARD_BRICK_H__

#include "Brick.h"
#include "Collidable.h"

class HardBrick final : public Brick, public Collidable {
public:
	HardBrick(Game& game);
	HardBrick(const std::string& id, const std::string& texture,
		int hitpoints, const std::string& hitSound,
		const std::string& breakSound, int breakScore, Game& game);
	std::unique_ptr<Brick> clone(Game& game) const override;
	void displayInfo() const override;

	void createCollidable(int x, int y, int w, int h, SDL_Color&& color) override;
	void render(SDL_Renderer& renderer) const override;
};

#endif // !__HARD_BRICK_H__
