//Shannon Rhodes
//ECE 2620-001
//Lab 4

#include <iostream>
#include <fstream>
using namespace std;

//Findmax function that gets the max value of each line 
int findmax (int input1, int input2, int input3, int input4, int input5)
{ 
	int x[] = {input1, input2, input3, input4, input5}; 
	int max = input1;
	for (int i = 0; i < 5; ++i)
	{
		if (x[i] > max)
		   {
				max = x[i];
			}
	}		
	return max;
}

int main()
{
	//Variable Declarations
	int n = 0;
	int max, input1, input2,input3,input4,input5;

	//Ask the user for the number of lines
	cout << "Input the number of lines 'n' in the input file" <<endl;
	cin >> n;

	//Read the file "lab4_input.txt" and create a dynamic array
	ifstream infile("lab4_input.txt");
	int *array;
	array = new int [n];

	//Loop that reads all the inputs of each line and calls the max function
	for (int i = 0; i < n; ++i)
	{ 
		infile>>input1>>input2>>input3>>input4>>input5;
		array[i] = findmax(input1,input2,input3,input4,input5);
		cout<<array[i]<<" ";
	}

	//Creates a new output file and prints the array with the max values 
	ofstream outfile("lab4_output.txt");
	for (int i = 0; i < 5; ++i)
	{
		outfile<<array[i]<<endl;
	}
	
	//deletes the array
	delete [] array;
}