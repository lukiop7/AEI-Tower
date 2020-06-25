#include "background.h"

background::background()
{
	Load("images/back.png");
}

background::~background()
{
}

void background::show(sf::RenderWindow& renderWindow) {
	Screen::Show(renderWindow);
}