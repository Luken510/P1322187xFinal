/** \file game.h
* Header file for the game class.
* * Sets global parameters for the game
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <memory>
// pre declare class car
class car; 

//! The Game Class
/*!
This class sets the view limits on the game window
*/
class Game 
{
	private:
		
	public:
		  Game(); //!<default constructor
		 
		  void ViewLimits(std::shared_ptr<car> &newCar, std::shared_ptr<sf::View> &newView); //!< Function to limit game view




};
#endif