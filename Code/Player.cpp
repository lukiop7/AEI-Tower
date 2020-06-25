#include "Player.h"
#include "Game.h"
#include <iostream>
#include <math.h>


Player::Player(int a) :_velocityX(0), _animTime(0), _velocityY(0), _maxvelocityX(6.0f), _maxvelocityY(6.0f), _ground(416), _gravity(0.2f), _onGround(true),
_wallHit(0), _lvl(0), _maxplat(5), _onPlatform(1), _jumpPower(0), _onEdge(0), _starting(true),_wallCounter(0), _sound(a)
{
	Load("images/sheet.png");
	_ASSERT(IsLoaded());
	GetSprite().setTextureRect(Animation::idle_1);
	GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height);
	SetOut(false);
	
	soundHop.loadFromFile("sounds/hop.wav");
	soundWhoopie.loadFromFile("sounds/woopie.wav");
	soundPrrah.loadFromFile("sounds/prrah.wav");
	soundSkrrt.loadFromFile("sounds/skrrt.wav");
	soundEssa.loadFromFile("sounds/essa.wav");
}

Player::~Player()
{
}

void Player::Update()
{
	if (_starting == true) {
		if (_sound == 1) {
			sound.setBuffer(soundEssa);
			sound.playPitched();
		}
		_starting = false;
	}

	animation_sound();
	if (GetSprite().getPosition().y > 538)
		SetOut(true);
	if (fabs(GetSprite().getPosition().y - _ground) < 5 && _onPlatform == true)
	{
		GetSprite().setPosition(GetSprite().getPosition().x, _ground);
		_velocityY = 0;
		_wallHit = 0;
		_wallCounter = 0;
		_onGround = true;

	}
	checkMove();
	boundaries();
	if (_velocityX > _maxvelocityX)
		_velocityX = _maxvelocityX;

	if (_velocityX < -_maxvelocityX)
		_velocityX = -_maxvelocityX;
	if (_velocityY != 0 && _onGround == true) {

	}

	GetSprite().move(_velocityX, _velocityY);

	if (_onGround == false) {
		if (_velocityY < _maxvelocityY) {
			_velocityY += _gravity;
		}
	}



}

void Player::Draw(sf::RenderWindow& rw)
{
	V_Object::Draw(rw);
}

void Player::move(float x, float y)
{
	GetSprite().move(x, y);
}

void Player::animation_sound()
{
	_animTime += 1;
	if (_animTime == 61)
		_animTime = 0;
	if (_velocityX < 0 && _onGround == true) {

		GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height);
		GetSprite().setRotation(0);
		if (_animTime <= 15)
			GetSprite().setTextureRect(Animation::walk_left_1);
		else if (_animTime <= 30)
			GetSprite().setTextureRect(Animation::walk_left_2);
		else if (_animTime <= 45)
			GetSprite().setTextureRect(Animation::walk_left_3);
		else if (_animTime <= 60)
			GetSprite().setTextureRect(Animation::walk_left_4);
	}
	if (_velocityX > 0 && _onGround == true) {

		GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height);
		GetSprite().setRotation(0);
		if (_animTime <= 15)
			GetSprite().setTextureRect(Animation::walk_right_1);
		else if (_animTime <= 30)
			GetSprite().setTextureRect(Animation::walk_right_2);
		else if (_animTime <= 45)
			GetSprite().setTextureRect(Animation::walk_right_3);
		else if (_animTime <= 60)
			GetSprite().setTextureRect(Animation::walk_right_4);
	}
	if (_velocityX == 0 && _onGround == true) {
		GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height);
		GetSprite().setRotation(0);
		if (_animTime <= 20)
			GetSprite().setTextureRect(Animation::idle_1);
		else if (_animTime <= 40)
			GetSprite().setTextureRect(Animation::idle_2);
		else if (_animTime <= 60)
			GetSprite().setTextureRect(Animation::idle_3);
	}
	if (_onGround == false) {
		if (_jumpPower == 2) {
			GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height / 2);

			GetSprite().rotate(6);
			GetSprite().setTextureRect(Animation::rotate);
		}
		else {
			GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height);
			GetSprite().setRotation(0);
			if (_velocityX < 0) {
				if (_velocityY < -1)
					GetSprite().setTextureRect(Animation::jump_left_1);
				else if (_velocityY < 1)
					GetSprite().setTextureRect(Animation::jump_left_2);
				else
					GetSprite().setTextureRect(Animation::jump_left_3);
			}
			if (_velocityX > 0) {
				if (_velocityY < -1)
					GetSprite().setTextureRect(Animation::jump_right_1);
				else if (_velocityY < 1)
					GetSprite().setTextureRect(Animation::jump_right_2);
				else
					GetSprite().setTextureRect(Animation::jump_right_3);
			}
			if (_velocityX == 0) {

				GetSprite().setTextureRect(Animation::jump);

			}
		}
	}
	if (_onEdge == -1) {
		GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height);
		GetSprite().setRotation(0);
		if (_animTime <= 15)
			GetSprite().setTextureRect(Animation::edge_left_1);
		else if (_animTime <= 30)
			GetSprite().setTextureRect(Animation::edge_left_2);
		else if (_animTime <= 45)
			GetSprite().setTextureRect(Animation::edge_left_1);
		else if (_animTime <= 60)
			GetSprite().setTextureRect(Animation::edge_left_2);
	}
	if (_onEdge == 1) {
		GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, GetSprite().getGlobalBounds().height);
		GetSprite().setRotation(0);
		if (_animTime <= 15)
			GetSprite().setTextureRect(Animation::edge_right_1);
		else if (_animTime <= 30)
			GetSprite().setTextureRect(Animation::edge_right_2);
		else if (_animTime <= 45)
			GetSprite().setTextureRect(Animation::edge_right_1);
		else if (_animTime <= 60)
			GetSprite().setTextureRect(Animation::edge_right_2);
	}
	if (_lvl % 50 == 0 && _lvl != 0) {
		if (_sound == 1) {
			sound.setBuffer(soundSkrrt);
			sound.playPitched();
		}
	}
	if (GetSprite().getPosition().y > 480) {
		if (_sound == 1) {
			sound.setBuffer(soundSkrrt);
			sound.playPitched();
		}
	}
}

