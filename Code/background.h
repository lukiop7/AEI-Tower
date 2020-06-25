/**
 * @file Background.h
 * @brief Background screen class.
* @author Lukasz Kwiecien
 */
#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Screen.h"

 /** @class background
 * A class that shows the game background.
 *Inherits Screen publicly. */

class background: public Screen
{
public:
    /**
    *Constructor.
    */
	background();
    /**
    *Destructor.
    */
	~background();
    /**
    *Calls screen show function and displays the sprite in the window.
    *@param window render window.
    */
	void show(sf::RenderWindow& window);

};