#include "dataLoader.h"
#include "restaurantClass.h"
#include "foodItem.h"
#include <iostream>
#include <fstream>
using namespace std;

//internal functions used by the LoadData function
bool LoadRestData(Restaurant* holder, string dataFile);
bool LoadFoodData(vector<foodItem>* holder, string dataFile);

bool LoadData(Restaurant* restaurant_holder, vector<foodItem>* foodItems_holder, string foodItemFile, string restaurantDataFile) {
	//first, read the restuarant data
	bool restSuccess = LoadRestData(restaurant_holder, restaurantDataFile);
	if(!restSuccess)
		return false;
		
	bool foodSuccess = LoadFoodData(foodItems_holder, foodItemFile);
	
	return foodSuccess;
}

bool LoadRestData(Restaurant* holder, string dataFile) {
	
}

bool LoadFoodData(vector<foodItem>* holder, string dataFile) {
	ifstream foodStream(dataFile.c_str());
	string workingLine;
	
	foodItem* curItem;
	bool isItem = false;
	string fname = "FOODNAME=";
	string ftype = "FOODTYPE=";
	string fprice = "PRICE=";
	getline(foodStream, workingLine);
	if(workingLine == "[FOODFILE1_0]") {
		
		getline(foodStream, workingLine);
		while(workingLine != "[ENDFILE]") {
			
		//this is a food item file, continue
		if(workingLine == "[FOODITEM]") {
			curItem = new foodItem();
			isItem = true;
		} else if (!workingLine.compare(0, fname.length(), fname)) {
						
		} else if (!workingLine.compare(0, ftype.length(), ftype)) {
			
		} else if (!workingLine.compare(0, fprice.length(), fprice)) {
			
		} else if (workingLine == "[ENDFOODITEM]") {
			
		}
		else {

		}
			//end of loop, get next line
		getline(foodStream, workingLine);
		}
	} else {
		//bad file, leave.
		foodStream.close();
		return false;
	}
}

int main() {
	vector<foodItem> foods;
	Restaurant restaurant;
	
	bool val = LoadData(&restaurant, &foods, "testFoodFile.txt", "testRestFile.txt");
	
	cout << val << endl;
	
	return 0;
}
