#pragma once
#ifndef __BRICK_H__
#define __BRICK_H__

#include <iostream>
#include <optional>
#include <SDL.h>

class Game;
class Collidable;

class Brick {
public:
	//~Brick() = default;
	virtual std::unique_ptr<Brick> clone(Game& game) = 0;
	virtual void displayInfo() const = 0;
	//Brick(const Brick&) = delete;
	//Brick& operator=(const Brick&) = delete;

	//virtual void onHit() const = 0;
	//virtual void onBreak() const = 0;
	//virtual int getHitpoints() const = 0;

	virtual const void decreaseHitpoints() = 0;
	virtual void createCollidable(int x, int y, int w, int h, SDL_Color&& color) = 0;
	virtual const Collidable& getCollidable() const = 0;
	virtual void render(SDL_Renderer& renderer) const = 0;

//protected:
	Brick() = default;
	Brick(const std::string& id, const std::string& texture,
		const std::optional<int> hitpoints, const std::string& hitSound,
		const std::optional<std::string> breakSound, const std::optional<int> breakScore);		//Should this be abstract?
	std::string id;		//Maybe not needed
	std::string texture;
	std::optional<int> hitpoints;
	std::string hitSound;
	std::optional<std::string> breakSound;
	std::optional<int> breakScore;
};

#endif // !__BRICK_H__
