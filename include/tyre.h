/** \file tyre.h
* Header file for Tyre class.
* * instantiates the values and functions needed to create the Tyre class
*/

#ifndef TYRES_H
#define TYRES_h

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "AABB.h"


//! The Tyre Class
/*!
This class will instantiate the variables needed to create and maintain the Tyrewalls
*/
class Tyres : public AABB, public sf::Drawable
{
private:
	float fMinX;  //!< instantiate the min X co-ord of the tyre
	float fMaxX;  //!< instantiate the max X co-ord of the tyre
	float fMinY;  //!< instantiate the min Y co-ord of the tyre
	float fMaxY;  //!< instantiate the max Y co-ord of the tyre
	
public:
	sf::RectangleShape Rectangle; //!< instantiate the rectangle used for the tyres
	sf::FloatRect frm_Tyrewall; //!< instantiate the float rectangle class used for the tyres
	Tyres(); //!<default constructor
	/**
	The second constructor availible
	\param left is X co-ord position of the tyre
	\param top is Y co-rd position of the tyre
	\param width is the width of the tyre
	\param height is the height of the tyre
	*/
	Tyres(float left,float top,float width,float height);
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
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< draw function
	void setMinMax(); //!< function that sets the minimum and maximum of current X and Y Values
	sf::FloatRect getHitBox(); //!< function to get the current hitbox of the tyres
	
};


#endif