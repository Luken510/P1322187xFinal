/** \file HUD.cpp
* cpp file for HUD class.
* * creates the HUD for the game
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "HUD.h"
#include "car.h"

using namespace std;
using namespace sf;

/*!
Create the HUD object
sets the font(loadsfrom file)
sets the font, string, position and char size to the first lap timer
sets the font, string, position and char size to the second lap timer
sets the font, string, position and char size to the third lap timer
sets the size and color of the background to the timers
instantiates the laptstarts height, width, left and top values
instantiates the halfway height, width, left and top values
*/

HUD::HUD()
{

	font.loadFromFile(".//assets//fonts//liberationsansregular.ttf");
	tLaptime.setFont(font);
	tLaptime.setString(to_string(c_Laptimer.getElapsedTime().asSeconds()));
	tLaptime.setPosition(200.0f, 300.0f);
	tLaptime.setCharacterSize(17);

	tFirstLapText.setFont(font);
	tFirstLapText.setPosition(200.0f, 325.0f);
	tFirstLapText.setCharacterSize(17);

	tSecondLapText.setFont(font);
	tSecondLapText.setPosition(200.0f, 350.0f);
	tSecondLapText.setCharacterSize(17);

	r_LapTimerBG.setSize(sf::Vector2f(90, 90));
	r_LapTimerBG.setFillColor(sf::Color::Black);

	fr_LapStart.height = 70.0f;
	fr_LapStart.width = 100.0f;
	fr_LapStart.left = 400.0f;
	fr_LapStart.top = 80.0f;

	fr_Halfway.height = 100.0f;
	fr_Halfway.width = 50.0f;
	fr_Halfway.left = 400.0f;
	fr_Halfway.top = 450.0f;
}
// draw function
void HUD::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(r_LapTimerBG);
	target.draw(tLaptime);
	target.draw(tFirstLapText);
	target.draw(tSecondLapText);
	

}
// updates the time, and what to write to the screen
void HUD::Update()
{
	c_Laptimer.getElapsedTime().asSeconds();
	tLaptime.setString(to_string(c_Laptimer.getElapsedTime().asSeconds()));
}
// sets the first timers position
void HUD::setTime1Position(float x, float y)
{
	tLaptime.setPosition(x, y);
}
// sets the second timers position
void HUD::setTime2Position(float x, float y)
{
	tFirstLapText.setPosition(x, y);
}
// sets the third timers position
void HUD::setTime3Position(float x, float y)
{
	tSecondLapText.setPosition(x, y);
}
// sets the background of the timers position
void HUD::setRectPosition(float x, float y)
{
	r_LapTimerBG.setPosition(x, y);
}
// gets the position of the first timer
sf::Vector2f HUD::getPosition()
{
	sf::Vector2f temp(tLaptime.getPosition().x, tLaptime.getPosition().y);
		return temp;
}
// function to check if the car has gone past halfway/starting position
void HUD::LapCheck(car p1)
{
	// if the car has passed one of the checkpoints
	if (p1.DetectingLapCollisions(&fr_LapStart))
	{
		// if the car is about to start
		if (bGameStart == true && !bHalfway)
		{
			c_Laptimer.restart();
			bGameStart = false;

			c_Laptimer.getElapsedTime().asSeconds();
			tLaptime.setString(to_string(c_Laptimer.getElapsedTime().asSeconds()));

		}
		// if the car is pass the start, and halfway (ends the lap)
		else if (!bGameStart && bHalfway)
		{
			c_Laptimer.restart();

			tSecondLapText.setString(tFirstLapText.getString());
			tFirstLapText.setString(tLaptime.getString());

			bHalfway = false;


		}
	}
	// if the car is halfway
	else if (p1.DetectingLapCollisions(&fr_Halfway))
	{
		if (!bHalfway)
		{
			bHalfway = true;
		}
	}
}