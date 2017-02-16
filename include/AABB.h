/** \file AABB.h
* Header file for the AABB class.
* * Allows subclasses to be manipulated
*/

#ifndef AABB_H
#define AABB_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "collidable.h"



//! The AABB Class
/*!
This Class will be used by AABB objects for future references
It can find the min, max, positin and penetration (intercept)
*/

class AABB : public Collidable
{
private:
	
	sf::Vector2f v_min; //!< instantiate min
	sf::Vector2f v_max; //!< instantiate max
	sf::Vector2f v_mPos; //!< instantiate position
	sf::Vector2f v_Normal; //!< instantiate the normal
	float fPenetration; //!< instantiate the Penetration (intercept)

public:
	AABB(); //!< Default constructor
	sf::Vector2f getMin(); //!< return the value of v_min
	sf::Vector2f getMax(); //!< return the value of v_max
	sf::Vector2f getPos(); //!< return the position of the object
	sf::Vector2f getNormal(); //!< return the normal of the object
	void setNormal(sf::Vector2f &newNormal); //!< set the value of v_Normal
	void setPos(float x, float y); //!< set the position, x and y
	void setMin(sf::Vector2f minimum); //!< set the value of v_min
	void setMax(sf::Vector2f maximum); //!< set the value of v_max
	float fDotProduct(sf::Vector2f V1, sf::Vector2f V2); //!< return the dotproduct of two vectors, the parameters are both vectors
};


#endif