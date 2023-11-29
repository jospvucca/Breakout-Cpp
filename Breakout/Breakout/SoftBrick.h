#pragma once
#ifndef __SOFT_BRICK_H__
#define __SOFT_BRICK_H__

#include "Brick.h"

class SoftBrick final : public Brick {
public:
	SoftBrick() = default;
	SoftBrick(const std::string& id, const std::string& texture,
		int hitpoints, const std::string& hitSound,
		const std::string& breakSound, int breakScore);
	std::unique_ptr<Brick> clone() const override;
	void displayInfo() const override;
};

#endif // !__SOFT_BRICK_H__
