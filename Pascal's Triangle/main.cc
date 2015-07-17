// Shannon Rhodes
// HW1
// ECE 2620 - Pascal's triangle

#include <iostream>
#include <stdio.h>

double factorial (double n)
{
	int solution;
	for (int i = 0; i <= n; i++)
	     {
			 if (i == 0)
			 	 solution = 1;
			 else
				solution = solution*i; 
		 }
	     return solution; 
}
double pascal_triangle (int n, int p)
{
   int triangle = 0;
	triangle = factorial(n)/(factorial(p)*factorial(n-p));
	return triangle; 
}

int main()
{
	//n is the row #, p is the column number

	for (int n = 0,num = 15; n <= num; n++)
	{
	    
		for (int p = 0; p <= n; p++)
		{
			printf ("%f",pascal_triangle(n,p));
 		}
		printf ("\n");
	}
}