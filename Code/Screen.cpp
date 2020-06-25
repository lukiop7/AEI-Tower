#include "Screen.h"

void Screen::Load(std::string filename)
{
	if (_image.loadFromFile(filename)) {
		_sprite.setTexture(_image);
		_filename = filename;
	}
}

void Screen::Show(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

sf::Sprite& Screen::GetSprite()
{
	return _sprite;
}
