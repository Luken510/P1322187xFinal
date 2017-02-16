/** \file MainMenu.h
* Header file for Mainmenu class.
* * creates the MainMenu
*/
#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>

//! The MainMenu Class
/*!
This class will instantiate the variables needed to create and maintain the MainMenu screeb
*/
class MainMenu : public sf::Drawable
{
private:
	sf::Font font; //!< instantiate the font for the main menu
	sf::Text tInstructions; //!< instantiate the text object Instructions
	sf::Text tIntro; //!< instantiate the text object Introduction
	sf::Texture m_Texture; //!< instantiate the texture
	sf::Sprite m_Sprite; //!< instantiate the sprite that will use the texture

public:
	MainMenu();//!< default constructor
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< draw function

};

#endif