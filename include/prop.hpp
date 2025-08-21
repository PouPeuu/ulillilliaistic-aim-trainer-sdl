#ifndef PROP_H
#define PROP_H

#include <SDL3/SDL_render.h>
class Prop {
	private:
		int x, y;
	public:
		virtual void render(SDL_Renderer *renderer) = 0;
};

#endif
