/**
 * @file Player.h
 * @brief Player class.
* @author Lukasz Kwiecien
 */
#pragma once
#include "V_Object.h"
#include "Animation.h"
#include "SFML/Audio.hpp"
#include "PitchedSound.h"

 /** @class Player
 * Handles Player collision with the walls, user input, movement, physics, animations and sounds.
 * Because Player is a visible object in the game, class inherits publicly V_Object.
 */

class Player :
	public V_Object {
public:
	/** Player Constructor.
	*@param a initialization parameter for _sound.
	*/
	Player(int a); 
	/**
	* Player destructor.
	*/
	~Player();
	/**
	* Override V_Object Update() function. Checks velocities and calls other functions(responsible for movement and animations etc.).
	*/
	void Update();
	/**
	* Draws sprite to the render window.
	*@param rw render window. 
	*/
	void Draw(sf::RenderWindow& rw);
	/**
	* Moves player by a given amount of pixels on x and y axis.
	*@param x offset on the x axis.
	*@param y offset on the y axis.
	*/
	void move(float x, float y);

	//other functions are getters and setters

	float GetVelocityX() const;
	float GetVelocityY() const;
	int GetJumpPower() const;
	void SetJumpPower(int x);
	int GetGround()const;
	void SetGround(int x);
	int  GetLvl() const;
	void SetLvl(int x);
	int GetOnEdge() const;
	void SetOnEdge(int x);
	bool GetOnGround() const;
	void SetOnGround(bool x);
	bool GetOnPlatform() const;
	void SetOnPlatform(bool x);
	bool GetStarting() const;
	void SetStarting(bool x);
	int GetMaxPlat() const;
	void SetMaxPlat(int x);
	float GetGravity() const;
	void SetGravity(float x);
private:
	/**
	* Updates animations and sounds of the player.
	*/
	void animation_sound();
	/**
	* Handles movement based on user's input.
	*/
	void checkMove();
	/**
	* Handles collision with walls.
	*/
	void boundaries();
	sf::SoundBuffer soundHop; ///< sound buffer for Hop sound.
	sf::SoundBuffer soundWhoopie;///< sound buffer for Whoopie sound.
	sf::SoundBuffer soundPrrah;///< sound buffer for Prrah sound.
	sf::SoundBuffer soundSkrrt;///< sound buffer for Skrrt sound.
	sf::SoundBuffer soundEssa;///< sound buffer for Essa sound.
	static PitchedSound sound;///< PitchedSound object for playing sounds.
	float _velocityX, _velocityY;
	float _maxvelocityX, _maxvelocityY;
	int _wallHit;
	float _animTime;
	int _jumpPower;
	int _ground, _lvl;
	int _onEdge;
	int _wallCounter;
	bool _onGround;
	bool _onPlatform;
	bool _starting;
	int _maxplat;
	float _gravity;
	int _sound;
	bool _out;

};