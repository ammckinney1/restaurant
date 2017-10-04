#include "orderItem.h"
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

void orderItem::setTax(double _tax){
	tax = _tax;
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

string orderItem::getCustomerName() const{
	return customerName;
}

string  orderItem::getServerName() const{
	return serverName;
}

bool orderItem::getPaid() const{
	return paid;
}

double orderItem::getTotal() const{
	return total;
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

