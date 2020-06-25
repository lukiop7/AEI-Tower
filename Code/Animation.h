/**
 * @file Animation.h
 * @brief Animation class.
* @author Lukasz Kwiecien
 */
#pragma once
#include "SFML/Graphics.hpp"

 /** @class Animations
 * Holds rectangle coordinates for each appropriate player animation from sheet.png file.
 * Every member of the class is static, so it can be accessed without creating an object.
 */

class Animation
{
public:
	static sf::IntRect walk_right_1;
	static sf::IntRect walk_right_2;
	static sf::IntRect walk_right_3;
	static sf::IntRect walk_right_4;
	static sf::IntRect walk_left_1;
	static sf::IntRect walk_left_2;
	static sf::IntRect walk_left_3;
	static sf::IntRect walk_left_4;
	static sf::IntRect idle_1;
	static sf::IntRect idle_2;
	static sf::IntRect idle_3;
	static sf::IntRect jump_right_1;
	static sf::IntRect jump_right_2;
	static sf::IntRect jump_right_3;
	static sf::IntRect jump_left_1;
	static sf::IntRect jump_left_2;
	static sf::IntRect jump_left_3;
	static sf::IntRect edge_left_1;
	static sf::IntRect edge_left_2;
	static sf::IntRect edge_right_1;
	static sf::IntRect edge_right_2;
	static sf::IntRect jump;
	static sf::IntRect rotate;

};

