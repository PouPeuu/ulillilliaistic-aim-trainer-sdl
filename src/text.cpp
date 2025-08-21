#include "text.hpp"

Text::Text(std::string text, int size, std::string font_path) :
	text(text), size(size), font_path(font_path) {};

void Text::setText(std::string text) {
	this->text = text;
}

void Text::setSize(int size) {
	this->size = size;
}

void Text::setFont(std::string font_path) {
	this->font_path = font_path;
}


std::string Text::getText() {
	return this->text;
}

int Text::getSize() {
	return this->size;
}

std::string Text::getFont() {
	return this->font_path;
}
