#ifndef TEXT_H
#define TEXT_H

#include <SDL3_ttf/SDL_ttf.h>
#include <string>

class Text {
	protected:
		std::string text;
		int size;
		TTF_Font *font;
		SDL_FColor color;
	public:
		Text(TTF_Font *font, std::string text = "", int size = 12, SDL_FColor color = {0, 0, 0, 0});

		void setText(std::string text);
		void setSize(int size);
		void setFont(TTF_Font *font);

		TTF_Font *getFont();
};

#endif
