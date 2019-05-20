#include "RHorrace_prog3.h"

//Horrace, Robert CS202

/*
	This program is designed to hold the 
	implementations of the mfunctions used 
	for the maze.
	All of these functions will be used.
	Operator overloading wasn't needed and
	too many problems took place.
*/

node::node():point(NULL),num(0),left(NULL),right(NULL){}//default constructor

node::node(const char pnt[],int & nm):num(nm),left(NULL),right(NULL)//initialization constructor
{
	point = new char[strlen(pnt)+1];
	strcpy(point,pnt);
}

node::~node()//destructor
{
	if(point)
	{
		delete [] point;
		point = NULL;
	}
	if(num != 0) num = 0;
}

node *& node::go_left()//go left function
{
	return left;
}

node *& node::go_right()//go right function
{
	return right;
}

void node::connect_left(node * connect)//connect the left function
{
	left = connect;
}

void node::connect_right(node * connect)//connect the right function
{
	right = connect;
}

int node::compare(int & nm)//compare function
{
	if(num == nm) return 0;//if a match
	else if(nm < num) return -1;//if less than
	else if(nm > num) return 1;//if greater than
}

int node::compare_pnt(const char pos[])//compare the point function
{
	if(strcmp(point,pos) == 0) return 1;//if a match
	return 0;
}

int node::initiate(const char pnt[])//initiate function
{
		if(point) delete [] point;
		point = new char[strlen(pnt) + 1];
		strcpy(point,pnt);
		return 1;
}

void node::display()//display function for checking if the tree is balanced
{
	cout << num << endl;
}

maze::maze():root(NULL),position(NULL){}//maze constructor

maze::~maze()//destructor
{
	delete_all(root);//calls delete all function
}

void maze::build(int & lvl)//build function
{
	const char pnt[SIZE] = "Checkpoint";//for the other nodes that aren't start or finish
	int a = lvl + 1;//sets the variable for height of the tree
	for(int i = 1;i < pow(2,a);++i)//for inserting the numbers for building the tree
	{
		if(insert(root,pnt,i) == 1){}//calls insert function
		//there will always be 1 less than 2^height
	}
	root -> display();//check if root, if balanced, root will always be 2^difficulty level
	initiate_start();//initiates start, start will always be root
	while(initiate_end(a) == -2){}//calls initiate end function, will always be a leaf
}

int maze::initiate_start()//initiate start function
{
	const char start[SIZE] = "Start";
	if(!root) return 0;
	root -> initiate(start);//initiates root
	position = root;//makes position equal to root, position will move.
	return 1;
	
}

int maze::initiate_end(int & hgt)//initiate end function
{
	int a = 0;
	int lvl = pow(2,hgt);//sets the highest number possible for the tree
	const char pnt[SIZE] = "Finish";
	//random number generator
	srand(time(NULL));
	a = rand()%lvl + 1;//between 1 and 2^height
	if(a%2 == 0) a -= 1;//if even, make odd
	return initiate_end(root,a,pnt);//calls recursive function
	
}

int maze::initiate_end(node *& root,int & nm, const char pnt[])//initiate end recursive function
{
	if(!root) return -2;//if NULL
	if(root -> compare(nm) == 0)//number matches
	{
		root -> initiate(pnt);//initiates end
		return 1;
	}
	if(root -> compare(nm) == 1) return initiate_end(root -> go_right(),nm,pnt);//goes to the right
	if(root -> compare(nm) == -1) return initiate_end(root -> go_left(),nm,pnt);//goes to the left
	return 0;
}

int maze::move_player(const char choice[])//move player function
{
	const char pos[SIZE] = "Finish";
	if(!root) return -1;//if tree doesn't exist
	if(strcmp(choice,"Right") == 0) position = position -> go_right();//go to the right if right
	else if(strcmp(choice,"Left") == 0) position = position -> go_left();//go to the left if left
	if(position -> compare_pnt(pos) == 1 && !position -> go_left() && !position -> go_right()) return 1;//if a match and th end
	else if(position -> compare_pnt(pos) == 0 && !position -> go_left() && !position -> go_right())//if no match and the end
	{
	position = root;//sets position back at the beginning
	return 2;
	}
	return 0;
} 

int maze::insert(node *& root,const char pnt[],int & nm)//insert function
{
	if(!root)//if NULL
	{
		root = new node(pnt,nm);//make new node
		return 1;
	}
	else
	{
		if(insert(root -> go_right(),pnt,nm) == 1)//if inserting to the right was successful
		//it will always insert to the right
		{
			if(height(root -> go_right()) - height(root -> go_left()) == 2)//if no longer balanced
			{
				return rotate_to_left_once(root);//rotates tree til balanced
			}
			return 1;
		}
		return 0;
	}
	return 0;
}

int maze::height(node * root)//height function
{
	int left,right = 0;
	if(!root) return 0;//if NULL
	left = height(root -> go_left());//checks height of left
	right = height(root -> go_right());//checks height of right
	if(left > right) return left + 1;//if left is higher
	else return right + 1;//ifright is greater than or equal to left
}

int maze::rotate_to_left_once(node *& root)//rotate to the left function
{
	if(!root) return 0;//if NULL
	node * temp = NULL;
	temp = root -> go_right();
	root -> connect_right(temp -> go_left());
	temp ->connect_left(root);
	root = temp;
	return 1;
}

int maze::rotate_to_left_twice(node *& root)//rotate to the left twice function
{
	if(!root) return 0;//if NULL
	rotate_to_right_once(root -> go_right());//rotates two nodes
	rotate_to_left_once(root);//rotates a second time
}

int maze::rotate_to_right_once(node *& root)//rotate to the right function
{
	if(!root) return 0;//if NULL;
	node * temp = NULL;
	temp = root -> go_left();
	root -> connect_left(temp -> go_right());
	temp -> connect_right(root);
	root = temp;
	return 1;
}

int maze::rotate_to_right_twice(node *& root)//rotate to the right twice function
{
	if(!root) return 0;//if NULL
	rotate_to_left_once(root -> go_left());//rotates two nodes
	rotate_to_right_once(root);//rotates a second time
}

int maze::display_all(node * root)//display all function
{
	//this function was for checking the nodes 
	//if they were inserted correctly
	if(!root) return 0;//if NULL
	if(display_all(root -> go_left())){}//displays the left side
	root -> display();//displays root
	if(display_all(root -> go_right())){}//displays the right side
	return 1;
}

int maze::delete_all()//delete all wrapper function
{
	position = NULL;//sets position to NULL;
	return delete_all(root);//calls recursive function
}

int maze::delete_all(node *& root)//delete all recursive function
{
	if(!root) return 0;//if NULL
	delete_all(root -> go_left());//deletes the left
	delete_all(root -> go_right());//deletes the right
	delete root;
	root = NULL;
	return 1;
}
