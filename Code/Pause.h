/**
 * @file Pause.h
 * @brief Pause screen class.
* @author Lukasz Kwiecien
 */

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Screen.h"


 /** @class Pause
 * A class that shows the "game paused" screen. 
 * Inherits Screen publicly.
 */

class Pause: public Screen
{
public:
	/**
	*Constructor.
	*/
	Pause();
	/**
	*Destructor.
	*/
	~Pause();
	/**
	*Calls screen show function and displays the sprite in the window.
	*@param window render window.
	*/
	void show(sf::RenderWindow& window);
};