#pragma once
#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include "Object.h"

class Drawable : public Object {
public:
	Drawable(Game& game);
	virtual ~Drawable() = default;
	
	virtual void render(SDL_Renderer& renderer) const;

	bool isVisible() const { return visible; }
	const SDL_Color& getColor() const { return color; }

	void setVisible(bool vis) { visible = vis; }	//TODO - not sure if i should have these methods or even keep it public
	void setColor(SDL_Color& col) { color = col; }

protected:
	SDL_Color color;
	bool visible;
};
#endif // !__DRAWABLE_H__
