#ifndef TEXT_H
#define TEXT_H

#include <string>

class Text {
	private:
		std::string text;
		int size;
		std::string font_path;
	public:
		Text(std::string text = "", int size = 12, std::string font_path = "res/");

		void setText(std::string text);
		void setSize(int size);
		void setFont(std::string font_path);

		std::string getText();
		int getSize();
		std::string getFont();
};

#endif
