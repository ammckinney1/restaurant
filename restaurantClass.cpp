#include "restaurantClass.h"

void Restaurant::setRestaurantName(string _restaurantName){
	restaurantName = _restaurantName;
}

void Restaurant::setServerName(string _serverName){
	serverName = _serverName;
}

void Restaurant::setCapacity(int _capacity){
	capacity = _capacity;
}

string Restaurant::getRestaurantName(){
	return restaurantName;
}

string Restaurant::getServerName(){
	return serverName;
}

int Restaurant::getCapacity(){
	return capacity;
}
