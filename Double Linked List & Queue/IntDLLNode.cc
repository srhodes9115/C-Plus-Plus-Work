//Shannon Rhodes
//ECE 2620
//Class IntDLLNode
#include "lab6headerfile.h"
#define NULL 0

//constructor that initializes the Nodes
IntDLLNode::IntDLLNode(int element, IntDLLNode *n,IntDLLNode *p)
{
	info = element;
	next = n;
	prev = p;
}