/** \file HUD.h
* Header file for HUD class.
* * creates the HUD for the game
*/


#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
// pre declare class car
class car;
//! The HUD Class
/*!
This class will instantiate the variables needed to create and maintain the HUD
*/
class HUD : public sf::Drawable
{
private:
	sf::Text tLaptime; //!< instantiate the text object laptime
	sf::Font font;//!< instantiate the font for manipulation
	sf::Clock c_Laptimer; //!< instantiate the clock for the game
	sf::Text tFirstLapText; //!< instantiate the Text object for other laps
	sf::Text tSecondLapText; //!< instantiate the Text object for other laps
	sf::RectangleShape r_LapTimerBG; //!< instantiate the background of the timers
	sf::FloatRect fr_LapStart; //!< instantiate the point of starting the lap
	sf::FloatRect fr_Halfway; //!< instantiate the halfway point of the lap
	bool bGameStart = true; //!< instantiate the bool value to check to see if the car just started
	bool bHalfway = false; //!< instantiate the bool value to check to see if the car has gone halfway
public:
	HUD(); //!< defualt constructor 
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< draw function
	void Update(); //!< updates all variables to maintain the HUD
	void setTime1Position(float x, float y); //!< set the position of the first timer
	void setTime2Position(float x, float y); //!< set the position of the second timer
	void setTime3Position(float x, float y); //!< set the position of the third timer
	void setRectPosition(float x, float y); //!< set the position of the Background
	sf::Vector2f getPosition(); //!< gets the position of the first laptimer
	void LapCheck(car p1); //!< function to check if the car has gone past halfway/starting position
};

#endif