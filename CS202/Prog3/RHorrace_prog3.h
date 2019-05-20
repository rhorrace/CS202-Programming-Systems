#include "RHorrace_operators.h"

//Horrace, Robert CS 202

/*
   This program designed to hold
   the classes being used.
   There will be object oriented 
   programming and operator overloading
   if possible.
   All functions will be used somewhere in this program.
 */

const int HSH = 20;//hash size
const int SIZE = 100;//default size of arrays
const int TEXT = 500;//size of text messages

class text//text class
{
	public:
		text();//default constructor
		text(char nm[]);//initialization constructor
		~text();//destructor
		int compare(char nm[]);//compare function
		void display();//display function
	protected:
		char * name;//string variable for name
};

class message:public text//message class derived from text
{
	public:
		message();//default constructor
		message(char nm[],char msg[],char dt[]);//initialization constructor
		~message();//destructor
		int compare(char nm[]);//compare function
		void display();//display function
	protected:
		char * txt;//string variable for text message
		char * date;//string variable for the date sent
};

class textnode:public message//textnode class derived from message
{
	public:
		textnode();//default constructor
		textnode(char nm[],char msg[],char dt[]);//initialization constructor
		~textnode();//destructor
		textnode *& go_next();//next function
		void connect_next(textnode * connect);//connect to next function
		int compare(char nm[]);//compare function
		void display();//display function
	protected:
		textnode * next;//next pointer

};

class texts//hash table class
{
	public:
		texts();//default constructor
		~texts();//destructor
		void build();//build function
		int hash(char nm[]);//hash function
		int insert(char nm[], char msg[], char dt[]);//insert function
		int save(char nm[], char msg[], char dt[]);//write to file function
		int display(char nm[]);//display if match wrapper function
		int display_all();//display all wrapper fucntion
		int delete_all();//delete all wrapper function
	protected:
		int insert(textnode *& head, char nm[], char msg[], char dt[]);//insert recursive function
		int display_list(textnode * head, char nm[]);//display list recursive function
		int display_all(textnode * head);//display all recursive function
		int delete_all(textnode *& head);//delete all recursive function
		textnode ** head;//textnode pointer of pointers
};

class node//node class
{
	public:
		node();//default constructor
		node(const char pnt[],int & nm);//initialiation constructor
		~node();//destructor
		node *& go_left();//left function
		node *& go_right();//right function
		void connect_left(node * connect);//conect to left function
		void connect_right(node * connect);//connect to right function
		int compare(int & nm);//compare function
		int compare_pnt(const char pos[]);//compare position function
		int initiate(const char pnt[]);//initiate function
		void display();//display function
	protected:
		char * point;//start and finish char pointer
		int num;//number for creating the tree
		node * left;//left pointer
		node * right;//right pointer
};

class maze//modified AVL tree
{
	public:
		maze();//default constructor
		~maze();//destructor
		void build(int & lvl);//build function
		int initiate_start();//set start function
		int initiate_end(int & hgt);//set finish function
		int move_player(const char choice[]);//move position function
		int delete_all();//delete all wrapper function
	protected:
		int insert(node *& root,const char pnt[],int & nm);//insert function
		int rotate_to_left_once(node *& root);//rotate to the left function
		int rotate_to_left_twice(node *& root);//rotate to the left twice function
		int rotate_to_right_once(node *& root);//rotate to the right once function
		int rotate_to_right_twice(node *& root);//rotate to the right twice function
		int height(node * root);//height function
		int initiate_end(node *& root, int & nm, const char pnt[]);//set fincish recursive function
		int display_all(node * root);//display all recursive function
		int delete_all(node *& root);//delete all recursive function
		node * root;//root pointer
		node * position;//player position pointer, this will move through the tree.
};

void txt(texts & my_txts);//texts function

void mz();//maze function

void calc();//calculator function

