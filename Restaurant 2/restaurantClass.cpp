#include "restaurantClass.h"

void Restaurant::setRestaurantName(string _restaurantName){
	restaurantName = _restaurantName;
}

void Restaurant::setCapacity(int _capacity){
	capacity = _capacity;
}

string Restaurant::getRestaurantName(){
	return restaurantName;
}

int Restaurant::getCapacity(){
	return capacity;
}

