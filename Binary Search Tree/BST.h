//Shannon Rhodes
//ECE 2640-001
//Header file
#include <iostream>
using namespace std;

template <class T,class C>
class BSTNode
{
	public:
		BSTNode() 
		{
			left = right = NULL;
		}
		BSTNode(const T id, const C last, const C first, const C add_ress, const T telenum, BSTNode<T,C> *l = NULL, BSTNode<T,C> *r = NULL)
		{
			studentid = id;
			lastname = last;
			firstname = first;
			address = add_ress;
			phonenumber = telenum;
			left = l;
			right = r;
		}	
		T studentid,phonenumber;
		C lastname,firstname,address;
		BSTNode<T,C> *left,*right;
};

template<class T,class C>
class BST
{
	public:
		BST()
		{
			root = NULL;
		}
		bool isEmpty() const
		{
			return (root == NULL);
		}
		BSTNode<T,C> *root;
		void inorder(BSTNode<T,C>* p);
		void inorder();
		void insert(const T id,const C lastname,const C firstname,const C address,const T phonenumber);
	//protected:
		
		T* search(const T&) const;	
		void visit(BSTNode<T,C>* p);
		void deleteNode(BSTNode<T,C>*& node);
};