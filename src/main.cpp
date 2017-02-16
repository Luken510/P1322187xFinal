/*! \mainpage RadRacer
*
* This is the documentation for the simple racing game RadRacer
*
* This program is a simple racing game
*
*/

/** \file main.cpp
* Contains the entry point for the program.
* Contains the entry point for the program which creates the main game loop
* updating the other objects constantly through the main loop
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <SFML/Window.hpp>
#include "car.h"
#include "background.h"
#include "collidable.h"
#include "game.h"
#include "MainMenu.h"
#include "tyre.h"
#include "AABB.h"
#include <memory>
#include "HUD.h"

using namespace std;
using namespace sf;


/**
The entry point for the application.
*/
int main()
{
	shared_ptr<car> p_player1(new car()); //!< create the player1 car
	background racetrack(1); // instatiate the background objects
	background mainmenuBG(0);

	// instatiate the tyre walls and their position
	shared_ptr<Tyres> shr_pTyreWall1(new Tyres(86.0f ,180.0f, 600.0f, 50.0f));
	shared_ptr<Tyres> shr_pTyreWall2(new Tyres(86.0f , 235.0f, 240.0f, 250.0f));
	shared_ptr<Tyres> shr_pTyreWall3(new Tyres(86.0f , 480.0f, 40.0f, 120.0f));
	shared_ptr<Tyres> shr_pTyreWall4(new Tyres(641.0f, 240.0f, 60.0f, 385.0f));
	shared_ptr<Tyres> shr_pTyreWall5(new Tyres(450.0f, 340.0f, 80.0f, 300.0f));
	shared_ptr<Tyres> shr_pTyreWall6(new Tyres(250.0f, 600.0f, 280.0f, 190.0f));
	shared_ptr<Tyres> shr_pTyreWall7(new Tyres(-30.0f, 722.0f, 930.0f, 100.0f));
	shared_ptr<Tyres> shr_pTyreWall8(new Tyres(-125.0f, 20.0f, 80.0f, 730.0f));
	shared_ptr<Tyres> shr_pTyreWall9(new Tyres(-50.0f, 20.0f, 930.0f, 58.0f));
	shared_ptr<Tyres> shr_pTyreWall10(new Tyres(830.0f, 20.0f, 80.0f, 730.0f));
	// double dispatch
	vector<Collidable *> v_CollisionVector;
	car cTempP1 = *p_player1;
	Tyres tTempTyre1 = *shr_pTyreWall1;
	Tyres tTempTyre2 = *shr_pTyreWall2;
	Tyres tTempTyre3 = *shr_pTyreWall3;
	Tyres tTempTyre4 = *shr_pTyreWall4;
	Tyres tTempTyre5 = *shr_pTyreWall5;
	Tyres tTempTyre6 = *shr_pTyreWall6;
	Tyres tTempTyre7 = *shr_pTyreWall7;
	Tyres tTempTyre8 = *shr_pTyreWall8;
	Tyres tTempTyre9 = *shr_pTyreWall9;
	Tyres tTempTyre10 = *shr_pTyreWall10;

	v_CollisionVector.push_back(&cTempP1);
	v_CollisionVector.push_back(&tTempTyre1);
	v_CollisionVector.push_back(&tTempTyre2);
	v_CollisionVector.push_back(&tTempTyre3);
	v_CollisionVector.push_back(&tTempTyre4);
	v_CollisionVector.push_back(&tTempTyre5);
	v_CollisionVector.push_back(&tTempTyre6);
	v_CollisionVector.push_back(&tTempTyre7);
	v_CollisionVector.push_back(&tTempTyre8);
	v_CollisionVector.push_back(&tTempTyre9);
	v_CollisionVector.push_back(&tTempTyre10);


	MainMenu mainmenu1; //!< create a mainmenu
	Game gMaster; //!< create the view limits
	HUD hud; //!< create the hud

	int startgame = 0;
	RenderWindow window(VideoMode(1024,768), "RadRacer", Style::Close | Style::Titlebar); //!< render window

	float fFrameTime(1.0f / 60.0f); // fps
	float fTimePassed;

	Clock timer;
	shared_ptr<View> view_player1(new View(FloatRect(0, 0, 600, 300))); //!< set view


	// game loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (timer.getElapsedTime().asSeconds() > fFrameTime)
		{
			
			fTimePassed = timer.restart().asSeconds(); //!< set ftimepassed
			p_player1->Update(fTimePassed); //!< update car
			view_player1->setCenter(p_player1->getPosition()); //!< update the view parameters
		

			if (p_player1->DetectingCollisions(&tTempTyre1) == true) //!< detecting collisions
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(1));			
			}
			if (p_player1->DetectingCollisions(&tTempTyre2) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(2));				
			}
			if (p_player1->DetectingCollisions(&tTempTyre3) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(3));
			} 
			if (p_player1->DetectingCollisions(&tTempTyre4) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(4));
			}
			if (p_player1->DetectingCollisions(&tTempTyre5) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(5));
			}
			if (p_player1->DetectingCollisions(&tTempTyre6) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(6));
			}
			if (p_player1->DetectingCollisions(&tTempTyre7) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(7));
			}
			if (p_player1->DetectingCollisions(&tTempTyre8) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(8));
			} 
			if (p_player1->DetectingCollisions(&tTempTyre9) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(9));
			}
			if (p_player1->DetectingCollisions(&tTempTyre10) == true) //!< detecting collisions	
			{
				v_CollisionVector.at(0)->collides(v_CollisionVector.at(10));
			}
			
				
			hud.Update(); //!< update hud
			hud.LapCheck(*p_player1); //!< check to see where the car is

			gMaster.ViewLimits(p_player1, view_player1); //!< set the view limits

			hud.setTime1Position(view_player1->getCenter().x - 300, view_player1->getCenter().y + 70);  //!< set position of the first timer
			hud.setTime2Position(view_player1->getCenter().x - 300, view_player1->getCenter().y + 95);  //!< set position of the second timer
			hud.setTime3Position(view_player1->getCenter().x - 300, view_player1->getCenter().y + 120); //!< set position of the third timer
			hud.setRectPosition(hud.getPosition().x, hud.getPosition().y); //!< set the background of the timers position
		}
		
	
		


		// if the game is started
		if (Keyboard::isKeyPressed(Keyboard::Key::Return))
		{
			startgame = 1;

		}
		// during the main game
		if (startgame == 1)
		{
			
			window.clear(Color::White);

			window.setView(*view_player1);
			// draw all game objects
			window.draw(racetrack);
			window.draw(*p_player1);
			window.draw(*shr_pTyreWall1);
			window.draw(*shr_pTyreWall2);
			window.draw(*shr_pTyreWall3);
			window.draw(*shr_pTyreWall4);
			window.draw(*shr_pTyreWall5);
			window.draw(*shr_pTyreWall6);
			window.draw(*shr_pTyreWall7);
			window.draw(*shr_pTyreWall8);
			window.draw(*shr_pTyreWall9);
			window.draw(*shr_pTyreWall10);	
			window.draw(hud);

			window.display();
		}
		else
		{

			window.clear(Color::White);
			window.draw(mainmenuBG); //!< draw background of mainmenu
			window.draw(mainmenu1);  //!< draw mainmenu
			window.display();
		}
	}



	}

