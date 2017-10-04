// Madeleine Kobus

#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int SIZE = 4;
	string serversArray[SIZE] = {"Flo", "Betty", "Alice", "Dave"};
	int count = 0, party, number;
	bool done = false, finish = false;
	string choice;
	
	//ENTER THE RESTAURANT
	while (count < SIZE)
	{
		cout << serversArray[count] << ": Hi! Welcome to Marylou's Diner!" << endl;
		cout << serversArray[count] << ": My name is " << serversArray[count] << " I'll be your server today." << endl;
		cout << serversArray[count] << ": How many will be in your party today? " << endl;
		cin >> party;
		while (finish == false)
		{
			if (party >= 1 && party <= 10)
			{
				if (party > 4)
				{
					cout << serversArray[count] << ": We have a great tabel by the window for you! Please follow me. " << endl;
					finish = true;
				}
				else
				{
					while (done == false)
					{
						cout << serversArray[count] << ": Would you like a table or a booth? " << endl;
						cin >> choice;
						if (choice == "table" || choice == "booth")
						{
							cout << serversArray[count] << ": Great! Please follow me to your " << choice << "." << endl;
							done = true;
						}
						else 
						{
							cout << "INVALID ENTRY" << endl;
						}
						
					
					}
				}//Else party > 4 
				finish = true;
			}// IF party1
			else
			{
				cout << serversArray[count] << ": I'm sorry, we can't seat a party of that size. " << endl;
			}
			finish = true;
		}
		//******************************************************************
		//PAUSE for user input???
		
		//WELCOME to you table
		//*******************************************************************
		cout << serversArray[count] << ": Welcome to your table, here are some menus. " << endl;
		cin >> choice;
		while (done == false)
		{
			cout << serversArray[count] << ": Can I start you off with some drinks?" << endl;
			cin >> choice;
			if (choice == "yes")
			{
				cout << serversArray[count] << ":  What can I get you? " << endl;
				//ORDER DRINKS FOR EACH PERSON IN THE PARTY
				done = true;
			}
			else if (choice == "no")
			{
				cout << serversArray[count] << ": Ok, I'll give you a moment to think. " << endl;
				//PAUSE GAME AND WAIT FOR USER INPUT???
				done = true;
			}
			else
			{
				cout << serversArray[count] << "I'm sorry? what was that? " << endl;
				done = false;
 			}
		}
			
		count++;
	} //While SIZE
	
	return 0;
}
