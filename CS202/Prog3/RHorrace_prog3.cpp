#include "RHorrace_prog3.h"

//Horrace, Robert CS202

/*
   This program is designed for the main function.
   This function will utilize a menu, so they can 
   only use one app at a time.
   This is just the basis of phone apps.
 */

int main()
{
	texts my_texts;//texts object
	char response;//either Y or N
	int answer = 0;//for menu
	my_texts.build();//builds from a text file
	cout << endl << "Welcome User." << endl;
	do{
		do{
			cout << "Which app do you want to use(1:texts, 2:maze,3:calculator(enter the number)): ";
			cin >> answer;
			cin.ignore(SIZE,'\n');
			switch(answer)
			{
				case 1://if user wants to deal with text messages
					txt(my_texts);
					break;
				case 2://if user wants to play the maze game
					mz();
					break;
				case 3://if user wants to use the calculator
					calc();
					break;
				default:
					cout << "Error. Not an option." << endl;
			}
		}while(answer != 1 && answer != 2 && answer != 3);//repeats if none of the apps were chosen.
		do{
			cout << "Use another App?(Y/N): ";
			cin >> response;
			cin.ignore(SIZE,'\n');
			response = toupper(response);
		}while(response != 'N' && response != 'Y');//repeats if not Y or N
	}while(response == 'Y');//repeats if user says yes.
	cout << "Farewell." << endl;
	return 0;
}
