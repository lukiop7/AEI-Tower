/**
 * @file Game.h
 * @brief Main Game class.
* @author Lukasz Kwiecien
 */
#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "GOManager.h"
#include "Pause.h"
#include "background.h"
#include "HUD.h"
#include "Options.h"
#include "MainMenu.h"

 /** @class Game
 * The heart of the game. It contains the game loop. Initializes the window and all necessary objects. Calls appropriate functions from other classes. */

class Game
{

public:
	/**
	*Creates game window and views. Sets the gamestate and starts the game loop.
	*/
	static void Start();
	/**
	*Initializes game objects: player and platforms.
	*/
	static void initialize();
	/**
	*Deletes player and platforms objects. Function is called when the game is over and main menu is about to be displayed.
	*"Prepares" the game for initialized later.
	*/
	static void Destructing();
	const static int SCREEN_WIDTH = 640; ///< width of the screen.
	const static int SCREEN_HEIGHT = 480; ///< height of the screen.
private:
	/**
	*Checks if the game state is equal to exiting.
	*@return true if yes otherwise false.
	*/
	static bool IsExiting();
	/**
	*Game loop calls functions depending on the current gamestate.
	*For example when gamestate is equal to "Playing" calls all necessary update and draw functions.
	*/
	static void GameLoop();
	/**
	*Calls function responsible for showing the pause screen.
	*/
	static void ShowPause();
	/**
	*Calls function responsible for showing the Main Menu and changes the gamestate based on the user choice in the Menu.
	*/
	static void ShowMenu();
	/**
	*Calls function responsible for showing the game over screen.
	*/
	static void ShowOver();
	/**
	*Calls function responsible for showing the Options Menu. Changes the gamestate and enable or disable music based on the user choice.
	*/
	static void ShowOptions();
	/**
     * Enum representing the states that game can be in.
     */
	enum  GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting, Over, ShowingOptions
	};

	static GameState _gameState; 
	static sf::RenderWindow _mainWindow; ///< game window.
	static GOManager _gameObjectManager;
	static sf::View _mainview; ///< view for displaying V_Objects objects.
	static sf::View _HUDview; ///< view for displaying HUD.
	static Pause _pauseScreen;
	static background _backScreen;
	static HUD _HUD;
	static sf::Music _music; ///< Music.
	static Options _options;
};
