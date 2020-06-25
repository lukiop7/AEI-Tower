#include "HUD.h"

HUD::HUD()
{
	Load("images/over.png");
	_player = nullptr;
	font.loadFromFile("comic.ttf");
	text.setFont(font);
	textOver.setFont(font);
	text.setCharacterSize(20);
	textOver.setCharacterSize(60);
	textOver.setFillColor(sf::Color::Red);
	text.setFillColor(sf::Color::White);
	text.setPosition(10, 30);
}

HUD::~HUD()
{
}

void HUD::SetPlayer(Player* player)
{
	_player = player;
}

void HUD::showScore(sf::RenderWindow& window)
{
	text.setString("SCORE: " + std::to_string(_player->GetLvl() * 10));
	window.draw(text);
}

void HUD::Show(sf::RenderWindow& window)
{
	textOver.setPosition(321, 165);
	Screen::Show(window);
	textOver.setString(std::to_string(_player->GetLvl()));
	window.draw(textOver);
	textOver.setPosition(321, 226);
	textOver.setString(std::to_string(_player->GetLvl() * 10));
	window.draw(textOver);
	window.display();
}
