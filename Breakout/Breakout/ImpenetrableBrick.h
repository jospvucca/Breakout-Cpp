#pragma once
#ifndef __IMPENETRABLE_BRICK_H__
#define __IMPENETRABLE_BRICK_H__

#include "Brick.h"

class ImpenetrableBrick : public Brick {
	ImpenetrableBrick(const std::string& id, const std::string& texture, const std::string& hitSound);
	void displayInfo() const override;
};

#endif // !__IMPENETRABLE_BRICK_H__
