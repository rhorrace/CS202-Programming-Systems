#include "RHorrace_prog2.h"

void display_menu(menu & a_menu);//display menu function
void order(stock & a_stock);//order function
void display_ing(stock & a_stock);//display ingredients function
void display_by_ing(stock & a_stock);//display items that use the ingredient function
int main()
{
	stock my_stock;//stock object
	menu my_menu;//menu object
	char response;
	my_stock.build_tree();//build tree function
	my_stock.build_lists();//build lisr function
	my_menu.build();//build menu function
	do{
		display_menu(my_menu);//call display menu
		display_ing(my_stock);
//		order(my_stock);
		display_ing(my_stock);
		display_by_ing(my_stock);
		do{
			cout << "End the program?(Y/N): ";
			cin >> response;
			cin.ignore(SIZE,'\n');
			response = toupper(response);
		}while(response != 'Y' && response != 'N');
	}while(response == 'N');
	cout << "Farewell" << endl;
	return 0;
}

void display_menu(menu & a_menu)//display menu function
{
	cout << "This is the menu." << endl;
	a_menu.display_all();//display all function
}

void order(stock & a_stock)//order function
{
	char fd[SIZE];
	int amnt;
	char response;
	do{
		cout << "Enter an order?(Y/N): ";
		cin >> response;
		cin.ignore(SIZE,'\n');
		response = toupper(response);
	}while(response != 'Y' && response != 'N');
	if(response == 'Y')
	{
		while(response == 'Y')
		{

			do{
				cout << "What is the order?: ";
				cin.get(fd,SIZE,'\n');
				cin.ignore(SIZE,'\n');
			}while(!isalpha(fd[0]));
			cout << "How much of that order?: ";
			cin >> amnt;
			if(a_stock.update(fd,amnt) == 0)//calls update function
			{
				cout << "Error. An ingredient is out of stock or too many of the item in the order. Can't process." << endl;
			}
			else if(a_stock.update(fd,amnt) == 1)
			{
				cout << "Order Processed." << endl;
			}
			do{
				cout << "Enter another order?(Y/N): ";
				cin >> response;
				cin.ignore(SIZE,'\n');
				response = toupper(response);
			}while(response != 'Y' && response != 'N');
		}
	}
}

void display_ing(stock & a_stock)//display ingredients function
{
	char response;
	do{
		cout << "Display ingredients in stock?(Y/N): ";
		cin >> response;
		cin.ignore(SIZE,'\n');
		response = toupper(response);
	}while(response != 'Y' && response != 'N');
	if(response == 'Y') a_stock.display_ing();//calls display ing function

}

void display_by_ing(stock & a_stock)//display items that use the ingredient function
{
	node * temp = NULL;
	char ing[SIZE];
	char response;
	do{
		cout << "These are the ingredients." << endl;
		a_stock.display_ing();//calls display ing function
		do{
			cout << "Which ingredient do you want to see with menu items that use it?: ";
			cin.get(ing,SIZE,'\n');
			cin.ignore(SIZE,'\n');
			ing[0] = toupper(ing[0]);
		}while(!isalpha(ing[0]));
		temp = new node;
		temp = a_stock.retrieve(ing);
		if(!temp) cout << "There are no menu items that use this ingredient." << endl;
		else
		{
			cout << "These are the menu items that use " << ing << "."<< endl;
			temp -> display_items(); 
		}
		do{
			cout << "Another ingredient?(Y/N): ";
			cin >> response;
			cin.ignore(SIZE,'\n');
			response = toupper(response);
		}while(response != 'Y' && response != 'N');
	}while(response == 'Y');
		if(temp)
		{
			temp -> delete_all_items();
			delete temp;
			temp = NULL;
		}

}
