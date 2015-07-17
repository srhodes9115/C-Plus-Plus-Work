//Shannon Rhodes
//ECE 2620
//Lab 6 

#include <iostream>
#include "lab6headerfile.h"
#define NULL 0
using namespace std;

int main()
{ 
	//Declarations
	int choice,pick; //could be char - doesn't work for letters
	IntDLList mylist; //Creates a list
	DLLStack mystack; //Creates a stack
	DLLQueue myqueue; //Creates a Queue
	
	while (true)
	{
		//Initial options
		cout<<"Please pick one of these options:"<<endl;
		cout<<"Choose 1 to Create a Simple (unsorted) list"<<endl;
		cout<<"Choose 2 to create a sorted list"<<endl;
		cout<<"Choose 3 to create a FIFO Queue"<<endl;
		cout<<"Choose 4 to create a LIFO Queue (Stack)"<<endl;
		cout<<"Choose 5 to Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1://Create a simple unsorted List
				while(true)
				{
					cout<<"Pick one of these options: Choose 1 to enter an integer for insertion at the head of the list"<<endl;
					cout<<"Choose 2 to enter an integer for insertion at the tail of the list"<<endl;
					cout<<"Choose 3 to display and delete the integer from the head of the list"<<endl;
					cout<<"Choose 4 to display and delete the integer from the tail of the list"<<endl;
					cout<<"Choose 5 to search for an integer in the list, and delete that node"<<endl;
					cout<<"Choose 6 to display the contents of the list from head to tail, in order"<<endl;
					cout<<"Choose 7 to exit the program"<<endl;
					cin>>choice;
					switch(choice)
					{
						case 1: //Asks the user to enter integer for insertion at head"
							cout<<"Enter integer for insertion at head"<<endl;
							cin>>pick;
							mylist.addToHead(pick);
							break;
						case 2://Asks the user to enter integer for insertion at tail of the list
							cout<<"Enter integer for insertion at tail of the list"<<endl;
							cin>>pick;
							mylist.addToTail(pick);
							break;
						case 3://Display and delete integer from head of list 
							try //Try clause to prevent the user from deleting something that isn't there
							{
								mylist.deleteFromHead();
							}
							catch (char *s)
								{
									cerr<<"Error: "<<s<<endl;
								}
							int tmp;
							tmp = mylist.deleteFromHead();
							cout<<"The deleted integer at the head was "<<tmp<<endl;;
							break;
						case 4://Display and delete integer from tail of list
							try //Try clause prevents the user from deleting something that isn't actually in the list because the computer has nothing to reference
							{
								mylist.deleteFromTail();
							}
							catch (char *s)
								{
									cerr<<"Error: "<<s<<endl;
								} 
							int tmp2;
							tmp2 = mylist.deleteFromTail();
							cout<<tmp2<<" was deleted from the tail"<<endl;
							break;
						case 5://Search for integer in list, and delete that node 
							cout<<"Enter which integer would you like to delete?"<<endl;
							cin>>pick;
							if(mylist.isInList(pick) == true) //Checks if this integer is in the list
							{
								mylist.deleteNode(pick);
							}
							else
							{	
								cout<<pick<<" was deleted"<<endl;
							}
							break;
						case 6://Display the contents of list from head to tail, in order
							cout<<"The contents of the list are: "<<endl;
							mylist.printList();
							break;
						case 7://Exit the program
							cout<<"Exiting"<<endl;
							return 0;
						default:
							cout<<"Pick one of these options: Choose 1 to enter an integer for insertion at the head of the list"<<endl;
							cout<<"Choose 2 to enter an integer for insertion at the tail of the list"<<endl;
							cout<<"Choose 3 to display and delete the integer from the head of the list"<<endl;
							cout<<"Choose 4 to display and delete the integer from the tail of the list"<<endl;
							cout<<"Choose 5 to search for an integer in the list, and delete that node"<<endl;
							cout<<"Choose 6 to display the contents of the list from head to tail, in order"<<endl;
							cout<<"Choose 7 to exit the program"<<endl;
							cin>>choice;
						}
				}
				break;
			case 2://Create a sorted list
				while(true)
				{
					cout<<"Please pick one of the options:"<<endl;
					cout<<"Choose 1 to enter an integer for sorted insertion (increasing order) into list"<<endl;
					cout<<"Choose 2 to search and delete the integer, if present in the list"<<endl;
					cout<<"Choose 3 to display the contents of the sorted list of integers, in increasing order"<<endl;
					cout<<"Choose 4 to exit the program"<<endl;
					cin>>choice;
					switch(choice)
					{
						mylist.sort();
						case 1://Enter integer for sorted insertion(increasing order) into list
							cout<<"Enter an integer for sorted insertion "<<endl;
							cin>>pick;
							mylist.addSortNode(pick);
							break;
						case 2://Search and delete integer, if present in list
							cout<<"Enter an integer to delete if present in the list"<<endl;
							cin>>pick;
							if(mylist.isInList(pick) == true) //Checks if this integer is in the list
							{
								mylist.deleteNode(pick);
								cout<<pick<<" was deleted"<<endl;
							}
							else
							{
								cout<<pick<<" is not in the list"<<endl;
							}	
							break;
						case 3://Display contents of sorted list of integers, in increasing order
							cout<<"The contents of the list are: "<<endl;
							mylist.printList();
							break;
						case 4://Exit the program
							return 0;
							break;
						default: //Repeats offer to user
							cout<<"Please pick one of the options:"<<endl;
							cout<<"Choose 1 to enter an integer for sorted insertion (increasing order) into list"<<endl;
							cout<<"Choose 2 to search and delete the integer, if present in the list"<<endl;
							cout<<"Choose 3 to display the contents of the sorted list of integers, in increasing order"<<endl;
							cout<<"Choose 4 to exit the program"<<endl;
							cin>>choice;
							break;
					}
				}
				break;
			case 3://Create FIFO Queue
				while(true)
				{
					cout<<"Choose one of the following options:"<<endl;
					cout<<"Choose 1 to ENQUEUE"<<endl;
					cout<<"Choose 2 to DEQUEUE"<<endl;
					cout<<"Choose 3 to PRINT QUEUE"<<endl;
					cout<<"Choose 4 to Exit the program"<<endl;
					cin>>choice;
					switch(choice)
					{
						case 1://Enter integer for insertion into queue
							cout<<"Enter an integer to insert to the queue"<<endl;
							cin>>pick;
							myqueue.EnQueue(pick);
							break;
						case 2://Display and delete integer from queue
							int temp;
							temp = myqueue.DeQueue();
							cout<<"Deleted "<<temp<<" from queue"<<endl;
							break;
						case 3://Display queue contents without deleting anything, first element first
							cout<<"The Queue is: "<<endl;
							myqueue.printQueue();
							break;
						case 4://Exit the program
							return 0;
							break;
						default: //Repeats offer to user
							cout<<"Choose one of the following options:"<<endl;
							cout<<"Choose 1 to ENQUEUE"<<endl;
							cout<<"Choose 2 to DEQUEUE"<<endl;
							cout<<"Choose 3 to PRINT QUEUE"<<endl;
							cout<<"Choose 4 to Exit the program"<<endl;
							cin>>choice;
							break;
					}
				}
				break;
			case 4://Create LIFO Queue (Stack)
				while(true)
				{   
					cout<<"Choose one of the following options:"<<endl;
					cout<<"Choose 1 to PUSH"<<endl;
					cout<<"Choose 2 to POP"<<endl;
					cout<<"Choose 3 to PRINT STACK"<<endl;
					cout<<"Choose 4 to exit the program"<<endl;
					cin>>choice;
					switch(choice)
					{
						case 1://Enter integer for insertion into stack
							cout<<"Enter an integer for insertion into the stack"<<endl;
							cin>>pick;
							mystack.push(pick);
							break;
						case 2://Display integer and delete it from the stack
							int temp;
							temp = mystack.pop();
							cout<<temp<<" has been popped from the stack"<<endl;
							break;
						case 3://Display stack contents without deleting anything,last element first
							cout<<"The stack is: "<<endl;
							mystack.readFromStack();
							break;
						case 4://Exit the program
							return 0;
							break;
						default://Repeats offer to user
							cout<<"Choose one of the following options:"<<endl;
							cout<<"Choose 1 to PUSH"<<endl;
							cout<<"Choose 2 to POP"<<endl;
							cout<<"Choose 3 to PRINT STACK"<<endl;
							cout<<"Choose 4 to exit the program"<<endl;
							cin>>choice;
							break;
					}
				}
				break;
			case 5://Exit the Program
					cout << "Exiting" << endl;
					return false;
					break;
			default: //Repeats offers to user
				cout<<"Please pick one of these options:"<<endl;
				cout<<"Choose 1 to Create a Simple (unsorted) list"<<endl;
				cout<<"Choose 2 to create a sorted list"<<endl;
				cout<<"Choose 3 to create a FIFO Queue"<<endl;
				cout<<"Choose 4 to create a LIFO Queue (Stack)"<<endl;
				cout<<"Choose 5 to Exit"<<endl;
				cin>>choice;
		}
	}
}