//Shannon Rhodes
//C++ - Lab 1 - ECE 2620
//

#include <iostream>
#include <cmath>
#include <coordinate_calculations.h>
using namespace std; 

int main()
{
	//Declarations
	int choice;
	int i = 0;
	double x1, y1, x2, y2, rad;

	//Inputs given by the user
	cout << "Enter the center point x1 and y1 separated by a space = " <<endl;
	cin >> x1 >> y1;
	cout << "Enter a point on the circle x2 and y2 separated by a space= " << endl;
	cin >> x2 >> y2;

	//Loop to give the user a choice on what to calculate
	while (i == 0)
{
	cout << "Press 0 to compute the radius of a circle, Press 1 to compute the circumference,Press 2 to compure the area, or Press 3 to exit" <<endl; 
	cin >> choice;
	switch (choice)
	{	
		case 0: //radius 
			cout << "The radius is = " << radius(x1,y1,x2,y2)<< endl;
			break;
		case 1: //circumference
			rad = radius(x1,y1,x2,y2); 
			cout <<"The circumference is = " << circumference(rad) << endl;
			break;
		case 2: //area
			rad = radius(x1,y1,x2,y2); 
			cout <<"The area is = " << area(rad) << endl;
			break;
		case 3://exit
			cout <<"Exiting" <<endl;
			i = 1;
			break;
		default: 
			cout << "Press 0 to compute the radius of a circle, Press 1 to compute the circumference,Press 2 to compure the area, or Press 3 to exit" << endl; 
	}
}
}
