#include "Platform.h"
#include <iostream>
#include <random>


Platform::Platform(int lvl, Player* player) : _distance(84), _player(player), _lvl(lvl), _movespeed(1.0f),_gravity(0.2f)
{
	Load("images/floor.png");
	_ASSERT(IsLoaded());
	SetOut(false);
	int tmp = generatepos();
	if (_lvl == 0) {
		GetSprite().setTextureRect(sf::IntRect(0, 0, 492, 32));
		GetSprite().setPosition(640 / 2, 416 - (_distance * _lvl));
	}
	else {
		GetSprite().setTextureRect(sf::IntRect(0, 0, generatelength(tmp), 32));
		GetSprite().setPosition(tmp, 416 - (_distance * _lvl));
	}
	GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, 0);
}


Platform::~Platform()
{

}

void Platform::Update()
{

	Collision();
	Color();
	Speed();
	if (_player->GetLvl() >= 3) {
		_player->SetGravity(_gravity);
		if (_player->Getposition().y <= 160) {
			if (_player->GetLvl() < 200) {
				GetSprite().move(0, 2.5);
				_player->SetGravity(0.3f);
			}
			else if (_player->GetLvl() < 250){
				GetSprite().move(0, 3.2);
			_player->SetGravity(0.35f);
		}
			else{
				GetSprite().move(0, 4.0);
				_player->SetGravity(0.4f);
			}
		}
		if (_player->Getposition().y <= 0){
			GetSprite().move(0, 4.0);
			_player->SetGravity(0.6f);
		}
		else
			GetSprite().move(0, _movespeed);
		if (_player->GetLvl() == _lvl && _player->GetOnPlatform() == true && _player->GetOnGround() == true)
		{
			_player->SetPosition(_player->Getposition().x, GetSprite().getPosition().y - 1);
		}


		if (GetSprite().getPosition().y >= 480)
			SetOut(true);


		if (_player->GetLvl() == _lvl && _player->GetOnPlatform() == true && _player->GetOnGround() == true && IsOut() == true)
		{
			_player->SetOnGround(false);
			_player->SetOnPlatform(false);
			_player->SetOnEdge(0);
		}
		if (IsOut() == true) {
			Regenerate();
		}
	}
}

void Platform::Draw(sf::RenderWindow& rw)
{
	V_Object::Draw(rw);
}

void Platform::Color()
{
	if (_lvl < 25)
	{
		
	}
	else if (_lvl < 50)
		GetSprite().setColor(platform_colors::plat_50);
	else if (_lvl < 75)
		GetSprite().setColor(platform_colors::plat_100);
	else if (_lvl < 100)
		GetSprite().setColor(platform_colors::plat_150);
	else if (_lvl < 125)
		GetSprite().setColor(platform_colors::plat_200);
	else if (_lvl < 150)
		GetSprite().setColor(platform_colors::plat_250);
	else if (_lvl < 175)
		GetSprite().setColor(platform_colors::plat_300);
	else if (_lvl < 200)
		GetSprite().setColor(platform_colors::plat_350);
	else if (_lvl < 225)
		GetSprite().setColor(platform_colors::plat_400);
	else if (_lvl < 250)
		GetSprite().setColor(platform_colors::plat_450);
	else {
		std::random_device rd;
		std::mt19937 rand(rd());
		std::uniform_int_distribution<> col(0, 255);
		GetSprite().setColor(sf::Color(col(rd), col(rd), col(rd)));
	}
}

void Platform::Speed()
{
	if (_player->GetLvl() < 25)
	{

	}
	else if (_player->GetLvl() < 50)
		_movespeed = 1.2f;
	else if (_player->GetLvl()<75)
		_movespeed = 1.4f;
	else if (_player->GetLvl() < 100)
		_movespeed = 1.6f;
	else if (_player->GetLvl() < 125)
		_movespeed = 1.8f;
	else if (_player->GetLvl() < 150)
		_movespeed = 2.0f;
	else if (_player->GetLvl() < 175)
		_movespeed = 2.2f;
	else if (_player->GetLvl() < 200) {
		_movespeed = 2.4f;
		_gravity = 0.25f;
	}
	else if (_player->GetLvl() < 225)
		_movespeed = 2.6f;
	else if (_player->GetLvl() < 250)
		_movespeed = 2.8f;
	else {
		_movespeed = 3.5f;
		_gravity = 0.3f;
	}
}

void Platform::Collision()
{
	if (Collide() == true) {
		if (fabs(_player->Getposition().y - GetSprite().getPosition().y) < 5 && _player->GetVelocityY() > 0) {
			_player->SetGround(GetSprite().getPosition().y);
			(*this) = _player;
			_player->SetOnPlatform(true);
			_player->SetOnGround(true);

		}
		if (_player->GetLvl() == _lvl && _player->GetOnPlatform() == true) {
			if (_player->Getposition().x <= (GetSprite().getPosition().x + 5 - GetSprite().getGlobalBounds().width / 2))
			{
				_player->SetOnEdge(-1);

			}
			if (_player->Getposition().x >= (GetSprite().getPosition().x - 5 + GetSprite().getGlobalBounds().width / 2))
			{
				_player->SetOnEdge(1);

			}
			if (_player->Getposition().x > (GetSprite().getPosition().x + 5 - GetSprite().getGlobalBounds().width / 2) && _player->Getposition().x < (GetSprite().getPosition().x - 5 + GetSprite().getGlobalBounds().width / 2))
			{
				_player->SetOnEdge(0);

			}
		}

	}
	else {
		if (_player->GetLvl() == _lvl) {
			if (_player->GetOnGround() == true) {
				_player->SetOnPlatform(false);
				_player->SetOnGround(false);
				_player->SetGround(416);
				_player->SetOnEdge(0);
			}
		}
	}
}

bool Platform::Collide()
{
	if ((int)_player->Getposition().x >= (int)GetSprite().getPosition().x - (GetSprite().getGlobalBounds().width / 2)
		&& (int)_player->Getposition().x <= (int)GetSprite().getPosition().x + (GetSprite().getGlobalBounds().width / 2))
		return true;
	else
		return false;


}

void Platform::Regenerate()
{
	_player->SetMaxPlat(_player->GetMaxPlat()+1);
	_lvl = _player->GetMaxPlat();
	if (_lvl % 25 == 0) {
		GetSprite().setTextureRect(sf::IntRect(0, 0, 492, 32));
		GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, 0);
		GetSprite().setPosition(640 / 2, -32);
	}
	else {
		int tmp = generatepos();
		GetSprite().setTextureRect(sf::IntRect(0, 0, generatelength(tmp), 32));
		GetSprite().setOrigin(GetSprite().getGlobalBounds().width / 2, 0);
		GetSprite().setPosition(tmp, -32);
	}
	SetOut(false);
}

int Platform::generatelength(int pos)
{
	int tmp = pos;
	std::random_device rd;
	std::mt19937 rand(rd());
	std::uniform_int_distribution<> len(7, 13);
	int length = len(rd) * 20;
	tmp -= 74;
	if ((tmp - (length / 2)) < 0)
		length = length - 2 * ((length / 2) - tmp);
	tmp += 74;
	if ((tmp + (length / 2)) > 570)
		length = length - 2 * ((tmp + (length / 2)) - 570);
	if (length < 140)
		return 140;
	else
		return length;
}


int Platform::generatepos()
{
	std::random_device rd;
	std::mt19937 rand(rd());
	std::uniform_int_distribution<> pos(144, 496);
	return pos(rd);
}

Platform& Platform::operator=(Player* p)
{
	p->SetLvl(_lvl);
	return *this;
}




