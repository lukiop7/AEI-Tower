/**
 * @file Options.h
 * @brief Options class.
* @author Lukasz Kwiecien
 */
#pragma once
#include "Screen.h"
#include <list>

 /** @class Options
 * A class that shows the options screen. Allows user to disable or enable sounds of the player and the game music.
 * Inherits publicly Screen.
 */

class Options :public Screen
{
public:
	/**
	*Constructor.
	*/
	Options();
	/**
	*Destructor.
	*/
	~Options();
	/**
	*Enum representing possible return values the options could return.
	*/
	enum OptionsResult { Exit, Back };
	/**
	*Calls screen show function and displays the sprite in the window.
	*@param window render window.
	*/
	void Show(sf::RenderWindow& window);
	/**
	*Highlights the currently selected option.
	*@param x currently selected option.
	*/
	void UpdateChoice(int x);
	/**
	*Disables or enables music or sounds depending on selected option and its current value.
	*@param x currently selected option.
	*@param y current value of the chosen option, if 1 - enabled if 0 - disabled.
	*/
	void UpdateOption(int x, int y);
	/**
	*Handles user input and calls appropriate functions based on user choice.
	*@param window render window.
	*@return options state.
	*/
	OptionsResult Option(sf::RenderWindow& window);
	int _music, _sound;
	/**
	*Struct representing options menu items.
	*/
	struct OptionsItem {
	public:
		sf::Text* text; ///< pointer to a text.
		int nb; ///< number of the option.
		std::string second;///< string for storing currently unused string(the opposite of current value of option: on or off).
		/**
		*overloaded = operator for changing color of the text.
		*/
		void operator=(const sf::Color c) {
			text->setFillColor(c);
		}
		/**
		*overloaded = operator for swapping the strings of the item.
		*/
		void operator=(std::string s) {
			std::string tmp = text->getString();
			text->setString(s);
			second = tmp;
		}


	};
private:
	sf::Font font;
	sf::Text text_sound;
	sf::Text text_music;
	std::list<OptionsItem> _optionsItems; ///<list of type OptionsItem, stores items that compose the options menu.
};

