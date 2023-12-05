#pragma once
#ifndef __COLLIDABLE_H__
#define __COLLIDABLE_H__

#include "Drawable.h"

class Collidable : public Drawable {
public:
	Collidable(Game& game);
	~Collidable();

	bool onCollision(const Collidable& other) const;

	void setX(const int x) override;
	void setY(const int y) override;
	void setWidth(const int w) override;
	void setHeight(const int h) override;

	const bool isEnabled() const {}
	const int getExtendedX() const { return extendedX; }
	const int getExtendedY() const { return extendedY; }
	const int getCollisionBoxX() const { return cbX; }
	const int getCollisionBoxY() const { return cbY; }

	void setEnabled(const bool isEnabled) { enabled = isEnabled; }
	void setExtendedX(const int x) { extendedX = x; }
	void setExtendedY(const int y) { extendedY = y; }
	void setCollisionBoxX(const int x) { cbX = x; }
	void setCollisionBoxY(const int y) { cbY = y; }

protected:

	int extendedX;
	int extendedY;

	int cbX;
	int cbY;

private:
	bool enabled;

};

#endif // !__COLLIDABLE_H__
