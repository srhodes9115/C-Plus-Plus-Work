//Shannon Rhodes
//ECE 2060-001
//Mergesort.cc file
#include <iostream>
using namespace std;

long signed int merge (long signed int size, long signed int list1[], long signed int size1, long signed int list2[], long signed int size2, long signed int list3[]) 
{	
	//declarations of the counters for the loops
	long signed int i1 = 0, i2 = 0, i3 = 0; 

	//if the sub arrays add up to be bigger than the actual array --> exit
	if (size1+size2 > size) 
		return false; 

	// while both lists are non-empty  
	while ((i1 < size1) && (i2 < size2)) 
	{ 
		if (list1[i1] < list2[i2]) 
			list3[i3++] = list1[i1++];
		else 
			list3[i3++] = list2[i2++]; 
	} 

	while (i1 < size1) 
	{ // copy remainder of list1  
		list3[i3++] = list1[i1++]; 
	} 

	while (i2 < size2) 
	{ // copy remainder of list2  
		list3[i3++] = list2[i2++]; 
	} 
	return true; 
}

void mergesort(long signed int array[], long signed int size) 
{ 
	//Declarations
	long signed int temp[size]; 
	long signed int mid, i; 

	//the array only has one element it doesn't need to be sorted
	if (size < 2) 
		return;  

	//merges the sorted sub arrays back to the original array
	else 
		mid = size / 2; 
		mergesort(array, mid); 
		mergesort(array + mid, size - mid); 
		merge (size,array, mid, array + mid, size - mid, temp); 
	for (i = 0; i < size; i++) 
	{ 
		array[i] = temp[i]; 
	}   
}	
