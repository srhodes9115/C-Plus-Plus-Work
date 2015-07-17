//Shannon Rhodes
//ECE 2620-001

#include <iostream>
#include <cmath>
#include "circle.h"
using namespace std;

int main()
{
	//Variable declarations
	int choice;
	int i = 0;
	double x1_input = 1, y1_input = 3, x2_input = 0, y2_input = 0;
	double x1_input2 = -1.5, y1_input2 = -6.65, x2_input2 = -.5, y2_input2 = 10;

	//Object Instantiation using the circle constructor
	circle <int>my_obj1(x1_input, y1_input, x2_input, y2_input);
	circle <float>my_obj2(x1_input2, y1_input2, x2_input2, y2_input2);

	//While loop to continually give the user options
	while (i == 0)
	{
		cout << "Press 0 to compute the radius of the two circles, Press 1 to compute the circumference of the two circles, Press 2 to compute the area of the two circles, Press 3 to compute new values for circle 1, Press 4 to compute new values for circle 2, or Press 5 to exit" <<endl; 
		cin >> choice;

	switch (choice)
	{	
		case 0: //Computes the radius of circle 1 and circle 2 
			cout << "The radius of circle 1 is = " << my_obj1.radius(x1_input, y1_input, x2_input, y2_input)<< endl;
			cout << "The radius of circle 2 is = " << my_obj2.radius(x1_input2, y1_input2, x2_input2, y2_input2)<< endl;
			break;
		case 1: //Computes the circumference of circle 1 and circle 2
			cout <<"The circumference of circle 1 is = " << my_obj1.circumference(my_obj1.radius(x1_input, y1_input, x2_input, y2_input)) << endl;
			cout <<"The circumference of circle 2 is = " << my_obj2.circumference(my_obj2.radius(x1_input2, y1_input2, x2_input2, y2_input2)) << endl;
			break;
		case 2: //Computes the area of circle 1 and circle 2
			cout <<"The area of the first circle is = " << my_obj1.area(my_obj1.radius(x1_input, y1_input, x2_input, y2_input)) << endl;
			cout <<"The area of the second circle is = " << my_obj2.area(my_obj2.radius(x1_input2, y1_input2, x2_input2, y2_input2)) <<endl;
			break;
		case 3: // Asks the user for new x1,y1,x2,y2 values for circle 1
			cout << "Enter the center point of a circle x1 and y1 separated by a space = " <<endl;
			cin >> x1_input >> y1_input;
			cout << "Enter a point on the circle x2 and y2 separated by a space= " << endl;
			cin >> x2_input >> y2_input;
			my_obj1.populate_classobj(x1_input,y1_input,x2_input,y2_input);
			break;
		case 4: //Asks the user for new x1,y2,x2,y2 values for circle 2
			cout << "Enter the center point of a circle x1 and y1 separated by a space = " <<endl;
			cin >> x1_input2 >> y1_input2;
			cout << "Enter a point on the circle x2 and y2 separated by a space= " << endl;
			cin >> x2_input2 >> y2_input2;
			my_obj2.populate_classobj(x1_input2, y1_input2, x2_input2, y2_input2);
			break;
		case 5://exit
			cout <<"Exiting" <<endl;
			i = 1;
			break;
		default: 
			cout << "Press 0 to compute the radius of the two circles, Press 1 to compute the circumference of the two circles, Press 2 to compute the area of the two circles, Press 3 to compute new values for circle 1, Press 4 to compute new values for circle 2, or Press 5 to exit" <<endl; 
		}
	}
}
