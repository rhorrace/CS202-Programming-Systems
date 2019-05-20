#include "RHorrace_prog1.h"

//Horrace,Robert CS202
/*
   This program is desinged to hold the classes
   for the census data. 
   These are derived classes from the location
   class in the hierarchy.
   All the functions and data will be used.
 */
class census:public location//census class location derived
{
	public:
		census();//constructor
		void insert(char hshld[], int & agemax, int & agemin, int & salary, int & x, int & y);
		void display();
	protected:
		char * household;
		int maxchild;
		int minchild;
		int income;


};

class censusvertex:public census//censusnode class census derived
{
	public:
		censusvertex();//constructor
		~censusvertex();//destructor
		void insert(char hshld[], int & agemax, int & agemin, int & salary, int & x, int & y);
		void display();
		void delete_edge();
	protected:
		class censusnode * head;
		void delete_edge(censusnode *& cur);
		censusnode * tail;


};

class censusnode
{
	public:
		censusnode();//constructor
		~censusnode();//destructor
		censusnode *& go_next();
		void connect_next(censusnode * connected);
	protected:
		censusvertex * adjacent;
		censusnode * next;
};

class censusgraph//graph class
{
	public:
		censusgraph();//constructor
		~censusgraph();//destructor
		int initialize();
		void build();//build function
		void insert_adjacent(char hshld, int & agemax, int & agemin, int & salary, int & x, int & y);//insert adjecent function
		void find_location();
		void display_all();//display_function
		void delete_all();//delete all function
	protected:
		censusvertex * censuslist;
};
