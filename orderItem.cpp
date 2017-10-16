#include "orderItem.h"
#include <iostream>
using namespace std;

void orderItem::setCustomerName(string _name) {
	customerName = _name;
}
 
void orderItem::setServerName(string _name){
	serverName = _name;
}

void orderItem::setPaid(){
	if (paid = false){
		paid = true;
	}
	else{
		paid = false;
	}
}

void orderItem::setTotal(double _total){
	total = _total;
}

void orderItem::setTaxRate(double _tax){
	taxRate = _tax;
}

void orderItem::setTip(double _tip){
	tip = _tip;
}

void orderItem::setTableNumber(int _tableNumber){
	tableNumber = _tableNumber;
}

void orderItem::setServerRating(int _serverRating){
	serverRating = _serverRating;
}

void orderItem::setNumOfCustomers(int _numOfCustomers){
	numOfCustomers = _numOfCustomers;
}

foodItem orderItem::getFoodItemAt(int count) {
	if(count < foodOrder.size()) {
		return foodOrder[count];
	}
}

void orderItem::setFoodItemAt(int count, foodItem item) {
	if(count < foodOrder.size()) {
		foodOrder[count] = item;
	}
}

void orderItem::removeFoodItemAt(int count) {
	if(count < foodOrder.size()) {
		foodItem holder;
		for(int i = count+1; i < foodOrder.size(); i++) {
			holder = foodOrder[i];
			foodOrder[i] = foodOrder[i-1];
			foodOrder[i-1] = holder;
		}
		foodOrder.pop_back();
	}
}

string orderItem::getCustomerName() const{
	return customerName;
}

string  orderItem::getServerName() const{
	return serverName;
}

bool orderItem::getPaid() const{
	return paid;
}

double orderItem::getTax() const{
	return tax;
}

double orderItem::getTip() const{
	return tip;
}

int orderItem::getTableNumber() const{
	return tableNumber;
}

int orderItem::getServerRating() const{
	return serverRating;
}

int orderItem::getNumOfCustomers() const{
	return numOfCustomers;
}

double orderItem::calculateTax(double subTotal){
	tax = subTotal * getTaxRate();
	return tax;
};

void orderItem::addFoodItem(foodItem item){
	foodOrder.push_back(item);
}

void orderItem::deleteFoodItem(){
	foodOrder.pop_back();
}

int orderItem::getNumOfItems(){
	return foodOrder.size();
}

double orderItem::getTaxRate() const {
	return taxRate;
}

double orderItem::getSubTotal(){
	for (int i=0; i<foodOrder.size(); i++){
		subTotal = subTotal + foodOrder[i].getPrice();
	}
	return subTotal;
}

double orderItem::getTotal(){
	total = subTotal + tax;
	return total;
}

void orderItem::printTicket(){
	for (int i=0; i<foodOrder.size(); i++){
		cout << foodOrder[i].getName() << endl;
		cout << foodOrder[i].getType() << endl;
		cout << foodOrder[i].getnotes() << endl;
		cout << foodOrder[i].getPrice() << endl;
		cout << endl;
	}
}

