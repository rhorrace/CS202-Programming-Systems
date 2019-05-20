#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

//Horrace, Robert CS202
/*
   This .h file is designed to hold all the classes of the program.
   The classes will utilize inheritance and use relationships in
   order to run the program.
   Object oriented programming and dynamic binding will be used.
 */

const int SIZE = 100;


class item//abstract base class
{
	public:
		item();//constructor
		item(char fd[], char tp[]);//constructor for initialization
		virtual ~item();//virtual destructor
		virtual int compare(char fd[]) = 0;//virtual compare function
		virtual void display() = 0;//virtual display function
	protected:
		char * food;//food char pointer
		char * type;//food type char pointer
};

class entree:public item//class derived from item
{
	public:
		entree();//constructor
		entree(char fd[], char tp[], char sd[]);//constructor for initialization
		~entree();//destructor
		int compare(char fd[]);//compare function
		void display();//display functions
	protected:
		char * side;//side variable
};

class appetizer:public item//class derived from item
{
	public:
		appetizer();//constructor
		appetizer(char fd[], char tp[]);//constructor for initialization
		int compare(char fd[]);//compare function
		void display();//display function
	protected:
};

class drink:public item//class derived from item
{
	public:
		drink();//constructor
		drink(char fd[], char tp[]);//constructor for initialization
		int compare(char fd[]);//compare function
		void display();//display function
	protected:
};

class foodnode//node class for LLL of menu items
{
	public:
		foodnode();//constructor
		~foodnode();//destructor
		foodnode *& go_next();//travers function
		void connect_next(foodnode * connect);//connect node function
		void insert(char fd[],char tp[],char sd[]);//insert function
		int compare(char fd[]);//compare function
		void display();//display function
	protected:
		item * itm;//base class pointer for dynamic binding
		foodnode * next;//next pointer
};
class node//class for tree nodes
{
	public:
		node();//constructor
		node(char ing[], int & num);//constructor with arguments
		~node();//destructor
		void connect_left(node * connect);//connect left function
		void connect_right(node * connect);//connect right function
		node *& go_left();//traverse left function
		node *& go_right();//traverse right function
		int insert_item(char fd[], char tp[], char sd[]);//insert item wrapper function
		int compare(char ing[]);//compare function
		int update_amount(char fd[], int & amnt);//update amount wrapper function
		void display();//display ingredient function
		void display_items();//display item wrapper function
		int delete_all_items();//delete all all items wrapper function
	protected:
		int insert_item(foodnode *& fhead, char fd[], char tp[], char sd[]);//insert item recursive function
		int update_amount(foodnode * fhead, char fd[], int & amnt);//update amount recursive function
		void display_items(foodnode * fhead);//display items recursive functioni
		int delete_all_items(foodnode *& fhead);//delete all items recursive function
		char * ingredient;//ingredient variable
		int amount;//ingredient amount variable
		foodnode * fhead;//foodnode pointer for LLL
		node * left;//left pointer
		node * right;//right pointer

};

class stock//tree class BST
{
	public:
		stock();//constructor
		~stock();//destructor
		void build_tree();//build tree function
		int insert(char ing[], int & num);//insert wrapper function
		int insert_item(char ing[], char fd[], char tp[], char sd[]);//insert item wrapper function
		node *& retrieve(char ing[]);//retrieve function
		void build_lists();//build LLL function
		int update(char fd[], int & amnt);//update wrapper function
		void display_ing();//display ingredient wrapper function
		void display_all();//display all wrapper function
		int delete_all();//delete all nodes wrapper function
	protected:
		int insert(node *& root, char ing[], int & num);//insert recursive function
		int insert_item(node * root, char ing[], char fd[], char tp[], char sd[]);//insert item recursive function
		node *& retrieve(node * root, char ing[]);//retrieve recursive function
		int update(node *& root, char fd[], int & amnt);//update recursive function
		void display_ing(node * root);//display ingredient recursive function
		void display_all(node * root);//display all recursive function
		int delete_all(node *& root);//delete all recursive function
		node * root;//root pointer
};

class menu//menu class for the customer
{
	public:
		menu();//constructor
		~menu();//destructor
		void build();//build function
		int insert(char fd[], char tp[], char sd[]);//insert wrapper function
		void display_all();//display all wrapper function
		int delete_all();//delete all wrapper function
	protected:
		int insert(foodnode *& head, char fd[], char tp[], char sd[]);//insert recursive function
		void display_all(foodnode * head);//display all recursive function
		int delete_all(foodnode *& head);//delete all recursive function
		foodnode * head;//foodnode pointer
};
