/**
 * @file platform_colors.h
 * @brief Platform Types class.
* @author Lukasz Kwiecien
 */
#pragma once
#include "SFML/Graphics.hpp"
 /** @class platform_colors
 * Class similar to Animation class.
 * Holds colors constructed from RGBA components for each platform type.
 * Every 50 levels the type of the platform and its color changes.
 * Every member of the class is static, so it can be accessed without creating an object.
 */

class platform_colors
{
public:
	static sf::Color plat_50;
	static sf::Color plat_100;
	static sf::Color plat_150;
	static sf::Color plat_200;
	static sf::Color plat_250;
	static sf::Color plat_300;
	static sf::Color plat_350;
	static sf::Color plat_400;
	static sf::Color plat_450;

};

