/**
 * @file MainMenu.h
 * @brief Main Menu class. 
* @author Lukasz Kwiecien
 */
#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>

 /** @class MainMenu
 * Responsible for displaying the menu and changing the game state based on user's input.*/
class MainMenu {

public:
	/**
	 * Represents various possible return values the menu could return.
	 */
	enum MenuResult { Nothing, Exit, Play, Options };
	/**
	 * Struct that represents the individual menu items in the menu.
	 * Allows user to use mouse or arrow keys to choose the button.
	 */
	struct MenuItem {
	public:
		sf::Rect<int> rect;
		sf::Sprite* sprite; ///< pointer to a sprite.
		MenuResult action;
		int button;
		/**
		*Overloaded = operator for setting color of the sprite.
		*/
		void operator=(sf::Color c) {
			sprite->setColor(c);
		}


	};
	/**
	* Function loads a main-menu and buttons images and creates a sprites to display them.
	* @param window render window.
	* @return the main-menu state from the GetMenuResponse function called with window as a parameter.
	*/
	MenuResult Show(sf::RenderWindow& window);
private:
	sf::Texture image,play_text,exit_text,options_text;
	sf::Sprite sprite,play,exit,options;
	/**
	*Checks if any button was pressed. If not returns nothing.
	*@param x position of the mouse on the x axis.
	*@param y position of the mouse on the y axis.
	*@return menu state.
	*/
	MenuResult HandleClick(int x, int y);
	/**
	*Handles user mouse and keyboard input. Calls other functions based on the input.
	*@param window render window.
	*@return menu state.
	*/
	 MenuResult GetMenuResponse(sf::RenderWindow& window);
	 /**
	 *Responsible for returning menu state according to selected button.
	 *@param x currently selected button.
	 *@return menu state.
	 */
	MenuResult HandleKey(int x);
	/**
	*Highlight the selected button.
	*@param x currently selected button.
	*@param window render window.
	*/
	 void UpdateButton(int x, sf::RenderWindow& window);
	std::list<MenuItem> _menuItems;///< list of type MenuItem, stores items that compose the menu.
};