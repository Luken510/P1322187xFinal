/** \file Background.cpp
* cpp file for the background class.
* * Sets up the background of the game
*/


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "background.h"

using namespace std;

/*!
set the background image depending on which part of the game it is currently at
sets the texture(loads image from file)
sets the origin of the texture
sets the position of the texture
*/
background::background(bool btrack)
{
	if (btrack == 1)
	{m_Texture.loadFromFile(".\\assets\\pictures\\track.png"); }
	else if (btrack == 0)
	{
		m_Texture.loadFromFile(".\\assets\\pictures\\mainmenubg.png");
	}
	setTexture(m_Texture);
	setOrigin(getLocalBounds().width / 2.0f, getLocalBounds().height / 2.0f);
	if (btrack == 1){setPosition(400, 400);}
	else if (btrack == 0){ setPosition(514, 385); }
	
}