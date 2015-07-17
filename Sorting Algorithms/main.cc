//ECE 2620-001
//Shannon Rhodes
//Lab 6 - g++ main.cc insertionsort.cc sortfunctions.h -o main
//./main

#include <iostream>
#include <ctime>
#include "sortfunctions.h"
#include <fstream>
#define MAXSIZE 2100000
using namespace std; 

int main()
{
	//Declarations of all the variables
	int choice, n = 0,i = 0,count = 0,N = 0;
	double begin_time,end_time,cpu_time_used;
	long signed int x[MAXSIZE];
	//read in from the input file, create an output file
	ifstream infile;
	ofstream outfile;
	
	while (n == 0)
	{
	//Ask the user what they want to do
	cout << "Press 0 to read the data from the input file, Press 1 to sort using the insertion method, Press 2 to sort using the bubble method, Press 3 to sort using the merge method, Press 4 to sort using the radix method, Press 5 to exit" <<endl; 
		cin >> choice;
	switch (choice)
		{
		case 0://read data from input file 
			infile.open("lab5_largeinput.txt");
			cout <<"Reading the data from the input file: " << endl;
			for (;!infile.eof(); i++)
			{
				infile>>x[i];
				count++;
			}
			infile.close();
			N = count - 1;
			cout<<"The number of elements in the input file is "<<N<<endl;
			break;
		case 1://sort data using insertion sort, computes how long it takes, writes the sorted array into an outfile
			cout <<"Sorting the data using the insertion sort method" << endl;
			begin_time = clock();
			insertionsort(x,N);
			end_time = clock();
			cpu_time_used = (end_time-begin_time)/CLOCKS_PER_SEC;
			cout <<"The time to compute this sort is "<< cpu_time_used<<" seconds"<<endl;
			outfile.open("lab5_insertionsorted.txt");
			for (int i = 0; i < N; ++i)
			{
				outfile<<x[i]<<endl;
			}
			outfile.close();
			break;
		case 2://sort data using bubble sort, computes the time it takes to run, writes the sorted array into an outfile
			cout <<"Sorting the data using the bubble sort method" <<endl;
			begin_time = clock();
			bubblesort(x,MAXSIZE);
			end_time = clock();
			cpu_time_used = (end_time-begin_time)/CLOCKS_PER_SEC;
			cout <<"The time to compute this sort is "<< cpu_time_used<<" seconds"<<endl;
			outfile.open("lab5_bubblesorted.txt");
			for (int i = 0; i < N; ++i)
			{
				outfile<<x[i]<<endl;
			}
			outfile.close();
			break;
		case 3://sort data using merge sort, computes the time it takes to sort, writes the sorted array into an outfile
			cout <<"Sorting the data using the merge sort method" <<endl;
			begin_time = clock();
		    mergesort(x,MAXSIZE);
			end_time = clock();
			cpu_time_used = (end_time-begin_time)/CLOCKS_PER_SEC;
			cout <<"The time to compute this sort is "<< cpu_time_used<<" seconds"<<endl;
			outfile.open("lab5_mergesorted.txt");
			for (int i = 0; i < N; ++i)
			{
				outfile<<x[i]<<endl;
			}
			outfile.close();
			break;
		case 4://sort data using radix sort, computes the time it takes to sort the array, writes the sorted array into an outfile 
			cout <<"Sorting the data using the radix sort method"<<endl;
			begin_time = clock();
			radixsort(x,N);
			end_time = clock();
			cpu_time_used = (end_time-begin_time)/CLOCKS_PER_SEC;
			cout <<"The time to compute this sort is "<< cpu_time_used<<" seconds"<<endl;
			outfile.open("lab5_radixsorted.txt");
			for (int i = 0; i < N; ++i)
			{
				outfile<<x[i]<<endl;
			}
			outfile.close();
			break;
		case 5://exit the loop
			cout << "Exiting" << endl;
			n = 1;
			break;
		default:
			cout << "Press 0 to read the data from the input file, Press 1 to sort using the insertion method, Press 2 to sort using the bubble method, Press 3 to sort using the merge method, Press 4 to sort using the radix method, Press 5 to exit" <<endl; 
			cin >> choice;
		}
	}
}