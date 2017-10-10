// Madeleine Kobus

#include <iostream>
#include <string>

using namespace std;

void delayFunction(int);

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
		delayFunction(SIZE);
		
		//WELCOME to you table
		//*******************************************************************
		cout << serversArray[count] << ": Welcome to your seats, here are some menus. " << endl;
		done = false;
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
				cout << serversArray[count] << ": Please say 'order' when you are ready to order drinks." << endl;
				cin >> choice;
				if (choice == "order")
				{
					//ORDER DRINKS FOR EACH PERSON IN THE PARTY
					done = true;
				}
				else
				{
					cout << serversArray[count] << ": I'm sorry? What was that? " << endl;
					done = false;
				}
				
				
			}
			else
			{
				cout << serversArray[count] << "I'm sorry? What was that? " << endl;
				done = false;
 			}
		}
		cout << "****************************************************************" << endl;
		cout << endl;
		cout << "I'll be right back with your drinks! " << endl;
		cout << endl;
		cout << "*****************************************************************" << endl;
		
		//ORDER FOOD
		cout << serversArray[count] << ": Here are you drinks. " << endl;
		done = false;
		while (done == false)
		{
			cout << serversArray[count] << ": Ok! Are you ready to order? " << endl;
			cin >> choice;
			if (choice == "yes")
			{
				cout << serversArray[count] << ":  What can I get you? " << endl;
				//ORDER FOOD FOR EACH PERSON IN THE PARTY
				done = true;
			}
			else if (choice == "no")
			{
				cout << serversArray[count] << ": Ok, I'll give you a moment to think. " << endl;
				cout << serversArray[count] << ": Please say 'order' when you are ready to order your food." << endl;
				cin >> choice;
				if (choice == "order")
				{
					//ORDER FOOD FOR EACH PERSON IN THE PARTY
					done = true;
				}
				else
				{
					cout << serversArray[count] << ": I'm sorry? What was that? " << endl;
					done = false;
				}
				
				
			}
			else
			{
				cout << serversArray[count] << "I'm sorry? What was that? " << endl;
				done = false;
 			}
 		}
 		cout << serversArray[count] << ": Ok, I'll put your oder in. " << endl;
 		cout << endl;
 		cout << "********************************************************************" << endl;
 		cout << endl;
 		
 		cout << "Here we go guys! ....REPEATS ORDER TO CUSTOMERS???" << endl;
 		
 		cout << endl;
 		cout << "*********************************************************************" << endl;
 		cout << endl;
 		
 		cout << serversArray[count] << ": Looks like you all are finished eating. " << endl;
		done = false;
		while (done == false)
		{
			cout << serversArray[count] << ": Did we save room for dessert? " << endl;
			cin >> choice;
			if (choice == "yes")
			{
				cout << serversArray[count] << ":  What can I get you? " << endl;
				//ORDER DESSERT FOR EACH PERSON IN THE PARTY
				done = true;
			}
			else if (choice == "no")
			{
				cout << serversArray[count] << ": Alright, I'll be back with your check. " << endl;
				done = true;
			}
			else
			{
				cout << serversArray[count] << "I'm sorry? What was that? " << endl;
				done = false;
 			}
 		}
 		
 		cout << endl;
 		cout << "******************************************************************************" << endl;
 		cout << endl;
 		
 		cout << serversArray[count] << ": Here is the bill. " << endl;
		// BILL FUNCTION
			
		count++;
	} //While SIZE
	
	return 0;
}

//**************************************************************************
// Represents passing of time. 
//**************************************************************************
void delayFunction(int size)
{
	for (int i = 0; i <= size; i++)
	{
		cout << "********************************************************" << endl;
	}
}
