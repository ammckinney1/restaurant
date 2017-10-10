#include "dataLoader.h"
#include "foodItem.h"
#include "restaurantClass.h"
#include "orderItem.h"
#include <iostream>
using namespace std;

int addOrSelect();

int main() {
	vector<foodItem> items;
	Restaurant restData;
	bool loaded = LoadData(restData, items, "foodData.txt", "restaurantData.txt");
	if(!loaded) {
		//error in the loading process, report it and then exit
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
			itemTypes.push_back(items[i].getType);
		}
	}
	
	orderItem order;
	bool nextOrder = true;
	while(nextOrder) {
		//do order stuff
		int selector = addOrSelect();
		if(selector == 3) {
			break;
		} else if (selector == 2) {
			
		} else if (selector == 1) {
			//choose a category
			cout << "Select a category of items" << endl;
			for(int cat = 0; cat < itemTypes.size(); cat++) {
				cout << (cat+1) << ". " << itemTypes[cat] << endl;
			}
			int catSelect = 0;
			while(catSelect < 1 || catSelect > itemTypes.size()) {
				cin >> catSelect;
				
				if(catSelect < 1 || catSelect > itemTypes.size()) {
						cout << "Bad selection, please try again." << endl;
				}
			}
			catSelect--;
			
			//category is selected, now choose an item
			cout << "Select an item to add to the order" << endl;
			vector<foodItem> catItems;
			for(int it = 0; it < items.size(); it++) {
				
			}
		}
		
		//order is finished, ask if the POS should do another order
		bool testEnd = true;
		while(testEnd) {
			cout << "Do you wish to make another order? (y/n)" << endl;
			char c;
			cin >> c;
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
	int retval = 0;
	while(retval < 1 && retval > 3) {
		cout << "Do you wish to add a new item to the order, or edit an existing item?" << endl;
		cout << "1. Add a new item" << endl;
		cout << "2. Edit existing item" << endl;
		cout << "3. exit POS" << endl;
	
		cin >> retval;
		if(retval < 1 || retval > 3) {
			cout << "Bad input! Value must be a number between 1 and 3." << endl;
		}
	}
	
	return retval;
}
