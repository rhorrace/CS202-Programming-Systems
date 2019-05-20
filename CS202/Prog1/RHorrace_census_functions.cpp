#include "RHorrace_census.h"

//Horrace, Robert CS202

/*
   This program is designed to
   hold the implementations of
   the functions in census.h.
   All functions will be implemented.

 */

census::census()
{
	household = NULL;
	maxchild = 0;
	maxchild = 0;
	income = 0;	
}

void census::insert(char hshld[], int & agemax, int & agemin, int & salary, int & x, int & y)//census insert function
{
	household = new char[strlen(hshld) + 1];
	strcpy(household,hshld);
	maxchild = agemax;
	minchild = agemin;
	income = salary;
	location::insert(x,y);//call location's insert
}

void census::display()
{
	cout << household << endl;
	cout << "Oldest child's age: " << maxchild << endl;
	cout << "Youngest child's age: " << minchild << endl;
	cout << "Median household income: $ " << income << endl;
}

censusvertex::censusvertex()
{
	head = NULL;
	tail = NULL;
}

void censusvertex::insert(char hshld[], int & agemax, int & agemin, int & salary, int & x, int & y)
{
	census::insert(hshld,agemax,agemin,salary,x,y);
}
void censusvertex::display()
{
	census::display();
}
/*
void censusvertex::delete_edge()
{
	if(head) delete_edge(head);
}

void censusvertex::delete_edge(censusnode *& head)
{
	if(head -> go_next()) delete_edge(head -> go_next());
	delete head;
	head = NULL;
}

censusnode::censusnode()
{
	adjacent = NULL;
	next = NULL;
}

censusnode::~censusnode()
{
	if(adjacent)
	{
		delete adjacent;
		adjacent = NULL;
	}
	if(next)
	{
		delete next;
		next = NULL;
	}
}

censusnode *& censusnode::go_next()
{
	return next;
}

void censusnode::connect_next(censusnode * connected)
{
	next = connected;
}

censusgraph::censusgraph()
{
	censuslist = NULL;
}

censusgraph::~censusgraph()
{
	delete_all();
}

int censusgraph::initialize()
{
	ifstream fin;
	char line[SIZE];
	int count = 0;
	fin.open("census.txt");
	if(fin.is_open())
	{
		fin.get(line,SIZE,'\n');
		while(!fin.eof())
		{
			fin.ignore(SIZE,'\n');
			++count;
			fin.get(line,SIZE,'\n');
		}
		fin.close();
		cout << count;
	}
	return count;
}

void censusgraph::delete_all()
{
	for(int i = 0; i < 4; ++i)
	{
		(censuslist + i) -> delete_edge(); 
	}
	delete [] censuslist;
	censuslist = NULL;
}*/
