#include "RHorrace_prog1.h"

//Horrace,Robert CS202
/*
   This program is desinged to hold the classes
   for the school data. 
   These are derived classes from the location
   class in the hierarchy.
   All the functions and data will be used.
 */

class school:public location//school class location derived
{
	public:
		school();//school constructor
		void insert(char nm[], int & agemin, int & agemax, int & clssnm, int & sz, int & mx, int & x, int & y);//insert function
		void display();//display function
	protected:
		char * name;
		int agemin;
		int agemax;
		int classnum;
		int bestsize;
		int max;
};

class schoolnode:public school//schoolnode class school derived
{
	public:
		schoolnode();//schoolnode destructor
		void insert(char name[], int & agemin, int & agemax, int & classnum, int & size, int & max, int & x, int & y);//insert function
		void display();//display function
		schoolnode *& go_next();//traverse next function
		schoolnode *& go_prev();//traverse previous function
		void connect_next(schoolnode * connection);//connect the next node function
		void connect_prev(schoolnode * connection);//connect the previous node function
	protected:
		schoolnode * next;//next pointer
		schoolnode * prev;//previous pointer
};

class schoollist
{
	public:
		schoollist();//schoollist constructor
		~schoollist();//schoollist destructor
		void build();//build function
		void display();//display function
		void display_all();//display all function
		void delete_all();//display all function
	protected:
		void display(schoolnode * head);//display recursive function
		void display_all(schoolnode * head);//display all recursive function
		void delete_all(schoolnode *& head);//display all recursive function
		schoolnode * head;
		schoolnode * tail;
};
