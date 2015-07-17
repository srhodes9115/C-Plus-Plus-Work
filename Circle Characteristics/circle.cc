//Shannon Rhodes
//ECE 2620-001
//Circle.cc

#include <iostream>
#include "circle.h"
#define PI 4*atan(1)

// Distance function to compute the distance between two coordinates
template <class genericType> 
circle<genericType>::distance (genericType x1, genericType y1, genericType x2, genericType y2, genericType dist = 0)
{
	dist = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
	return dist;
}

//Radius function to compure the radius between two coordinates
template <class genericType> 
circle<genericType>::radius (genericType x1, genericType y1, genericType x2, genericType y2)
	{
		genericType rad;
		rad = distance(x1,y1,x2,y2);
		return rad; 
	}

//Circumference function to compute the circumference given the radius
template <class genericType> 
circle<genericType>::circumference (genericType rad)
	{
    	return 2*PI*rad; 
	}

//Area function to compute the area given the radius
template <class genericType> 
circle<genericType>::area (genericType rad)
	{
		return PI*rad*rad;
	}

//Sets the inputs equal to the private data members of the Circle class
template <class genericType> 
void circle<genericType>::populate_classobj(genericType input_x1, genericType input_y1, genericType input_x2, genericType input_y2)
	{
		x1 = input_x1;
		y1 = input_y1;
		x2 = input_x2;
		y2 = input_x2;
	}