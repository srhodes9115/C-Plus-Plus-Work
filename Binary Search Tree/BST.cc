//Shannon Rhodes
//ECE 2640-01
//Binary Search Tree Class
#include <fstream>
#include "BST.h"

template<class T,class C>
void BST<T,C>::deleteNode(BSTNode<T,C>*& node) //delete the node
{
	BSTNode<T,C> *tmp = node; //create a temp node to delete
	if (node != 0) //there is nothing in the node
	{
		if(!node->right) //node has no child to the right 
			node = node->left;
		else if (node->left == NULL)
			node = node->right;
		else
		{
			tmp = node->left;
			while (tmp->right != NULL)
				tmp = tmp->right;
			tmp->right = node->right;
			tmp = node;
			node = node->left;
		}
		delete tmp;
	}
}

template<class T,class C>
T* BST<T,C>::search(const T& el) const
{
	BSTNode<T,C> *p = root;
	while (p!=NULL)
	{
		if (el == p->studentid)
		{
			return (p); //&p->studentid
		}
		else 
		{
			if (el < p->studentid)
			{
				p = p->left; //keep searching, go to left sub-tree
			}
			else
			{
				p = p->right; //Go to right sub-tree
			}
		}
	}
	return (NULL);
}

template<class T,class C>
void BST<T,C>::insert(const T id,const C lastname,const C firstname,const C address,const T phonenumber)
{
	BSTNode<T,C> *p = root, *prev = NULL;
	while(p!= NULL)
	{
		prev = p;
		if (id < p->studentid)
		{
			p = p->left;
		}
		else 
		{
			p = p->right;
		}
	}
	if (root == NULL)
	{
		root = new BSTNode<T,C>(id,lastname,firstname,address,phonenumber);
	}
	else
	{
		if (id < prev->studentid)
		{
			prev->left = new BSTNode<T,C>(id,lastname,firstname,address,phonenumber);
		}
		else
		{
			prev->right = new BSTNode<T,C>(id,lastname,firstname,address,phonenumber);
		}
	}
}

template<class T,class C>
void BST<T,C>::inorder(BSTNode<T,C>* p)
{
	if (p!= NULL)
	{
		inorder(p->left);
		visit(p);
		inorder(p->right);
	}
} 

template<class T, class C>
void BST<T,C>::inorder()
{
		inorder(root);
}

template<class T,class C>
void BST<T,C>::visit(BSTNode<T,C> *p)
{
	cout<<p->studentid<<" ";
}