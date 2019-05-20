#include "RHorrace_prog2.h"

//Horrace, Robert CS202
/*
	This program is designed to hold the implementations
	of the two manager functions.
	The manager functions will be the food menu and the
	other will be the stock manager.
	A binary search tree will be used for the stock.
*/

stock::stock()//constructor
{
	root = NULL;
}
stock::~stock()//destructor
{
	delete_all();//call delete all function
}

void stock::build_tree()//build tree function
{
	ifstream fin;
	char ing[SIZE];
	int num;
	fin.open("RHorrace_stock.txt");//opens ext file
	if(fin.is_open())
	{
		fin.get(ing,SIZE,':');
		while(!fin.eof())
		{
			fin.ignore(SIZE,':');
			fin >> num;
			fin.ignore(SIZE,'\n');
			insert(ing,num);//call insert function
			fin.get(ing,SIZE,':');
		}
	fin.close();//close file
	}
}
int stock::insert(char ing[], int & num)//insert wrapper function
{
	return insert(root,ing,num);//call recursive function
}

int stock::insert(node *& root, char ing[], int & num)//insert recursive function
{
	if(!root)
	{
		root = new node(ing,num);//makes new node with arguments
		return 1;
	}
	if(root -> compare(ing) == 1) return insert(root -> go_left(),ing,num);//recursive call left
	if(root -> compare(ing) == -1) return insert(root -> go_right(),ing,num);//recursive call right
	else return 1;
}
int stock::insert_item(char ing[],char fd[],char tp[],char sd[])//insert item wrapper function
{
	return insert_item(root,ing,fd,tp,sd);//call recursive function
}
int stock::insert_item(node * root, char ing[], char fd[], char tp[], char sd[])//insert item recursive function
{
	if(!root) return 0;//if NULL
	if(root -> compare(ing) == 0) return root -> insert_item(fd,tp,sd);//if same ingredient
	if(root -> compare(ing) == -1) return insert_item(root -> go_right(),ing,fd,tp,sd);//if not same
	if(root -> compare(ing) == 1) return insert_item(root -> go_left(),ing,fd,tp,sd);//if not same
}

void stock::build_lists()//build lists function
{
	ifstream fin;
	char ing[SIZE];
	char fd[SIZE];
	char tp[SIZE];
	char sd[SIZE];

	fin.open("RHorrace_menu.txt");//open ext file
	if(fin.is_open())//check if open
	{
		fin.get(ing,SIZE,':');
		while(!fin.eof())
		{
			fin.ignore(SIZE,':');
			fin.get(fd,SIZE,':');
			fin.ignore(SIZE,':');
			fin.get(tp,SIZE,':');
			fin.ignore(SIZE,':');
			fin.get(sd,SIZE,'\n');
			fin.ignore(SIZE,'\n');
			insert_item(ing,fd,tp,sd);//call insert item function
			fin.get(ing,SIZE,':');
		}
	fin.close();//close file
	}

}

node *& stock::retrieve(char ing[])//retrieve wrapper function
{
	return retrieve(root,ing);//call recursive function
}

node *& stock::retrieve(node * root, char ing[])//retrieve recursive function
{
	if(!root) return root;
	if(root -> compare(ing) == 0) return root;//if a match
	if(root -> compare(ing) == 1) return retrieve(root -> go_left(),ing);//if not match
	if(root -> compare(ing) == -1) return retrieve(root -> go_right(),ing);//if not match
	return root;
}

int stock::update(char fd[], int & amnt)//update wrapper function
{
	return update(root,fd,amnt);//call recursive function
}

int stock::update(node *& root, char fd[], int & amnt)//update recursive function
{
	if(!root) return 0;//if NULL
	if(root -> update_amount(fd,amnt) == 0) return 0;//if out of stock
	if(update(root -> go_left(), fd, amnt) == 0 || update(root -> go_right(),fd,amnt) == 0) return 0;//if out of stock
	else return 1;
	
}

void stock::display_ing()//display ingredient function
{
	display_ing(root);//call recursive function
}

void stock::display_ing(node * root)//display ingredient function
{
	if(!root) return;//if NULL
	display_ing(root -> go_left());//display left side
	root -> display();//display root
	display_ing(root -> go_right());//display right side
}

void stock::display_all()//display all wrapper function
{
	display_all(root);//call recursive function
}

void stock::display_all(node * root)//display all recursive function
{
	if(!root) return;//if NULL
	display_all(root -> go_left());//display left side
	root -> display();//display ingredient
	root -> display_items();//display items
	display_all(root -> go_right());//display right side
}

int stock::delete_all()//delete all wrapper function
{
	return delete_all(root);//call recursive function
}

int stock::delete_all(node *& root)//delete all recursive function
{
	if(!root) return 0;//if NULL
	if(delete_all(root -> go_left())){}//delete left side
	if(delete_all(root -> go_right())){}//delete right side
	if(root -> delete_all_items() == 1){}//delete LLL
	delete root;
	root = NULL;
	return 1;
}

menu::menu()//constructor
{
	head = NULL;
}

menu::~menu()//destructor
{
	delete_all();//call delete all function
}

void menu::build()//build function
{
	ifstream fin;
	char fd[SIZE];
	char tp[SIZE];
	char sd[SIZE];
	fin.open("RHorrace_menuitems.txt");//open file
	if(fin.is_open())//if open
	{
		fin.get(fd,SIZE,':');
		while(!fin.eof())
		{
			fin.ignore(SIZE,':');
			fin.get(tp,SIZE,':');
			fin.ignore(SIZE,':');
			fin.get(sd,SIZE,'\n');
			fin.ignore(SIZE,'\n');
			insert(fd,tp,sd);//call insert function
			fin.get(fd,SIZE,':');
		}
		fin.close();//close file
	}
}

int menu::insert(char fd[], char tp[], char sd[])//insert wrapper function
{
	return insert(head,fd,tp,sd);//call recursive function
}

int menu::insert(foodnode *& head, char fd[], char tp[], char sd[])
{
	if(!head)//if NULL
	{
		head = new foodnode;
		head -> insert(fd,tp,sd);//call insert function
		return 1;
	}
	else return insert(head -> go_next(),fd,tp,sd);//go to next node if head is full
}

void menu::display_all()//display all wrapper function
{
	display_all(head);//call recursive function
}

void menu::display_all(foodnode * head)//display all recursive function
{
	if(!head) return;//if NULL
	head -> display();//call display function
	display_all(head -> go_next());//TRAVERSE TRAVERSE
}

int menu::delete_all()//delete all wrapper function
{
	delete_all(head);//call recursive function
}
int menu::delete_all(foodnode *& head)//delete all recursive function
{
	foodnode * temp = NULL;
	if(!head) return 0;//if NULL
	if(!head -> go_next())//if one node
	{
		delete head;
		head = NULL;
		return 1;
	}
		temp = head -> go_next();
		delete head;
		head = temp;
		return delete_all(head);//cal again
}
