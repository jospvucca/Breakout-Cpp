#pragma once
#ifndef __MEDIUM_BRICK_H__
#define __MEDIUM_BRICK_H__

#include "Brick.h"

class MediumBrick final : public Brick {
public:
	MediumBrick() = default;
	MediumBrick(const std::string& id, const std::string& texture,
		int hitpoints, const std::string& hitSound,
		const std::string& breakSound, int breakScore);
	std::unique_ptr<Brick> clone() const override;
	void displayInfo() const override;

	void createCollidable(int x, int y, int w, int h, SDL_Color&& color) override;
};

#endif // !__MEDIUM_BRICK_H__
