#include "dataLoader.h"
#include "foodItem.h"
#include "restaurantClass.h"
#include "orderItem.h"
#include <iostream>
using namespace std;
#define DEBUG

int addOrSelect();

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
				break;
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
	
	return 0;
}

int addOrSelect() {
	string parseHelper;
	int retval = 0;
	while(retval < 1 || retval > 2) {
		cout << "Do you wish to add a new item to the order, or edit an existing item?" << endl;
		cout << "1. Add a new item" << endl;
		//cout << "2. Edit existing item" << endl;
		cout << "2. exit POS" << endl;
	
		getline(cin, parseHelper);
		retval = stoi(parseHelper);
		if(retval < 1 || retval > 2) {
			cout << "Bad input! Value must be a number between 1 and 3." << endl;
		}
	}
	
	return retval;
}
