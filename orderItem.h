#ifndef ORDERITEM_H
#define ORDERITEM_H
#include <string>
#include "foodItem.h"
using namespace std;

class orderItem 
{
private:
    string customerName, serverName;
    bool paid;
    double total, tax, tip;
    int tableNumber, serverRating, numOfCustomers;
	vector<foodItem> foodOrder;

public:
	void setCustomerName(string _name);
	void setServerName(string _name);
	void setPaid();
	void setTotal(double _total);
	void setTax(double _tax);
	void setTip(double _tip);
	void setTableNumber(int _tableNumber);
	void setServerRating(int _serverRating);
	void setNumOfCustomers(int _numOfCustomers);
	
	void addFoodItem(foodItem item);
	void deleteFoodItem();
	int getNumOfItems();
	
	string getCustomerName() const;
	string  getServerName() const;
	bool getPaid() const;
	double getTotal() const;
	double getTax() const;
	double getTip() const;
	int getTableNumber() const;
	int getServerRating() const;
	int getNumOfCustomers() const;
};

#endif
