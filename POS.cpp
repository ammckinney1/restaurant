/*
 * Tina Appleton
 */
//Point of Sale interface
//used to order 

#include "dataLoader.h"
#include "foodItem.h"
#include "restaurantClass.h"
#include "orderItem.h"
#include <iostream>
using namespace std;
#define DEBUG

int addOrSelect();
void editOrder(orderItem &order);
void freeObjData(vector<foodItem>& items);

int main() {
	string parseHelper;
	vector<foodItem> items;
	Restaurant restData;
	bool loaded = LoadData(restData, items, "foodData.txt", "restaurantData.txt");
	if(!loaded) {
		//error in the loading process, report it and then exit
		cout << "Could not load Data files, exiting..." << endl;
		return 0;
	}
	vector<string> itemTypes;
	
	for(int i = 0; i < items.size(); i++) {
		bool shouldAdd = true;
		for(int b = 0; b < itemTypes.size(); b++) {
			if(itemTypes[b] == items[i].getType()) {
				shouldAdd = false;
			}
		}
		if(shouldAdd) {
			itemTypes.push_back(items[i].getType());
		}
	}
	
	orderItem order;
	bool nextOrder = true;
	
	
	while(nextOrder) {
		//do order stuff
		bool continueOrder = true;
		
		while(continueOrder) {
			int selector = addOrSelect();
			if(selector == 3) {
				break;
			} else if (selector == 2) {
				editOrder(order);
			} else if (selector == 1) {
				//choose a category
				cout << "Select a category of items" << endl;
				for(int cat = 0; cat < itemTypes.size(); cat++) {
					cout << (cat+1) << ". " << itemTypes[cat] << endl;
				}
				int catSelect = 0;
				while(catSelect < 1 || catSelect > itemTypes.size()) {
					getline(cin, parseHelper);
					catSelect = stoi(parseHelper);
				
					if(catSelect < 1 || catSelect > itemTypes.size()) {
							cout << "Bad selection, please try again." << endl;
					}
				}
				catSelect--;
			
				//category is selected, now choose an item
				cout << "Select an item to add to the order" << endl;
				vector<foodItem> catItems;
				int itemCounter = 1;
				for(int it = 0; it < items.size(); it++) {
					if(items[it].getType() == itemTypes[catSelect]) {
						cout << itemCounter << ". " << items[it].getName() << ": " << items[it].getPrice() << endl;
						catItems.push_back(items[it]);
						itemCounter++;
					}
				}
				int itemSelect = 0;
				while(itemSelect < 1 || itemSelect > itemCounter) {
					getline(cin, parseHelper);
					itemSelect = stoi(parseHelper);
					if(itemSelect < 1 || itemSelect > itemCounter) {
						cout << "Bad selection, please try again." << endl;
					}
				}
				
				
				//item is selected, determine if they want to make any changes to the item
				foodItem item = catItems[itemSelect - 1].copy();
				string itemNotes;
				cout << "If you would like to make any changes to the base item, please enter below. if not, type 'n/a' or 'none'." << endl;
				getline(cin, itemNotes);
				item.setnotes(itemNotes);
				
				order.addFoodItem(item);
			}
			
			bool isCompleteWorking = true;
			while(isCompleteWorking) {
				cout << "Is this order complete? (yes/no)" << endl;
				char sel;
				string sels;
				getline(cin, sels);
				sel = sels.c_str()[0];
				if(sel == 'y' || sel == 'Y') {
					continueOrder = false;
					isCompleteWorking = false;
				} else if (sel == 'n' || sel == 'N') {
					isCompleteWorking = false;
				} else {
					cout << "Bad input. Either input 'yes' (or 'y') or 'no' (or 'n')." << endl;
				}
			}
		}
		order.printTicket();
		
		//order is finished, ask if the POS should do another order
		bool testEnd = true;
		while(testEnd) {
			cout << "Do you wish to make another order? (y/n)" << endl;
			char c;
			string sels;
			getline(cin, sels);
			c = sels.c_str()[0];
			if(c == 'Y' || c == 'y') {
				testEnd = false;
			} else if (c == 'N' || c == 'n') {
				testEnd = false;
				nextOrder = false;
			} else {
				cout << "Bad entry, must choose y (or yes) to make another order, or n (or no) to not do so." << endl;
			}
		}
	}
	
	//currently this function gives a segmentation fault
	//might be an issue with how the function works
	//will have to test more
	//freeObjData(items);
	
	return 0;
}

int addOrSelect() {
	string parseHelper;
	int retval = 0;
	while(retval < 1 || retval > 3) {
		cout << "Do you wish to add a new item to the order, or edit an existing item?" << endl;
		cout << "1. Add a new item" << endl;
		cout << "2. Edit existing item" << endl;
		cout << "3. exit POS" << endl;
	
		getline(cin, parseHelper);
		retval = stoi(parseHelper);
		if(retval < 1 || retval > 3) {
			cout << "Bad input! Value must be a number between 1 and 3." << endl;
		}
	}
	
	return retval;
}

void editOrder(orderItem &order) {
	
	cout << "Which item would you like to edit?" << endl;
	int count;
	for(count = 0; count < order.getNumOfItems(); count++) {
		foodItem item = order.getFoodItemAt(count);
		cout << count+1 << ". " << item.getName() << ", " << item.getnotes() << endl;
	}
	int choice = -1;
	string choiceStr;
	do {
		getline(cin, choiceStr);
		choice = stoi(choiceStr);
		if(choice > order.getNumOfItems() || choice < 1) {
			choice = -1;
			cout << "Bad input! The input must be the number matching one of the items on the list." << endl;
			cout << "Please enter a new input." << endl;
		}
	} while (choice < 1);
	
	foodItem choiceItem = order.getFoodItemAt(choice-1); //remember, choice is the number on the list, which is 1 higher than the index of that item
	
	//have a selection of the item to edit, now make a selection of how to edit
	cout << "How would you like to edit this item?" << endl;
	cout << "1. edit the item notes." << endl;
	cout << "2. delete the item." << endl;
	cout << "3. do nothing." << endl;
	int choice2 = -1;
	do {
		getline(cin, choiceStr);
		choice2 = stoi(choiceStr);
		if(choice2 > 3 || choice2 < 1) {
			choice = -1;
			cout << "Bad input! The input must be a number between 1 and 3, matching your choice on the list of items." << endl;
			cout << "Please try again.";
		}
	} while(choice2 < 1);
	
	//now that we know what we want to do with it, lets do stuff
	if(choice2 == 1) {
		cout << "Please input the new changes you'd like made to this item." << endl;
		string entry;
		getline (cin, entry);
		choiceItem.setnotes(entry);
		order.setFoodItemAt(choice-1, choiceItem);
	} else if (choice2 == 2) {
		order.removeFoodItemAt(choice-1);
	}
	//we don't actually need an if statement for 3, since the function will just return now.
}

//function to delete all the dynamically allocated objects
void freeObjData(vector<foodItem> &items) {
	for(int count = 0; count < items.size(); count++) {
		delete &items[count];
	}
}
