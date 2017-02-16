/** \file Background.h
* Header file for the background class.
* * Sets up the background of the game
*/

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>

//! The background Class
/*!
	This class will be used to set the texture of the background in the game and apply it to the screen
*/

class background : public sf::Sprite
{
private:
	sf::Texture m_Texture; //!< instantiate m_Texture
	bool btrack = 0; //!< instantiate the bool, bTrack
public:
	/**
	The only constructor availible, takes one variables.
	\param btrack is the true or false statement instantiated above

	*/
	
	background(bool btrack); 
};

#endif