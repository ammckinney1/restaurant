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
	ifstream restStream(dataFile.c_str());
	string workingLine;
	
	const string rName = "NAME=";
	const string rServer = "SERVER=";
	const string rCapacity = "CAPACITY=";
	
	getline(restStream, workingLine);
	if(workingLine == "[RESTFILE1_0]") {
		//this is the restaurant data file
		vector<string> tempServerHolder;
		getline(restStream, workingLine);
		while(workingLine != "[ENDFILE]") {
			if(!workingLine.compare(0, rName.length(), rName)) {
				//restaurant name
				holder.setRestaurantName(splitString(workingLine, "=")[1]);
			} else if(!workingLine.compare(0, rCapacity.length(), rCapacity)) {
				//restaurant capacity
				string capacity_str = splitString(workingLine, "=")[1];
				int capacity_num = stoi(capacity_str, nullptr, 10);
				holder.setCapacity(capacity_num);
			} else if(!workingLine.compare(0, rServer.length(), rServer)) {
				//restaurant server
				string server_str = splitString(workingLine, "=")[1];
				tempServerHolder.push_back(server_str);
			}
			getline(restStream, workingLine);
		}
		
		//combine the server names in to one string for storage
		string servers = "";
		for(int counter = 0; counter < tempServerHolder.size(); counter++) {
			if(counter != 0)
				servers.append(":");
			servers.append(tempServerHolder[counter]);
		}
		
		holder.setServerName(servers);
		return true;
	} else {
		//bad file, leave
		restStream.close();
		return false;
	}
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
	//cout << temp_val << endl;
	return_val.push_back(temp_val);
	while(cur_pos >= 0 && cur_pos < origin.length()) {
		last_pos = cur_pos;
		cur_pos = origin.find(delim, last_pos+1);
		string temp_val = origin.substr(last_pos+1, cur_pos - (last_pos+1));
		return_val.push_back(temp_val);
	}
	
	return return_val;
}


/*
 * Drive main. Uncomment to compile driver
 */
/*
int main() {
	vector<foodItem> foods;
	Restaurant restaurant;
	
	string tester = "FOODITEM=BLADDER=TEMP=BLURGH";
	
	vector<string> temp = splitString(tester, "=");
	
	bool val = LoadData(restaurant, foods, "foodData.txt", "restaurantData.txt");
	
	if(val) {
		for(int counter = 0; counter < foods.size(); counter++) {
			cout << foods[counter].getName() << endl;
			cout << foods[counter].getType() << endl;
			cout << foods[counter].getPrice() << endl;
		}
	} else {
		cout << "Failure to load data" << endl;
	}
	
	return 0;
}
*/
