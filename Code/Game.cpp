#include "Game.h"
#include "Pause.h"
#include "Player.h"
#include "background.h"
#include "HUD.h"
#include "Platform.h"
#include <iostream>

void Game::Start() {
	if (_gameState != Uninitialized)
		return;
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Essa!");
	_mainview.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	_mainview.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	_HUDview.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	_HUDview.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	_mainWindow.setFramerateLimit(60);
	_gameState = Game::ShowingMenu;
	_music.openFromFile("sounds/intro.wav");
	_music.setLoop(true);
	_music.play();
	while (!IsExiting()) {
		GameLoop();
	}
	_mainWindow.close();
}

void Game::initialize()
{
	int a = 1;

	if (_options._sound == 0)
		a = 0;
	else
		a = 1;
	Player* player1 = new Player(a);
	_HUD.SetPlayer(player1);
	player1->SetPosition((640 / 2), 416);
	_gameObjectManager.Add("player", player1);
	Platform* platform[6];
	for (int i = 0; i < 6; i++) {
		platform[i] = new Platform(i, player1);
		std::string name = "platform " + std::to_string(i);
		_gameObjectManager.Add(name, platform[i]);
	}
}

void Game::Destructing()
{
	_gameObjectManager.Remove("player");
	for (int i = 0; i < 6; i++) {
		std::string name = "platform " + std::to_string(i);
		_gameObjectManager.Remove(name);
	}
}

bool Game::IsExiting() {
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event currentEvent;


	_mainWindow.pollEvent(currentEvent);
	switch (_gameState)
	{
	case Game::Playing:
	{
		_music.setVolume(20);
		if (_gameObjectManager.Get("player")->IsOut() == true)
		_gameState = Game::Over;
		_mainWindow.setView(_HUDview);
		_mainWindow.clear(sf::Color(0, 0, 0));
		_backScreen.show(_mainWindow);
		_HUD.showScore(_mainWindow);
		_mainWindow.setView(_mainview);
		_gameObjectManager.UpdateAll();
		_gameObjectManager.DrawAll(_mainWindow);
		_mainWindow.display();

		if (currentEvent.type == sf::Event::Closed)
		{
			_gameState = Game::Exiting;
		}
		if (currentEvent.type == sf::Event::KeyPressed) {
			if (currentEvent.key.code == sf::Keyboard::Escape)
				_gameState = Game::Paused;
		}
		break;
	}
	case Game::ShowingMenu:
	{
		_music.setVolume(100);
		ShowMenu();
		break;
	}
	case Game::ShowingOptions:
	{
		ShowOptions();
		break;
	}
	case Game::Paused:
	{
		ShowPause();
		if (currentEvent.type == sf::Event::Closed)
		{
			_gameState = Game::Exiting;
		}
		if (currentEvent.type == sf::Event::KeyPressed) {
			if (currentEvent.key.code == sf::Keyboard::Escape) {
				Destructing();
				_gameState = Game::ShowingMenu;

			}
			else {
				_gameState = Game::Playing;
			}
		}
		break;
	}
	case Game::Over:
	{
		ShowOver();
		if (currentEvent.type == sf::Event::Closed)
		{
			_gameState = Game::Exiting;
		}
		if (currentEvent.type == sf::Event::KeyPressed) {
			Destructing();
			_gameState = Game::ShowingMenu;
		}
		break;
	}
	}
}

void Game::ShowPause() {
	_pauseScreen.show(_mainWindow);
}

void Game::ShowMenu() {
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result) {
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		initialize();
		_gameState = Game::Playing;
		break;
	case MainMenu::Options:
		_gameState = Game::ShowingOptions;
		break;
	}
}

void Game::ShowOver()
{
	_HUD.Show(_mainWindow);
}

void Game::ShowOptions()
{
	Options::OptionsResult result = _options.Option(_mainWindow);
	switch (result) {
	case Options::Exit:
		_gameState = Game::Exiting;
		break;
	case Options::Back:
		_gameState = Game::ShowingMenu;
		if (_options._music == 0)
			_music.stop();
		else
			_music.play();
		break;

	}
}


Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GOManager Game::_gameObjectManager;
sf::View Game::_mainview;
sf::View Game::_HUDview;
Pause Game::_pauseScreen;
background Game::_backScreen;
HUD Game::_HUD;
sf::Music Game::_music;
Options Game::_options;
