/**
 * @file GOManager.h
 * @brief Object Manager
* @author Lukasz Kwiecien
 */

#pragma once
#include "V_Object.h"

 /** @class GOManager
 * Class responsible for managing game objects. Calls update and draw functions for each V_Object in the game.*/

class GOManager {
public:
	/**
	*Constructor.
	*/
	GOManager();
	/**
	*Destructor. Calls for_each function with map and GameObjectDeallocator as parameters.
	*For every object, from the objects map, GameObjectDeallocator functor is called. Every V_Object stored in the map is deleted. This prevents memory leaks.
	*/
	~GOManager();
	/**
	*Adds V_Object to the map. Map stores std::pair of string and pointer to V_Object.
	*@param name a string which holds the name of the object.
	*@param Object pointer to V_Object.
	*/
	void Add(std::string name, V_Object* Object);
	/**
	 * Function deletes the pointer to the V_Object referred to in results->second.
	 * @param name a string which holds the name of the object.
	 */
	void Remove(std::string name);
	/**
	*Function goes through entire map until it finds the Object with a given name. If the object is found returns pointer to it, otherwise returns NULL.
	*@param name name of the V_Object we want to get.
	*@return pointer to V_Object is returned.
	*/
	V_Object* Get(std::string name) const;
	/**
	* Calls draw function for every object stored in the map.
	*@param renderwindow render window.
	*/
	void DrawAll(sf::RenderWindow& renderWindow);
	/**
	* Calls update function for every object stored in the map.
	*/
	void UpdateAll();
private:
	std::map<std::string, V_Object*> _Objects; ///< collection of std::pair objects containing string and pointer to V_Object.
	/**
	*Struct which holds a functor to delete objects.
	*/
	struct GameObjectDeallocator {
		/**
		*Overloaded function operator.
		*/
		void operator()(const std::pair<std::string, V_Object*>& p)const {
			delete p.second;
		}
	};
};