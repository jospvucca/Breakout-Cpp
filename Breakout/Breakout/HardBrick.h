#pragma once
#ifndef __HARD_BRICK_H__
#define __HARD_BRICK_H__

#include "Brick.h"

class HardBrick : public Brick {
	HardBrick(const std::string& id, const std::string& texture,
		int hitpoints, const std::string& hitSound,
		const std::string& breakSound, int breakScore);
	void displayInfo() const override;
};

#endif // !__HARD_BRICK_H__
