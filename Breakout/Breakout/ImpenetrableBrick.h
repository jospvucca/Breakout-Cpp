#pragma once
#ifndef __IMPENETRABLE_BRICK_H__
#define __IMPENETRABLE_BRICK_H__

#include "Brick.h"

class ImpenetrableBrick : public Brick {
	void displayInfo() const override;
};

#endif // !__IMPENETRABLE_BRICK_H__