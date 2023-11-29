#pragma once
#ifndef __IMPENETRABLE_BRICK_H__
#define __IMPENETRABLE_BRICK_H__

#include "Brick.h"

class ImpenetrableBrick final : public Brick {
public:
	ImpenetrableBrick() = default;
	ImpenetrableBrick(const std::string& id, const std::string& texture, const std::string& hitSound);
	std::unique_ptr<Brick> clone() const override;
	void displayInfo() const override;
};

#endif // !__IMPENETRABLE_BRICK_H__
