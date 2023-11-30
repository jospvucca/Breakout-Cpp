#pragma once
#ifndef __COLLIDABLE_H__
#define __COLLIDABLE_H__

#include "Drawable.h"

class Collidable : public Drawable {
public:
	Collidable(Game& game);
	virtual ~Collidable() = default;

	bool onCollision(const Collidable& other) const;

	void setX(const int x) override;
	void setY(const int y) override;
	void setWidth(const int w) override;
	void setHeight(const int h) override;

	const bool isEnabled() const {}
	const int getCollisionBoxX() const { return cbX; }
	const int getCollisionBoxY() const { return cbY; }
	//TODO add field for center and getters and setters

	void setEnabled(const bool isEnabled) { enabled = isEnabled; }
	void setCollisionBoxX(const int x) { cbX = x; }
	void setCollisionBoxY(const int y) { cbY = y; }

private:
	bool enabled;
	int cbX;
	int cbY;
};

#endif // !__COLLIDABLE_H__
