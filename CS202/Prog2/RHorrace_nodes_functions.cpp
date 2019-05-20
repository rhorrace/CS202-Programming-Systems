#include "RHorrace_prog2.h"

//Horrace, Robert CS202
/*
	this program is designed to hold the functions for the node classes.
	Each function will be implmented and used somehow.
	Dynamic binding will be used in the foodnode class.
*/

foodnode::foodnode()//constructor
{
	itm = NULL;
	next = NULL;
}

foodnode::~foodnode()//destructor
{
	if(itm)
	{
		delete itm;
		itm = NULL;
	}
}

foodnode *& foodnode::go_next()//next function
{
	return next;
}
void foodnode::connect_next(foodnode * connect)//connect next function
{
	next = connect;
}
void foodnode::insert(char fd[],char tp[], char sd[])//insert function
{
	if(strcmp(tp,"entree") == 0)//if entree
	{
		itm = new entree(fd,tp,sd);
	}
	else if(strcmp(tp,"appetizer") == 0)//if appetizer
	{
		itm = new appetizer(fd,tp);
	}
	else if(strcmp(tp,"drink") == 0)//if drink
	{
		itm = new drink(fd,tp);
	}	
}

int foodnode::compare(char fd[])//compare function
{
	if(!itm) return 0;//no exist
	return itm -> compare(fd);//returns 0 or 1 depending if match or not
}

void foodnode::display()//display function
{
	if(itm) itm -> display();
}
node::node()//constructor
{
	fhead = NULL;
	left = NULL;
	right = NULL;
	ingredient = NULL;
	amount = 0;
}
node::node(char ing[], int & num)//initializing constructor
{
	ingredient = new char[strlen(ing) + 1];
	strcpy(ingredient, ing);
	amount = num;	
}

node::~node()//destructor
{
	if(ingredient)
	{
		delete [] ingredient;
		ingredient = NULL;
	}
	delete_all_items();//delete all items function
	amount = 0;
}
void node::connect_left(node * connect)//connect left function
{
	left = connect;
}

void node::connect_right(node * connect)//connect right function
{
	right = connect;
}

node *& node::go_left()//traverse to left function
{
	return left;
}

node *& node::go_right()//traverse to right function
{
	return right;
}

int node::insert_item(char fd[], char tp[], char sd[])//insert item wrapper function
{
	return insert_item(fhead,fd,tp,sd);//calls recursive function
}

int node::insert_item(foodnode *& fhead, char fd[], char tp[],char sd[])//insert item recursive function
{
	if(!fhead)//if NULL
	{
		fhead = new foodnode;
		fhead -> insert(fd, tp, sd);
		return 1;
	}
	else
	{
		return insert_item(fhead -> go_next(),fd,tp,sd);//TRAVERSE TRAVERSE
	}
}

int node::compare(char ing[])//compare ingredient function
{
	if(strcmp(ingredient,ing) > 0) return 1;//ing is less than
	if(strcmp(ingredient,ing) < 0) return -1;//ing is greater
	if(strcmp(ingredient,ing) == 0) return 0;//same
}

void node::display()//display function
{
	cout << "Ingredient: " << ingredient << endl;
	cout << "Amount: " << amount << endl;
}

int node::update_amount(char fd[], int & amnt)
{
	return update_amount(fhead,fd,amnt);
}

int node::update_amount(foodnode * fhead, char fd[], int & amnt)
{
	if(!fhead) return 0;
	if(fhead -> compare(fd) == 1)
	{
		amount -= amnt;
		if(amount < 0) return 0;
		return 1;	
	}	
}

void node::display_items()//display items wrapper function
{
	display_items(fhead);//recursive call
}

void node::display_items(foodnode * fhead)//display items recursive function
{
	if(!fhead) return;
	fhead -> display();
	display_items(fhead -> go_next());
}

int node::delete_all_items()//delete all items wrapper function
{
	return delete_all_items(fhead);//recursive call
}
int node::delete_all_items(foodnode *& fhead)//delete all items recursive function
{
	foodnode * temp = NULL;
	if(!fhead) return 0;
	if(!fhead -> go_next())
	{
	delete fhead;
	fhead = NULL;
	return 1;
	}
	temp = fhead -> go_next();
	delete fhead;
	fhead = temp;
	delete_all_items(fhead);//TRAVERSE TRAVERSE
}
