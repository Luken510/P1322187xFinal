/** \file game.cpp
* cpp file for the game class.
* * Sets global parameters for the game
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game.h"
#include "car.h"

using namespace std;
using namespace sf;

Game::Game(){}
// Function to limit game view
void Game::ViewLimits(shared_ptr<car> &newCar, shared_ptr<View> &newView)
{

	
	if (newCar->getPosition().x > 550 && newCar->getPosition().y < 200) 
	{
		newView->setCenter(550, 200);
	}
	
	else if (newCar->getPosition().x > 550 && newCar->getPosition().y > 590) 
	{
		newView->setCenter(550, 590);
	}
	
	else if (newCar->getPosition().x < 240 && newCar->getPosition().y > 590) 
	{
		newView->setCenter(240, 590);
	}

	else if (newCar->getPosition().x < 240 && newCar->getPosition().y < 200)			
	{
		newView->setCenter(240, 200);
	}
	//how far the screen goes left	
	else if (newCar->getPosition().x < 240)	
	{
		newView->setCenter(240, newCar->getPosition().y);
	}
	//how far the screen goes right	
	else if (newCar->getPosition().x > 550)					
	{
		newView->setCenter(550, newCar->getPosition().y);
	}
	//how far the screen goes up
	else if (newCar->getPosition().y < 200)								 	
	{
		newView->setCenter(newCar->getPosition().x, 200);
	}
	// how far the screen goes down
	else if (newCar->getPosition().y > 590)														
	{
		newView->setCenter(newCar->getPosition().x, 590); 
	}

	else
	{
		newView->setCenter(newCar->getPosition());
	}

	

}