#include "RHorrace_prog2.h"

//Horrace, Robert CS202
/*
   This program is designed to hold the implementations
   of the functions in the base and derived classes.
   All the functions, besides the virtual functions
   will be implemented.
   The base class will be an abstract base class and
   the derived classes will have the base class as their
   hub.
 */

item::item()//constructor
{
	food = NULL;
	type = NULL;
}

item::item(char fd[], char tp[])//initializing constructor
{
	food = new char[strlen(fd) + 1];
	strcpy(food,fd);
	type = new char[strlen(tp) + 1];
	strcpy(type,tp);
}

item::~item()//destructor
{
	if(food)
	{
		delete [] food;
		food = NULL;
	}
	if(type)
	{
		delete [] type;
		food = NULL;
	}
}

entree::entree():item()//constructor + initialization list
{
	side = NULL;
}

entree::entree(char fd[], char tp[], char sd[]):item(fd,tp)//initializing constructor + initialization list
{
	side = new char[strlen(sd) + 1];
	strcpy(side,sd);
}

entree::~entree()//destructor
{
	if(side)
	{
		delete [] side;
		side = NULL;
	}
	if(food)
	{
		delete [] food;
		food = NULL;
	}
	if(type)
	{
		delete [] type;
		type = NULL;
	}
}

int entree::compare(char fd[])//compare function
{
	if(!food) return 0;
	if(strcmp(food,fd) == 0) return 1;//if a match
	return 0;
}

void entree::display()//display function
{
	cout << type << ": " << food << endl;
	cout << "Side: " << side << endl;

}

appetizer::appetizer():item(){}//constructor + initialization list

appetizer::appetizer(char fd[], char tp[]):item(fd,tp){}//initializing constructor + initialization list

int appetizer::compare(char fd[])//compare function
{
	if(!food) return 0;
	if(strcmp(food,fd) == 0) return 1;//if the same
	return 0;
}

void appetizer::display()//display function
{
	cout << type << ": " << food << endl; 
}

drink::drink():item(){}//constructor + initialization list

drink::drink(char fd[], char tp[]):item(fd,tp){}//initializing constructor + initialization list

int drink::compare(char fd[])//compare function
{
	if(!food) return 0;
	if(strcmp(food,fd) == 0) return 1;//if the same
	return 0;
}

void drink::display()//display function
{
	cout << type << ": " << food << endl;
}
