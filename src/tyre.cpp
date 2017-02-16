/** \file tyre.cpp
* cpp file for Tyre class.
* * instantiates the values and functions needed to create the Tyre class
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/window.hpp>
#include "tyre.h"

using namespace std;
using namespace sf;

Tyres::Tyres(float left,float top,float width,float height)
{

	
	frm_Tyrewall.height = height; // height of the tyre wall
	frm_Tyrewall.width = width; // width of the tyre wall
	frm_Tyrewall.left = left; // starting point, i.e top left
	frm_Tyrewall.top = top; // max point, i.e bot right


	Rectangle.setPosition(sf::Vector2f( (left + (width /2.0f))  , (top + (height/ 2.0f))  ) ); //!< set the min
	Rectangle.setSize(sf::Vector2f(width, height)); //!< set the width/height
	Rectangle.setFillColor(sf::Color(0, 0, 0, 0)); //!< set the colour and visability
	Rectangle.setOrigin(((Rectangle.getLocalBounds().width) / 2.0f), ((Rectangle.getLocalBounds().height) / 2.0f)); //!< set the origin
	setMinMax();
	
};
// draw function
void Tyres::draw(RenderTarget &target, RenderStates states) const
{

	target.draw(Rectangle);
	

}
// function that sets the minimum and maximum of current X and Y Values
void Tyres::setMinMax()
{
	fMinX = (Rectangle.getOrigin().x - (Rectangle.getSize().x / 2.0f));
	fMaxX = (Rectangle.getOrigin().x + Rectangle.getSize().x/2.0f);
	fMinY = (Rectangle.getOrigin().y + (Rectangle.getSize().y / 2.0f));
	fMaxY = (Rectangle.getOrigin().y + Rectangle.getSize().y / 2.0f);

	sf::Vector2f MTemp;
	MTemp.x = fMaxX;
	MTemp.y = fMaxY;
	setMax(MTemp);
	sf::Vector2f mTemp2;
	mTemp2.x = fMinX;
	mTemp2.y = fMinY;
	setMin(mTemp2);
}
/**
Virtual function collides
\param *other. used for double dispatch - base class
*/
bool Tyres::collides(Collidable *other)
{
	return other->collides(this);
}
/**
Virtual function collides
\param *other. used for double dispatch - Tyre Class
*/
bool Tyres::collides(Tyres *other)
{

	return false;
}
