#include "text_prop.hpp"

#include <SDL3_ttf/SDL_ttf.h>

TextProp::TextProp(int x, int y, std::string text, int size, TTF_Font *font) {
    this->x = x;
    this->y = y;
    this->text = text;
    this->size = size;
    this->font = font;
}

void TextProp::render(SDL_Renderer *render) {
    TTF_RenderText_Blended(this->font, this->text.c_str(), this->text.size(), tihs->);
}