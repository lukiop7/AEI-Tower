/**
 * @file V_Object.h
 * @brief Visible Object Class.
* @author Lukasz Kwiecien
 */
#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>

 /** @class V_Object
 * Abstract class for objects visible on the screen. Handles loading images, drawing, updating and changing position of the object.
 * Each displayed object inherits from this class.
 */

class V_Object {
public:
	/**
	*Constructor.
	*/
	V_Object();
	/**
	*Virtual destructor.
	*/
	virtual ~V_Object();
	/**
	* If possible loads the image from the file to the sprite.
	*@param filename name of the file.
	*/
	virtual void Load(std::string filename);
	/**
	*If image was loaded draws sprite to the render window.
	*@param window render window.
	*/
	virtual void Draw(sf::RenderWindow& window);
	/**
	*Calls update function.
	*/
	virtual void Update();
	/**
	*Sets position of the sprite.
	*@param x position on the x axis.
	*@param y position on the y axis.
	*/

	//other functions are getters and setters.

	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f Getposition() const;
	virtual bool IsLoaded() const;
	virtual void SetOut(bool out);
	virtual bool IsOut() const;
	virtual float GetWidth() const;
	virtual float GetHeight() const;
	virtual sf::Rect<float> GetBoundingRect() const;

protected:
	sf::Sprite& GetSprite();
private:
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;
	bool _out;
};