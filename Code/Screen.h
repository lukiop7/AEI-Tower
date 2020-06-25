/**
 * @file Screen.h
 * @brief Screen class.
 * @author Lukasz Kwiecien
 */
#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include<string>

/** @class Screen
* Abstract class which loads and displays screens used during the game.
* Each object displaying screen(except MainMenu) inherits from this class.
*/

class Screen
{
public:
	/**
	*Screen constructor.
	*/
	Screen() {};
	/**
	*Virtual destructor.
	*/
	virtual ~Screen() {};
	/**
	* If possible loads the image from the file to the sprite.
	*@param filename name of the file.
	*/
	virtual void Load(std::string filename);
	/**
	*Draws sprite to the render window.
	*@param window render window.
	*/
	virtual void Show(sf::RenderWindow& window);
protected:
	sf::Sprite& GetSprite();
private: 
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
};

