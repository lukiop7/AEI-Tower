#include "Pause.h"

Pause::Pause()
{
	Load("images/paused.png");
}

Pause::~Pause()
{
}

void Pause::show(sf::RenderWindow& renderWindow) {
	Screen::Show(renderWindow);
	renderWindow.display();
}

