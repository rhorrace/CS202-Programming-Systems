#include "RHorrace_prog3.h"

//Horrace, Robert CS202

/*
	This program is designed to hold other functions.
	These functions will call the functions within
	each class.
	These functions will be needed in order for the
	whole program to work.
*/

void txt(texts & my_txts)//texts function
{
	char response;
	char nm[SIZE];//for name of person
	char msg[TEXT];//for text message
	char dt[SIZE];//for date sent
	do{
		do{
			cout << "Enter a message?(Y/N): ";
			cin >> response;
			cin.ignore(100,'\n');
			response = toupper(response);
		}while(response != 'Y' && response != 'N');//If not Y or N
		if(response == 'Y')//If yes
		{
			do{
				cout << "Enter the person you want to message: ";
				cin.get(nm,SIZE,'\n');
				cin.ignore(SIZE,'\n');
				cout << "Enter your message: ";
				cin.get(msg,TEXT,'\n');
				cin.ignore(TEXT,'\n');
				cout << "Enter today's date(month/day/year): ";
				cin.get(dt,SIZE,'\n');
				cin.ignore(SIZE,'\n');
				my_txts.insert(nm,msg,dt);//inserts the data
				my_txts.save(nm,msg,dt);//saves to the text file
				do{
					cout << "Enter another message?(Y/N): ";
					cin >> response;
					cin.ignore(100,'\n');
					response = toupper(response);
				}while(response != 'N' && response != 'Y');//if not Y and N
			}while(response == 'Y');//repeats if user says yes
		}
		do{
			do{
				cout << "Display messages sent to a specific person?(Y/N): ";
				cin >> response;
				cin.ignore(100,'\n');
				response = toupper(response);
			}while(response != 'Y' && response != 'N');//if not yes and no
			if(response == 'Y')//if yes
			{
				cout << "Enter name: ";
				cin.get(nm,SIZE,'\n');
				cin.ignore(SIZE,'\n');
				if(my_txts.display(nm) == 0)//if no one in the texts exist
					cout << "No messages were sent to that person." << endl;

				do{
					cout << " Again?(Y/N): ";
					cin >> response;
					cin.ignore(100,'\n');
					response = toupper(response);
				}while(response != 'Y' && response != 'N');//if response isn't Y and N
			}
		}while(response == 'Y');//repeats if yes
		do{
			cout << "Display All sent messages?(Y/N): ";
			cin >> response;
			cin.ignore(100,'\n');
			response = toupper(response);
		}while(response != 'Y' && response != 'N');//if response isn't Y or N
		if(response == 'Y')//if yes
			my_txts.display_all();//displays all
		do{
			cout << "Repeat?(Y/N): ";
			cin >> response;
			cin.ignore(100,'\n');
			response = toupper(response);
		}while(response != 'Y' && response != 'N');//repeats if not Y and N
	}while(response == 'Y');//repeats if yes
}
void mz()//maze function
{
	char direction[SIZE];
	char response;
	maze my_maze;
	int lvl = 0;
	int a = 0;
	do{
		do{
			cout << "Enter difficulty level(maximum level = 5): ";
			cin >> lvl;
			cin.ignore(100,'\n');
		}while(lvl <= 0 || lvl > 5);//repeats if the requirement isn't met
		my_maze.build(lvl);//builds maze depending on th level
		do{
			do{
				cout << "Left or Right: ";//only two directions to take
				cin.get(direction,SIZE,'\n');
				cin.ignore(SIZE,'\n');
				direction[0] = toupper(direction[0]);
			}while(strcmp(direction,"Left") != 0 && strcmp(direction,"Right") != 0);//if not left and right
			a = my_maze.move_player(direction);
			if(a == -1) cout << endl << "Maze doesn't Exist." << endl;//if the maze didn't build
			else if(a == 2)//if a dead end was reached
			{
				cout << endl << "Sorry, you reached a Dead End. You have to start over." << endl;
			}
			else if(a == 1) cout << endl << "CONGRATULATIONS." << endl;//If the finish was found
		}while(a == 0 || a == 2);//If dead end was reached
		do{
			cout << "Play Again?(Y/N): ";
			cin >> response;
			cin.ignore(SIZE,'\n');
			response = toupper(response);
		}while(response != 'Y' && response != 'N');//repeat if not Y and N
		if(response == 'Y') my_maze.delete_all();//deletes the maze if yes
	}while(response == 'Y');//repeats if yes
}
void calc()//calculator function
{
	calculator obj1;//first calculator object
	calculator obj2;//second calculator object
	char response;
	char op;
	do{
		cout << "Enter first number: ";
		cin >> obj1;// >> op call
		cin.ignore(100,'\n');
		cout << "Enter second number: ";
		cin >> obj2;// >> op call
		cout << " + , - , *, or /?: ";
		do{
			cin >> op;
			cin.ignore(100,'\n');
			switch(op)
			{
				case '+'://if add is chosen
					obj1 += obj2;// += op call
					cout << endl << obj1 << endl;// << op call
					break;
				case '-'://if minus is chosen
					obj1 -= obj2;// -= op call
					cout << endl << obj1 << endl;// << op call
					break;
				case '*'://if multiply is chosen
					obj1 *= obj2;// *= op call
					cout << endl << obj1 << endl;// << op call
					break;
				case '/'://if divide is chosen
					obj1 /= obj2;// /= op call
					cout << endl << obj1 << endl;// << op call
					break;
				default:
					cout << "Error, not recognized." << endl;
			}	
		}while(op != '+' && op != '-'&& op != '*' && op != '/');//repeats if the operators weren't chosen
		do{
			cout << "Again?(Y/N): ";
			cin >> response;
			cin.ignore(100,'\n');
			response = toupper(response);
		}while(response != 'N' && response != 'Y');//repeats if not Y and N
	}while(response == 'Y');//repeats if Y
}

