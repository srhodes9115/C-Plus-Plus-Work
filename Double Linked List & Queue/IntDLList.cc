//Shannon Rhodes
//ECE 2620
//Class IntDLList
#define NULL 0
#include "lab6headerfile.h"
#include <iostream>
using namespace std;

//Destructor for the IntDLList
IntDLList::~IntDLList()
{
	for (IntDLLNode *p;	head!=NULL;)
	{
		p = head->next; //goes through each node
		delete head; //delete nodes
		head = p; //moves head to next node
	}
}

//Adds an elements to the tail
void IntDLList::addToTail(int element)
{
	if (tail != NULL) //the list is not empty
	{
		tail = new IntDLLNode(element,NULL,tail); //creates a new tail
		tail->prev->next = tail; // cahnges the previous pointer to point to the new tail
	}
	else
	{
		head = tail = new IntDLLNode(element); //creates the new node
	}
}

//Deletes the node at the end of the list
int IntDLList::deleteFromTail()
{
	if (head!=NULL) //if the list is not empty
	{
		int element = tail->info; 
		if (head == tail) //one node in the list
		{
			delete tail; 
			head = tail = NULL; //Sets the pointers to nothing
		}
		else 
		{
			tail = tail->prev; //Moves the tail to the previous node
			delete tail->next; //deletes the last node
			tail->next=NULL; //points the previous node to null
		}	
		return element; //returns the deleted element
	}
	else 
	{
		throw ("ERROR");
	}
}

//The user can add a new node to the head with a given element
void IntDLList::addToHead(int element)
{
	head = new IntDLLNode(element,head,NULL);
	if (tail == NULL) //There's one node in the list
	{
		tail = head;
	}
	else
	{
		head->next->prev = head; ///sets head to the next hode
	}
}

//Deletes elements from the head
int IntDLList::deleteFromHead()
{
	if(head != NULL) //If the list isnt empty
	{
		int element = head->info; //element is equal to the first node's elements
		IntDLLNode *tmp = head; 
		if (head == tail) //There's one node in the list
		{
			head = tail = NULL; 
		}
		else
		{
			head = head->next; // move the head pointer to the next node
			head->prev = NULL; // move the node prev pointer to null
		}
		delete tmp; //deletes the first node
		return element;
	}
	else 
	{
		throw ("ERROR");
	}
}

//Deletes any Node in the list that matches the user's choice
void IntDLList::deleteNode(int element)
{
	if (!isEmpty()) //if the list is Empty
	{
		if (head == tail && element == head->info) //Only one node in the list
		{
			delete head; 
			head = tail = NULL;		//Sets the pointers to null so there is no longer a node	
		}
		else if (element == head->info) // If more than 1 node is in the list and the head holds the element the user wants
		{
			IntDLLNode *tmp = head; 
			head = head->next; //move the head pointer to the next node
			delete tmp;		//deletes the first node
		}
		
		else
		{
			//For loop that goes through each node tmp points to the node in front of pred node
			IntDLLNode *tmp,*pred;
			for (pred = head,tmp = head->next; tmp!= NULL && tmp->info !=element; pred = pred->next, tmp = tmp->next) 
			{
				//The element equals the tmp
				if (tmp != NULL)
				{
					pred->next= tmp->next; //Takes the pred next pointer and moves it to the 
					if (tmp == tail)
					{
						tail = pred;
					}
					delete tmp;
				}
			}
		}
	}
	else 
	{
		throw "ERROR";
	}
}

//Add a node so it is inserted in the right position in the sorted list
void IntDLList::addSortNode(int element)
{ 
	if (head == NULL) //if the list is empty
	{
		head =tail = new IntDLLNode(element); //create a new node 
		return; //exits the function
	}
	
	if (element <= head->info) //compares the element to the head
	{
		head = new IntDLLNode(element,head,NULL); //creates a new node at the head
		head->next->prev = head; //sets the head to the next node
	    return; //exits the function
	}
	if (element >= tail->info) //compares the element to the tail
	{
		addToTail(element); //adds to the tail
	}
	IntDLLNode *tmp; //new node
	for (tmp = head->next; tmp!= NULL && tmp->info<element; tmp=tmp->next); //loop that doesn't go through the head or the tail
	if(tmp!= NULL) // the list isn't empty or pointing past the ends
	{
		tmp->prev->next=tmp->prev= new IntDLLNode(element,tmp,tmp->prev); //Creates the node and links it to the node on either side
	}
}

//Checks if an element is in the list
bool IntDLList::isInList(int element)
{
	IntDLLNode *tmp;
	for (tmp = head; tmp = tail; tmp->next) //Goes through the whole list
	{
		if (tmp->info == element) //If the element in the node equals the user's choice
		{
			cout<<"True"<<endl; //Returns true if the element is in the list
			return true;
		}
	}
	cout<<"False"<<endl; //Returns false if the element isn't in the list
	return false;
}

//Print the entire list
int IntDLList::printList()
{
	IntDLLNode *temp;

		for(temp = head; temp != NULL; temp = temp->next) //Goes through all the elements
		{
			cout<<temp->info<<endl; //Prints the element in each node
		}
}

//Prints the list in the opposite direction
int IntDLList::reversePrint()
{
	IntDLLNode* tmp;
	if (head == NULL) //Empty list
	{
		cout<<"Nothing in the loop"<<endl;
	}
	else
	{
		for (tmp = tail; tmp != NULL; tmp = tmp->prev) //Goes through all the elements
		{
			cout<<tmp->info<<endl;
		}
	}
}