#include "dataLoader.h"
#include "restaurantClass.h"
#include "foodItem.h"
#include <iostream>
#include <fstream>
using namespace std;

bool LoadData(Restaurant* restuarant_holder, vector<foodItem>* foodItems_holder, string foodItemFile, string restuarantDataFile) {
	//first, read the restuarant data
	ifstream restuarantStream;
	restuarantStream.open(restuarantDataFile.c_str());
	if(restuarantStream.is_open()) {
		string workingline;
		std::getline(restuarantStream, workingline);
	} else {
		//error opening file, return false to indicate that loading failed.
		return false;
	}
	
	
	
	return true;
}

int main() {
	vector<foodItem> foods;
	Restaurant restaurant;
	
	bool val = LoadData(&restaurant, &foods, "testFoodFile.txt", "testRestFile.txt");
	
	cout << val << endl;
	
	return 0;
}
