//Shannon Rhodes
//ECE 2620
//Header file for classes
#define NULL 0
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
#define EMPTY_LIST 1

//Node Class
class IntDLLNode
{
	friend class IntDLList; //Need to access member functions in IntDLList

	public: //Constructor for creating the Nodes
		IntDLLNode();
		IntDLLNode(int = 0, IntDLLNode* =NULL,IntDLLNode* = NULL);
		
	protected: //Pointers for the Nodes
		int info;
		IntDLLNode *next,*prev;
};

//List Class
class IntDLList
{
	public:
		IntDLList() //Initializes head and tail
		{	
			head = tail = NULL;
		}
		~IntDLList();
		int isEmpty() //Returns 0 if there is nothing in the list
		{
			return (head == NULL);
		}
		//all the member functions for the IntDLList class
		void addToHead(int);
		void addToTail(int);
		int deleteFromHead();
		int deleteFromTail();
		void deleteNode(int);
		void sort();
		void addSortNode(int);
		bool isInList(int);
		int printList();
		int reversePrint();

	private: //Pointers for your list
		IntDLLNode *head, *tail;
};
#endif

//Stack class
class DLLStack
{	
	public: //Member functions for the DLLStack class
		DLLStack();
		bool isEmpty();
		int pop();
		void clear();
		void push(int element);
		int readFromStack();
		~DLLStack();
		int printStack();
		
	private: //List private variable to access the IntDLList class
		IntDLList lst;
};

//queue class
class DLLQueue
{	
	public: //Member functions for the DLLQueue
		DLLQueue();
		bool isEmpty();
		void EnQueue(int element);
		int DeQueue();
		int printQueue();
		void clear();
		~DLLQueue();

		//Data member so you can declare a list and reference functions from the IntDLList class
	private:
		IntDLList lst;
};