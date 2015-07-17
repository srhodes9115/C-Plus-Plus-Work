//Shannon Rhodes
//ECE 2640-001
//Stack Class
#include "lab6headerfile.h"
#include <iostream>
#define NULL 0
using namespace std;

//Constructor for the Stack
DLLStack::DLLStack()
{
}

//Deletes all the elements in the stack
void DLLStack::clear()
{
	while (!lst.isEmpty())
		lst.deleteFromHead();
}

//Destructor for the Stack
DLLStack::~DLLStack()
{
	clear();
}

//checks if the stack has any elements
bool DLLStack::isEmpty() 
{
	return lst.isEmpty();
}

//Deletes element from the top of the stack
int DLLStack::pop()
{
	return (lst.deleteFromHead());
}

//Push in the stack = adds an element to the head
void DLLStack::push(int element)
{
	lst.addToHead(element);
}

//prints the stack out element by element
int DLLStack::readFromStack()
{
	lst.printList();
}