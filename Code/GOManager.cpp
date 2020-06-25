#include "GOManager.h"
#include "Game.h"
#include <iostream>

GOManager::GOManager()
{
}

GOManager::~GOManager()
{
	std::for_each(_Objects.begin(), _Objects.end(), GameObjectDeallocator());
}

void GOManager::Add(std::string name, V_Object* gameObject)
{
	_Objects.insert(std::pair<std::string, V_Object*>(name, gameObject));
}

void GOManager::Remove(std::string name)
{
	std::map<std::string, V_Object*>::iterator results = _Objects.find(name);
	if (results != _Objects.end())
	{
		delete results->second;
		_Objects.erase(results);
	}
}
V_Object* GOManager::Get(std::string name) const
{
	std::map<std::string, V_Object*>::const_iterator results = _Objects.find(name);
	if (results == _Objects.end())
	{
		return NULL;
	}
	return results->second;
}

void GOManager::DrawAll(sf::RenderWindow& renderWindow)
{
	std::map<std::string, V_Object*>::const_iterator itr = _Objects.begin();
	while (itr != _Objects.end()) {
		itr->second->Draw(renderWindow);
		itr++;
	}
}


void GOManager::UpdateAll()
{
	std::map<std::string, V_Object*>::const_iterator itr = _Objects.begin();

	while (itr != _Objects.end())
	{
		itr->second->Update();

		itr++;
	}



}

