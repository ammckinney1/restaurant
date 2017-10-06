#include "dataLoader.h"
#include "restaurantClass.h"
#include "foodItem.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//internal functions used by the LoadData function
bool LoadRestData(Restaurant& holder, string dataFile);
bool LoadFoodData(vector<foodItem>& holder, string dataFile);
vector<string> splitString(const string& origin, const string& delim);

bool LoadData(Restaurant& restaurant_holder, vector<foodItem>& foodItems_holder, string foodItemFile, string restaurantDataFile) {
	//first, read the restuarant data
	bool restSuccess = LoadRestData(restaurant_holder, restaurantDataFile);
	if(!restSuccess)
		return false;
		
	bool foodSuccess = LoadFoodData(foodItems_holder, foodItemFile);
	
	return foodSuccess;
}

bool LoadRestData(Restaurant& holder, string dataFile) {
	return false;
}

bool LoadFoodData(vector<foodItem>& holder, string dataFile) {
	ifstream foodStream(dataFile.c_str());
	string workingLine;
	
	foodItem* curItem;
	bool isItem;
	isItem = false;
	const string fname = "FOODNAME=";
	const string ftype = "FOODTYPE=";
	const string fprice = "PRICE=";
	getline(foodStream, workingLine);
	if(workingLine == "[FOODFILE1_0]") {
		
		//this is a food item file, continue
		
		getline(foodStream, workingLine);
		while(workingLine != "[ENDFILE]") {
			
			if(workingLine == "[FOODITEM]") {
				curItem = new foodItem();
				isItem = true;
			} else if (!workingLine.compare(0, fname.length(), fname)) {
				//line contains the name of the item
				if(isItem) {
					string value = splitString(workingLine, "=")[1];
					curItem->setName(value);	
				}
			} else if (!workingLine.compare(0, ftype.length(), ftype)) {
				//line contains the type of the item
				if(isItem) {
					string value = splitString(workingLine, "=")[1];
					curItem->setType(value);
				}
			} else if (!workingLine.compare(0, fprice.length(), fprice)) {
				//line contains the item price.
				if(isItem) {
					string value = splitString(workingLine, "=")[1];
					curItem->setPrice(std::stod(value));
				}
			} else if (workingLine == "[ENDFOODITEM]") {
				holder.push_back(*curItem);
				curItem = 0;
				isItem = false;
			} else {

			}
			//end of loop, get next line
			getline(foodStream, workingLine);
		}
	} else {
		//bad file, leave.
		foodStream.close();
		return false;
	}
	
	foodStream.close();
	
	return true;
}

//helper function to split a string
//
vector<string> splitString(const string& origin, const string& delim) {
	vector<string> return_val;
	
	size_t last_pos = 0;
	size_t cur_pos = origin.find(delim, last_pos+1);
	string temp_val = origin.substr(last_pos, cur_pos - last_pos);
	cout << temp_val << endl;
	return_val.push_back(temp_val);
	while(cur_pos != string::npos) {
		last_pos = cur_pos;
		cur_pos = origin.find(delim, last_pos+1);
		if(cur_pos != string::npos) {
			string temp_val = origin.substr(last_pos+1, cur_pos - (last_pos+1));
			cout << temp_val << endl;
			return_val.push_back(temp_val);
		}
	}
	
	return return_val;
}

int main() {
	vector<foodItem> foods;
	Restaurant restaurant;
	
	string tester = "FOODITEM=BLADDER=TEMP=BLURGH";
	
	vector<string> temp = splitString(tester, "=");
	
	//bool val = LoadData(&restaurant, &foods, "testFoodFile.txt", "testRestFile.txt");
	
	//cout << val << endl;
	
	return 0;
}
