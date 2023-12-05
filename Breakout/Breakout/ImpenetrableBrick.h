#pragma once
#ifndef __IMPENETRABLE_BRICK_H__
#define __IMPENETRABLE_BRICK_H__

#include "Brick.h"
#include "Collidable.h"

class ImpenetrableBrick final : public Brick, public Collidable {
public:
	ImpenetrableBrick(Game& game);
	ImpenetrableBrick(const std::string& id, const std::string& texture, const std::string& hitSound, Game& game);
	std::unique_ptr<Brick> clone(Game& game) override;
	void displayInfo() const override;

	const void decreaseHitpoints() override;
	void createCollidable(int x, int y, int w, int h, SDL_Color&& color) override;
	const Collidable& getCollidable() const override;
	void render(SDL_Renderer& renderer) const override;
};

#endif // !__IMPENETRABLE_BRICK_H__
