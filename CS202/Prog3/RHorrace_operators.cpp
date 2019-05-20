#include "RHorrace_operators.h"

calculator::calculator():val(0){}

calculator::calculator(float vl):val(vl){}

calculator::calculator(const calculator & calc):val(calc.val){}

calculator::~calculator()
{
	val = 0;
}

calculator calculator::operator + (const calculator & calc) const
{
	calculator temp;
	temp.val = val + calc.val;
	return temp;
}

calculator calculator::operator += (const calculator & calc)
{
	val += calc.val;
	return *this;
}

calculator calculator::operator - (const calculator & calc) const
{
	calculator temp;
	temp.val = val - calc.val;
	return temp;
}

calculator calculator::operator -= (const calculator & calc)
{
	val -= calc.val;
	return *this;
}

calculator calculator::operator * (const calculator & calc) const
{
	calculator temp;
	temp.val = val * calc.val;
	return temp;
}

calculator calculator::operator *= (const calculator & calc)
{
	val *= calc.val;
	return *this;
}

calculator calculator::operator / (const calculator & calc) const
{
	calculator temp;
	temp.val = val / calc.val;
	return temp;
}

calculator calculator::operator /= (const calculator & calc)
{
	val /= calc.val;
	return *this;
}

istream & operator >> (istream & in, calculator & calc)// >> op overload
{
	in >> calc.val;
	return in;
}

ostream & operator << (ostream & out, const calculator & calc)
{
	out << calc.val;
	return out;
}
