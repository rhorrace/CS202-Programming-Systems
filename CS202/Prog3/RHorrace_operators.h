#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Horrace, Robert

/*
   This .h file is designed for operators.
   The operators that are going to be used
   in this program will be overload.
   More than half the operators in this file
   will be used.
 */

class calculator//class for a calculator
{
	public:
		calculator();//default constructor
		calculator(float vl);//initializing constructor
		calculator(const calculator & calc);//copy constructor
		~calculator();//destructor
		calculator operator + (const calculator &) const;// + op overload
		calculator operator += (const calculator &);//+= op overload
		calculator operator - (const calculator &) const;// - op overload
		calculator operator -= (const calculator &);//-= op overload
		calculator operator * (const calculator &) const;// * op overload
		calculator operator *= (const calculator &);//*= op overload
		calculator operator / (const calculator &) const;// / op overload
		calculator operator /= (const calculator &);// /= op overload
		friend istream & operator >> (istream &, calculator &);// >> op overload
		friend ostream & operator << (ostream &, const calculator &);// << op overload
	private:
		float val;//number value
};
