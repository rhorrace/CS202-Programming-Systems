#include "RHorrace_school.h"

location::location()//location constructor
{
	gpsx = 0;
	gpsy = 0;	
}

location::~location()//location destructor
{
	gpsx = 0;
	gpsy = 0;
}

void location::insert(int & x, int & y)//location insert function
{
	gpsx = x;
	gpsy = y;
}

void location::display()//location display function
{
	cout << "coordinate: " << gpsx << "," << gpsy << endl;
}

school::school()//school constructo
{
	name = NULL;
	agemin = 0;
	agemax = 0;
	classnum = 0;
	bestsize = 0;
	max = 0;
}

void school::insert(char nm[], int & min, int & max, int & clssnm, int & sz, int & mx, int & x, int & y)//school insert function
{
	name = new char[strlen(nm)+ 1];
	strcpy(name,nm);
	agemin = min;
	agemax = max;
	classnum = clssnm;
	bestsize = sz;
	max = mx;
	location::insert(x,y);//call location's insert
}
void school::display()//school display function
{
	cout << "School: " << name << endl;
	cout << "Age range: " << agemin << "-" << agemax << endl;
	cout << "Classes per grade: " << classnum << endl;
	cout << "Best class size: " << bestsize << endl;
	cout << "Maximum number of students: " << max << endl;
	location::display();//call location's display
}
schoolnode::schoolnode()//schoolnode constructor
{
	next = NULL;
	prev = NULL;
}

void schoolnode::insert(char name[], int & agemin, int & agemax, int & classnum, int  & size, int & max, int & x, int & y)//schoolnode insert function
{
	school::insert(name,agemin, agemax,classnum,size,max,x,y);//call school's insert function
}

void schoolnode::display()//schoolnode's display function
{
	school::display();//call school's display function
}

schoolnode *& schoolnode::go_next()//schoolnode go next function
{
	return next;//returns next node
}

schoolnode *& schoolnode::go_prev()//schoolnode go previous function
{
	return prev;//returns previous node
}

void schoolnode::connect_next(schoolnode * connection)//schoolnode connext next node function
{
	next = connection;//connection is connected
}
void schoolnode::connect_prev(schoolnode * connection)//schoolnode connect previous function
{
	prev = connection;//connection is connected
}

schoollist::schoollist()//schoollist constructor
{
	head = NULL;
	tail = NULL;
}

schoollist::~schoollist()//schoollist destructor
{
	delete_all();//calls delete all function
}

void schoollist::build()//schoollist build function
{
	char pk = 'n';
	ifstream fin;
	char name[SIZE];
	int agemin;
	int agemax;
	int classnum;
	int size;
	int max;
	int x;
	int y;
	int err;
	schoolnode * temp = NULL;
	fin.open("schools.txt");//open file
	if(fin.is_open())
	{
		fin.get(name,SIZE,':');
		while(!fin.eof())
		{
			//read in from file
			fin.ignore(SIZE,':');
			fin >> agemin;
			fin.ignore(SIZE,':');
			fin >> agemax;
			fin.ignore(SIZE,':');
			fin >> classnum;
			fin.ignore(SIZE,':');
			fin >> size;
			fin.ignore(SIZE,':');
			fin >> max;
			fin.ignore(SIZE,':');
			fin >> x;
			fin.ignore(SIZE,':');
			fin >> y;
			char pk = fin.peek();
			fin.ignore(SIZE,'\n');
			//insert data into a node in the DLL
			if(head == NULL)
			{
				head = new schoolnode;
				head -> insert(name, agemin, agemax, classnum, size, max, x, y);
				tail = head;
			}
			else
			{
				temp = new schoolnode;
				temp -> insert(name, agemin, agemax, classnum, size, max, x, y);
				temp -> connect_next(head);
				head -> connect_prev(temp);
				head = temp;
			}
			fin.get(name,SIZE,':');
		}
		fin.close();//file closed
	}
}

void schoollist::display_all()//schoollist display all wrapper function
{
	display_all(head);//recursive function call
}

void schoollist::display_all(schoolnode * head)//schoollist display all recursive function
{
	if(!head) return;//if NULL
	head -> display();//calls display function
	display_all(head -> go_next());//recursively traverse to next node
}

void schoollist::delete_all()//schoollist delete_all wrapper function
{
	delete_all(head);//recursive function call
}

void schoollist::delete_all(schoolnode *& head)//schoollist delete all recursive function
{
	if(!head) return;//if NULL
	if(head -> go_next()) delete_all(head -> go_next());//if next exists
	delete head;
	head = NULL;
}
