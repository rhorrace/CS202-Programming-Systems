#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

//Horrace, Robert CS202

/*
   This program is the primary
   .h file.
   This .h file has the location
   class, which is the indirect
   base class.
   The base of the hierarchy will
   have its functions called.
 */
const int SIZE = 100;

class location
{
	public:
		location();//constructor
		~location();//destructor
		void insert(int & x, int & y);//inset function
		void display();//display function
	protected:
		int gpsx;//x-coordinate
		int gpsy;//y-corrdinate
};

