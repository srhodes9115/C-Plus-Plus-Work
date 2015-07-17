//Shannon Rhodes
//ECE 2620-001
//Header file for Circle contains the functions of Class Circle

#include <iostream>
#include <cmath>
#define PI 4*atan(1) 

using namespace std;

template <class genericType> 
class circle 
{
 
private:
	//Private members
	genericType x1, y1, x2, y2;

protected:
	//Distance function declaration
	genericType distance (genericType x1, genericType y1, genericType x2, genericType y2);

public: 
	//Circle constructor
	circle (genericType x1_constructor = 0, genericType y1_constructor = 0, genericType x2_constructor = 0, genericType y2_constructor = 0)
{
	x1 = x1_constructor;
	y1 = y1_constructor;
	x2 = x2_constructor;
	y2 = y2_constructor;
}
	
	//Radius function declaration
	genericType radius (genericType x1, genericType y1, genericType x2, genericType y2);

	//Circumference function declaration
	genericType circumference (genericType rad);

	//Area function declaration
	genericType area (genericType rad);

	//Populate_classobj declaration
	void populate_classobj(genericType input_x1, genericType input_y1, genericType input_x2, genericType input_y2);
};