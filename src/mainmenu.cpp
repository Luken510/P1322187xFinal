/** \file MainMenu.cpp
* cpp file for Mainmenu class.
* * creates the MainMenu
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MainMenu.h"

using namespace std;
using namespace sf;
/*!
Create the mainmenu object
sets the font(loads from file)
sets the texture(loads from file)
sets the sprite to the texture
sets the sprites origin
sets the sprites position
sets the intros, font, string, color, position, size, and origin
sets the instructions, font, string, color, position, size, and origin
*/
MainMenu::MainMenu()
{
	font.loadFromFile(".//assets//fonts//liberationsansregular.ttf");
	m_Texture.loadFromFile(".\\assets\\pictures\\title.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(m_Sprite.getLocalBounds().width / 2.0f, m_Sprite.getLocalBounds().height / 2.0f);
	m_Sprite.setPosition(510, 284);


	tIntro.setFont(font);
	tIntro.setString("Press Enter to Start");
	tIntro.setColor(Color::Red);
	tIntro.setPosition(710, 984);
	tIntro.setCharacterSize(35);
	tIntro.setOrigin(tIntro.getPosition().x / 2, tIntro.getPosition().y / 2);


	tInstructions.setFont(font);
	tInstructions.setString("Use the Arrow Keys to drive the car");
	tInstructions.setColor(Color::Red);
	tInstructions.setPosition(540, 684);
	tInstructions.setCharacterSize(35);
	tInstructions.setOrigin(tInstructions.getPosition().x / 2, tInstructions.getPosition().y / 2);




}
// draw function
void MainMenu::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(m_Sprite);
	target.draw(tIntro);
	target.draw(tInstructions);
}