void Player::checkMove()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (_velocityX > 0)_velocityX = -0.085f;
		else _velocityX -= 0.085f;
		GetSprite().move(_velocityX, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (_velocityX < 0)_velocityX = 0.085f;
		else _velocityX += 0.085f;
		GetSprite().move(_velocityX, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

		_velocityX = 0;
		if (_sound == 1) {
			sound.setBuffer(soundPrrah);
			sound.playPitched();
		}


	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		if (_velocityX < -0.125f)

			_velocityX += 0.125f;
		else if (_velocityX > 0.125f)

			_velocityX -= 0.125f;
		else {

			_velocityX = 0;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (_onGround == true) {
			if ((_velocityX > 4.5f) || (-_velocityX > 4.5f))
				_jumpPower = 2;
			else if ((_velocityX > 3.9f) || (-_velocityX > 3.9f))
				_jumpPower = 1;
			else
				_jumpPower = 0;

			_onEdge = 0;
			switch (_jumpPower) {
			case 0:
			{
				_velocityY = -5.75;
				if (_sound == 1) {
					sound.setBuffer(soundHop);
					sound.playPitched();
				}

				break;
			}
			case 1:
			{
				_velocityY = fabs(_velocityX) * -0.5 - 5.75;
				if (_sound == 1) {
					sound.setBuffer(soundHop);
					sound.playPitched();
				}
				break;
			}
			case 2:
			{
				_velocityY = fabs(_velocityX) * -1 - 5.75;
				GetSprite().move(0, -8);
				if (_sound == 1) {
					sound.setBuffer(soundWhoopie);
					sound.playPitched();
				}
				break;
			}
			}
			_onGround = false;
			_onPlatform = false;

		}



	}

}

void Player::boundaries()
{
	if (GetSprite().getPosition().x < 89)
	{
		if (_onGround == false) {
			_wallCounter++;
			if (_wallCounter == 10)
				_wallCounter = 1;
			
			GetSprite().setPosition(95, GetSprite().getPosition().y);
			if(_wallCounter==1)
			_velocityX = -_velocityX ;
			if (_wallHit == 0)
			{
				_wallHit = 1;
			}
		}
		if (_onGround == true) {
			_wallCounter = 0;
			GetSprite().setPosition(GetSprite().getPosition().x + 2, GetSprite().getPosition().y);

			_velocityX = -_velocityX + 0.5;
		}

	}
	if (GetSprite().getPosition().x > Game::SCREEN_WIDTH - 89) {
		if (_onGround == true) {
			_wallCounter = 0;
			GetSprite().setPosition(GetSprite().getPosition().x - 1, GetSprite().getPosition().y);
			_velocityX = -_velocityX;
		}
		if (_onGround == false) {
			_wallCounter++;
			if (_wallCounter == 10)
				_wallCounter = 1;
			GetSprite().setPosition(545, GetSprite().getPosition().y);
			if (_wallCounter == 1)
				_velocityX = -_velocityX;
			else {
				_velocityX = 0;
			}
			if (_wallHit == 0)
			{
				_wallHit = 1;
			}
		}
	}
}


float Player::GetVelocityX() const
{
	return _velocityX;
}
float Player::GetVelocityY() const
{
	return _velocityY;
}

int Player::GetJumpPower() const
{
	return _jumpPower;
}

void Player::SetJumpPower(int x)
{
	_jumpPower = x;
}

int Player::GetGround() const
{
	return _ground;
}

void Player::SetGround(int x)
{
	_ground = x;
}

int Player::GetLvl() const
{
	return _lvl;
}

void Player::SetLvl(int x)
{
	_lvl = x;
}

int Player::GetOnEdge() const
{
	return _onEdge;
}

void Player::SetOnEdge(int x)
{
	_onEdge = x;
}

bool Player::GetOnGround() const
{
	return _onGround;
}

void Player::SetOnGround(bool x)
{
	_onGround = x;
}

bool Player::GetOnPlatform() const
{
	return _onPlatform;
}

void Player::SetOnPlatform(bool x)
{
	_onPlatform = x;
}

bool Player::GetStarting() const
{
	return _starting;
}

void Player::SetStarting(bool x)
{
	_starting = x;
}

int Player::GetMaxPlat() const
{
	return _maxplat;
}

void Player::SetMaxPlat(int x)
{
	_maxplat = x;
}

float Player::GetGravity() const
{
	return _gravity;
}

void Player::SetGravity(float x)
{
	_gravity = x;
}



PitchedSound Player::sound;
