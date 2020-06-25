/**
 * @file HUD.h
 * @brief HUD class. 
* @author Lukasz Kwiecien
 */
#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Player.h"
#include "Screen.h"
#include <sstream>
 /** @class HUD
 * Displays score and the game over screen.
 *Inherits Screen publicly.*/
class HUD: public Screen
{
public:
	/**
	*Constructor.
	*/
	HUD();
	/**
	*Destructor.
	*/
	~HUD();
	/**
	*Sets pointer to a player.
	*@param player pointer to a player.
	*/
	void SetPlayer(Player* player);
	/**
	*Displays players score in the window.
	*@param window render window.
	*/
	void showScore(sf::RenderWindow& window);
	/**
	*Calls screen show function and displays the sprite in the window.
	*@param window render window.
	*/
	void Show(sf::RenderWindow& window);
private:
	sf::Font font;
	sf::Text text;
	sf::Text textOver;
	Player* _player; ///< pointer to a player.



};

