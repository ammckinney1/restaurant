#ifndef DATALOADER_H
#define DATALOADER_H
#include "restaurantClass.h"
#include "foodItem.h"
#include <vector>
#include <string>

//function for loading data files. First two variables are pointers to where the code should store the loaded data.
//The final two variables are the location of the data files.
bool LoadData(Restaurant& restuarant_holder, vector<foodItem>& foodItems_holder, string foodItemFile, string restuarantDataFile);

#endif
