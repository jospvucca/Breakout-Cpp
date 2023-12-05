#pragma once
#ifndef __SOFT_BRICK_H__
#define __SOFT_BRICK_H__

#include "Brick.h"
#include "Collidable.h"

class SoftBrick final : public Brick, public Collidable {
public:
	SoftBrick(Game& game);
	SoftBrick(const std::string& id, const std::string& texture,
		int hitpoints, const std::string& hitSound,
		const std::string& breakSound, int breakScore, Game& game);
	std::unique_ptr<Brick> clone(Game& game) override;
	~SoftBrick();
	void displayInfo() const override;

	const void decreaseHitpoints() override;
	void createCollidable(int x, int y, int w, int h, SDL_Color&& color) override;
	const Collidable& getCollidable() const override;
	void render(SDL_Renderer& renderer) const override;
};

#endif // !__SOFT_BRICK_H__
