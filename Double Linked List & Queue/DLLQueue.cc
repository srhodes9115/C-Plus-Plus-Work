//Shannon Rhodes
//ECE 2640-001
//DLLQueue
#include "lab6headerfile.h"
#include <iostream>

//Queue Constructor
DLLQueue::DLLQueue()
{
}

//Checks if the list has any elements
bool DLLQueue::isEmpty()
{
	return lst.isEmpty();
}

//Adds element to the queue
void DLLQueue::EnQueue(int element)
{
	lst.addToTail(element);
}

//Takes elements from the queue
int DLLQueue::DeQueue()
{
	return lst.deleteFromHead();
}

//Prints the queue
int DLLQueue::printQueue()
{
		return lst.reversePrint();
}

//deletes all the elements in the queue
void DLLQueue::clear()
{
	while(!lst.isEmpty())
		lst.deleteFromHead();
}

//Destructor for the queue
DLLQueue::~DLLQueue()
{
	clear();
}