/** \file car.h
* Header file for the car class.
* * The Player class
*/

#ifndef CAR_H
#define CAR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include "collidable.h"
#include "AABB.h"
#include "HUD.h"

//! The car Class
/*!
This class will instantiate the variables needed to create and maintain 
the car class ( the player ) in the game
*/


class car : public sf::Drawable, public AABB
{
private:
	sf::Texture m_Texture; //!< instantiate the Texture that will be used to draw the car
	sf::Sprite m_Sprite; //!< instantiate the sprite that will use the texture
	sf::Vector2f m_Velocity; //!< instantiate the velocity of which the car moves
	float m_fRotationAngle; //!< instantiate the rotationAngle of which the car rotates
	sf::Vector2f m_Accerlation; //!< instantiate the accerlation of the car
	sf::Vector2f m_Position; //!< instantiate the position of the car
	float m_fMass; //!< instantiate the mass of the car
	float fMinX; //!< instantiate the min X co-ord of the car
	float fMaxX; //!< instantiate the max X co-ord of the car
	float fMinY; //!< instantiate the min Y co-ord of the car
	float fMaxY; //!< instantiate the max Y co-ord of the car
	float fCoefficient = 0.4f; //!< instantiate the value of coefficient
	float fGravity = 9.8f; //!< instantiate the value of gravity
	float fDirection = 0; //!< instantiate the direction of the car
	float fSpeed = 600.0f; //!< instantiate the speed of the car
	bool bCollisionsucessful = 0; //!< instantiate the bool to determine if a collision has occured
	bool bBottomSideColli = 0; //!< instantiate the bool to see which side the collsion has occured
	bool bTopSideColli = 0; //!< instantiate the bool to see which side the collsion has occured
	bool bLeftSideColli = 0; //!< instantiate the bool to see which side the collsion has occured
	bool bRightSideColli = 0; //!< instantiate the bool to see which side the collsion has occured
	sf::Vector2f v_InterceptDiff; //!< instantiate the Intercept difference

public:
	car(); //!< default constructor 
	/**
	The virtual draw function
	\param Target, is the object that will be drawn
	\Param states is how the object will be drawn
	*/
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Vector2f getRotatVector(); //!< function for getting the value of Rotation vector
	/**
	Update function for the car, it updates all values, position, and speed
	\only parameter is the Timepassed currently ingame
	*/
	void Update(float fTimePassed); 
	/**
	The Rotate function for the car
	\param direction is the direction in which it rotates
	\param Timepassed is the current timepassed ingame
	*/
	void Rotate(float direction, float fTimePassed);
	sf::Vector2f getPosition(); //!< returns the current position
	static float magnitude(sf::Vector2f v); //!< returns the current magnitude
	/**
	Virtual function collides
	\param *other. used for double dispatch - base class
	*/
	bool collides(Collidable *other);
	/**
	Virtual function collides
	\param *other. used for double dispatch - Tyre Class
	*/
	bool collides(Tyres *other);
	void setMinMax(); //!< function that sets the minimum and maximum of current X and Y Values
	bool DetectingCollisions(Tyres *other); //!< function that does a wide scope intercept check
	void setVelocity(sf::Vector2f m_newVel); //!< set the value of the car's velocity
	void setDirection(float fnewDire); //!< set the direction of the car
	float getDirection(); //!< get the current direction of the car
	sf::Vector2f getVelocity(); //!< get the current value of velocity
	void setPosition(sf::Vector2f newPos); //!< set the position of the car
	bool DetectingLapCollisions(sf::FloatRect *other); //!< function used to check where the car is on the lap




};


#endif 