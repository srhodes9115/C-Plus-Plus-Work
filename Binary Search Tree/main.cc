//Shannon Rhodes
//ECE 2640-001
// Lab 7 

#include <iostream>
#include "BST.h"
#include "BST.cc"
#include <fstream>
#include<string>
using namespace std;

int main()
{
	int choice,size;
	long int student_id,phone_number;
	string last_name, first_name,add_ress;
	BST<long int, string> mytree;

	ifstream infile("lab7_input.txt");
	ofstream outfile("lab7_output.txt");
	
	while (true)
	{
		cout<<"Choose 1 to read student records from the input file to the Binary Search Tree"<<endl;
		cout<<"Choose 2 to seach for a student"<<endl;
		cout<<"Choose 3 to edit the student record"<<endl;
		cout<<"Choose 4 to insert a student record"<<endl;
		cout<<"Choose 5 to delete a student record"<<endl;
		cout<<"Choose 6 to write records to the output file"<<endl;
		cout<<"Choose 7 to exit the program"<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1: 
				infile.open("lab7_input.txt");
				cout<<"Reading the student records from the input file into the binary search tree"<<endl;
				while(!infile.eof())
				{
					infile>>student_id>>last_name>>first_name>>add_ress>>phone_number;
					size++;
				}
				size = size-1;
				infile.close();
				infile.open("lab7_input.txt");
				for (int j = 0; j <size; j++)
				{
					infile>>student_id>>last_name>>first_name>>add_ress>>phone_number;
					mytree.insert(student_id,last_name,first_name,add_ress,phone_number);
				}
				mytree.inorder();
				break;
			case 2: 
				cout<<"Enter a student id number to find the student: "<<endl;
				cin>>student_id;
				cout<<"Searching for student "<<endl;
				break;
			case 3:
				cout<<"Enter a student id to edit that student's information"<<endl;
				cin>>student_id;
				cout<<"Editing the student ID"<<endl;
				break;
			case 4:
				cout<<"To insert a new student record:"<<endl;
				cout<<"Seperate the following by a space"<<endl;
				cout<<"There is no spaces or dashes in the phone number"<<endl;
				cout<<"Enter the student_id, lastname, firstname, adress, phonenumber"<<endl;
				cin>>student_id>>last_name>>first_name>>add_ress>>phone_number;
				cout<<"Insert the student record"<<endl;
				break;
			case 5:
				cout<<"Delete the student record"<<endl;
				break;
			case 6:
				cout<<"Writing the record to the output file"<<endl;
				outfile.open("lab7_output.txt");
				outfile.close();
				break;
			case 7:
				cout<<"Exit"<<endl;
				return false;
				break;
		}
	}
}
