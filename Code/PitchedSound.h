/**
 * @file PitchedSound.h
 * @brief Sounds class.
* @author Lukasz Kwiecien
 */
#pragma once
#include <SFML/Audio.hpp>
#include <random>

/** @class PitchedSound
* Responsible for sounds playback at different pitch.
*/

class PitchedSound : public sf::Sound
{
public:
	using Sound::Sound;
	/**
	*Plays sound at a random pitch.
	*/
	void playPitched();
};