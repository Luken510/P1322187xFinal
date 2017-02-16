/** \file AABB.cpp
* cpp file for the AABB class.
* contains all the parameters to create the AABB object and maintain it
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/window.hpp>
#include "AABB.h"


using namespace std;
using namespace sf;


AABB::AABB()
{

}
// return the value of v_min
Vector2f AABB::getMin()
{
	return v_min;
}
// return the value of v_max
Vector2f AABB::getMax()
{
	return v_max;
}
// return the position of the object
sf::Vector2f AABB::getPos()
{
	return v_mPos;
}
// set the position, x and y
void AABB::setPos(float x, float y) 
{ 
	v_mPos.x = x; v_mPos.y = y;
}
// return the dotproduct of two vectors, the parameters are both vectors
float AABB::fDotProduct(Vector2f V1, Vector2f V2)
{
	return V1.x * V2.x + V2.y * V1.y; 
}
//!< set the value of v_max
void AABB::setMax(Vector2f maximum)
{
	
	v_max = maximum;
}
// set the value of v_min
void AABB::setMin(Vector2f minimum)
{
	v_min = minimum;
}
 // return the normal of the object
Vector2f AABB::getNormal()
{
	return v_Normal;
}
// set the value of v_Normal
void AABB::setNormal(Vector2f &newNormal)
{
	 v_Normal = newNormal; 
}

