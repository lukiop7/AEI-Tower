/**
 * @file Platform.h
 * @brief Platform class.
* @author Lukasz Kwiecien
 */
#pragma once
#include "V_Object.h"
#include "Platform_Colors.h"
#include "Player.h"
#include "game.h"

 /** @class Platform
 * Responsible for platforms. Handles collision with the player, moves the entire map and generates platforms endlessly.
 * Because Platform is a visible object in the game, class inherits publicly V_Object.
 */

class Platform :
	public V_Object
{
public:
	/** Platform Constructor.
	*@param lvl initialization parameter for _lvl.
	*@param player pointer to Player object.
	*/
	Platform(int lvl, Player* player);
	/**
	*Platform destructor.
	*/
	~Platform();
	/**
	* Override V_Object Update() function. Moves platform and calls other functions(responsible for collisions, colors, speed etc.).
	*/
	void Update();
	/**
	* Draws sprite to the render window.
	*@param rw render window.
	*/
	void Draw(sf::RenderWindow& rw);
	/**
	*Sets appropriate color of the platform.
	*/
	void Color();
	/**
	*Changes _movespeed based on the level of the platform.
	*/
	void Speed();
	/**
	*Handles collision with the player.
	*/
	void Collision();
	/**
	*Checks if player is standing on the platform.
	*@return true if yes false if no.
	*/
	bool Collide();
	/**
	*When the platform is off screen, the function generates its new position, length and places the platform at the top of the screen.
	*/
	void Regenerate();
	/**
	*Generates length of the platform based on its position.
	*@param pos position of the platform(generated before).
	*@return length of the platform.
	*/
	int generatelength(int pos);
	/**
	*Generates position of the platform on the x axis.
	*@return position of the platform.
	*/
	int generatepos();
	/**
	*Overloaded operator.
	*Assigns the current platform level to the player level.
	*/
	Platform& operator =(Player* p);
private:
	float _movespeed;
	int _distance;
	int _lvl;
	int _ground;
	int _collision;
	float _gravity;
	Player* _player; ///< pointer to a Player object


};

