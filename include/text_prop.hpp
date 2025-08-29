#ifndef TEXT_PROP_H
#define TEXT_PROP_H

#include "prop.hpp"
#include "text.hpp"

class TextProp : Prop, Text {
	public:
		TextProp(int x, int y, std::string text = "", int size = 12, TTF_Font *font);

		void render(SDL_Renderer *renderer) override;
};

#endif
