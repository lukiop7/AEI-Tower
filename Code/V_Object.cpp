#include "V_Object.h"

V_Object::V_Object() {
	_isLoaded = false;
}

V_Object::~V_Object() {}

void V_Object::Load(std::string filename) {
	if (!_image.loadFromFile(filename)) {
		_filename = "";
		_isLoaded = false;
	}
	else {
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void V_Object::Draw(sf::RenderWindow& window) {

	if (_isLoaded) {
		window.draw(_sprite);
	}
}

void V_Object::Update()
{
}

void V_Object::SetPosition(float x, float y) {

	if (_isLoaded) {
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f V_Object::Getposition() const
{
	if (_isLoaded) {
		return _sprite.getPosition();
	}

	return sf::Vector2f();
}

bool V_Object::IsLoaded() const
{
	return _isLoaded;
}

void V_Object::SetOut(bool out)
{
	_out = out;
}

bool V_Object::IsOut() const
{
	return _out;
}

float V_Object::GetWidth() const
{
	return _sprite.getLocalBounds().width;
}

float V_Object::GetHeight() const
{
	return _sprite.getLocalBounds().height;
}

sf::Rect<float> V_Object::GetBoundingRect() const
{
	return _sprite.getGlobalBounds();
}

sf::Sprite& V_Object::GetSprite()
{
	return _sprite;
}
