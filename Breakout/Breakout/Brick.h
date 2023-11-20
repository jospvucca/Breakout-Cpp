#pragma once
#ifndef __BRICK_H__
#define __BRICK_H__

#include <iostream>
#include <optional>

class Brick {
public:
	~Brick() = default;
	virtual void displayInfo() const = 0;
	virtual void onHit() const = 0;
	virtual void onBreak() const = 0;
	//virtual int getHitpoints() const = 0;

private:
	std::string id;		//Maybe not needed
	std::string texture;
	std::optional<int> hitpoints;
	std::string hitSound;
	std::optional<std::string> breakSound;
	std::optional<int> breakScore;
};

#endif // !__BRICK_H__
