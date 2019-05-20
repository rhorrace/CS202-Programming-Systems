#include "RHorrace_prog3.h"

//Horrace, Robert CS202

/*
	This program is designed to hold the
	implementations of the functions used
	for the texts.
	Most functions will be used and some
	will be check/test functions.
	The messages will be written to and
	read from a text file.
*/

text::text():name(NULL){}//default constructor

text::text(char nm[])//initialization constructor
{
	name = new char[strlen(nm)+1];
	strcpy(name,nm);
}

text::~text()//destructor
{
	if(name)
	{
		delete [] name;
		name = NULL;
	}
}
int text::compare(char nm[])//compare function
{
	if(strcmp(name,nm) == 0) return 1;// if a match
	return 0;
}

void text::display()//display function
{
	cout << "Sent to: " << name << endl;
}

message::message():txt(NULL),date(NULL),text(NULL){}//message default constructor

message::message(char nm[], char msg[], char dt[]):text(nm)//initialization constructor
{
	txt = new char[strlen(msg)+1];
	strcpy(txt,msg);
	date = new char[strlen(dt)+1];
	strcpy(date,dt);
}

message::~message()//destructor
{
	if(txt)
	{
		delete [] txt;
		txt = NULL;
	}
	if(date)
	{
		delete [] date;
		date = NULL;
	}
}

int message::compare(char nm[])//compare function
{
	return text::compare(nm);//calls text's compare function
}

void message::display()//display function
{
	text::display();
	cout << "Message: " << txt << endl;
	cout << "Date received: " << date << endl;
}

textnode::textnode():next(NULL){}//textnode default constructor

textnode::textnode(char nm[], char msg[], char dt[]):next(NULL),message(nm,msg,dt){}//initialization constructor

textnode::~textnode(){}//destructor

textnode *& textnode::go_next()//go next function
{
	return next;
}

void textnode::connect_next(textnode * connect)//connect next function
{
	next = connect;
}

int textnode::compare(char nm[])//compare function
{
	return message::compare(nm);//calls message's comapare function
}

void textnode::display()//display function
{
	message::display();//calls message's display function
}

texts::texts()//default constructor
{
	head = new textnode *[HSH];
	for(int i = 0;i < HSH;++i)
	{
		*(head + i) = NULL;
	}	
}
texts::~texts()//destructor
{
	delete_all();//delete all wrapper function
}

void texts::build()//build function
{
	char nm[SIZE];
	char msg[TEXT];
	char dt[SIZE];
	ifstream fin;
	fin.open("RHorrace_texts.txt");//opens text file
	if(fin.is_open())
	{
		fin.get(nm,SIZE,':');
		while(!fin.eof())//while not end of file
		{
			fin.ignore(SIZE,':');
			fin.get(msg,TEXT,':');
			fin.ignore(TEXT,':');
			fin.get(dt,SIZE,'\n');
			fin.ignore(SIZE,'\n');
			insert(nm,msg,dt);//inserts into hashtable(array of LLL)
			fin.get(nm,SIZE,':');
		}
		fin.close();//closes file
	}
}

int texts::hash(char nm[])//hash function
{
	int a = 0;
	if(!nm) return -1;
	for(int i = 0;i<strlen(nm);++i)
	{
		a += nm[i];
	}
	return a%HSH;//returns 0 - 9
}

int texts::insert(char nm[], char msg[], char dt[])//insert wrapper function
{
	if(!head) return 0;//if NULL
	int a = hash(nm);//calls hash function
	if(a >= 0) return insert(*(head + a),nm,msg,dt);//calls recursive function
	return 0;
}

int texts::insert(textnode *& head, char nm[], char msg[], char dt[])//insert recursive function
{
	if(!head)//if NULL
	{
		head = new textnode(nm,msg,dt);//makes new node
		return 1;
	}
	return insert(head -> go_next(),nm,msg,dt);//traverses to next node
}

int texts::save(char nm[], char msg[], char dt[])//save function
{
	ofstream fout;
	fout.open("RHorrace_texts.txt",ios::app);//opens and appends text file
	if(fout.is_open())
	{
		fout << nm << ":" << msg << ":" << dt << endl;
		fout.close();
		return 1;
	}
	return 0;
}

int texts::display(char nm[])//display wrapper function
{
	if(!head) return 0;
	int a = hash(nm);//calls hash function
	return display_list(*(head + a),nm);//calls recursive function
}

int texts::display_list(textnode * head, char nm[])//display list recursive function
{
	if(!head) return 0;//if NULL
	if(!head -> go_next())
	{
		if(head -> compare(nm) == 1)//if match and one node or end of list
		{
			head -> display();//display
			return 1;
		}
		return 0;
	}
	if(head -> compare(nm) == 1) head -> display();//if a match
	return display_list(head -> go_next(),nm);//goes to next node
}

int texts::display_all()//display all wrapper function
{
	if(!head) return 0;//if NULL
	for(int i=0;i<HSH;++i)
	{
		if(display_all(*(head + i))){}//calls recrsive function
	}
}

int texts::display_all(textnode * head)//display all recursive function
{
	if(!head) return 0;//if NULL
	if(!head -> go_next())//if one node or end of list
	{
		head -> display();
		return 1;
	}
	head -> display();//displays node
	return display_all(head -> go_next());//travers to next node
}

int texts::delete_all()//delete all wrapper function
{
	if(!head) return 0;//if NULL
	for(int i=0;i<HSH;++i)
	{
		if(delete_all(*(head + i))){}//calls recursive function
	}
	delete [] head;//deletes array of LLL
	head = NULL;
	return 1;
}

int texts::delete_all(textnode *& head)//delete all recursive function
{
	textnode * temp = NULL;
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
		return delete_all(head);//delete the new head
}
