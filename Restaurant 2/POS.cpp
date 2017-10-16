#include "foodItem.h"
#include "restaurantClass.h"
#include "orderItem.h"
#include "serverClass.h"
#include <iostream>
#include <string>
using namespace std;
vector<Server> servers(4);
vector<foodItem> foodItem(4);
int orderNumber = 0;
int numOfCustomers;
int itemNumber;
orderItem newOrderItem;

void getDrinks();
void getfoodOrder();
void printBill();
void welcomeServer(int _sNumber);

int main() {

int sNumber;

int drink;
int option;


Restaurant Franks;
Franks.setRestaurantName("Franks");
Franks.setCapacity(100);
servers[0].setServerName("Fiona");
servers[0].setServerNumber(001);
servers[1].setServerName("Kevin");
servers[1].setServerNumber(002);
servers[2].setServerName("Elliot");
servers[2].setServerNumber(003);

foodItem[0].setName("2 Eggs and Toast");
foodItem[0].setType("Breakfast");
foodItem[0].setPrice(2.99);
foodItem[0].setItemNumber(1);

foodItem[1].setName("2 Eggs Hash browns, Toast, Bacon");
foodItem[1].setType("Breakfast");
foodItem[1].setPrice(4.99);
foodItem[1].setItemNumber(2);

foodItem[2].setName("Biscuits & Gravy with 2 eggs");
foodItem[2].setType("Breakfast");
foodItem[2].setPrice(5.99);
foodItem[2].setItemNumber(3);

foodItem[3].setName("Eggs Benedict with Fruit");
foodItem[3].setType("Breakfast");
foodItem[3].setPrice(8.99);
foodItem[3].setItemNumber(4);
	
cout << "Welcome! What would you like to do?" << endl;
cout << "Enter 1 to create new order" << endl;
cout << "Enter 2 to close an order" << endl;
cin >> option;
	
if (option == 1)
{
	orderNumber++;
	
	newOrderItem.orderNum = orderNumber;
	
	cout << "Please enter your name: ";
	cin >> newOrderItem.serverName;
	 
	cout << "please enter table number: ";
	cin >> newOrderItem.tableNumber;
	
	cout << "Please enter number of patrons at this table: ";
	cin >> numOfCustomers;
	
	getDrinks();
	getFoodOrder();
}

/*if (option == 2)
{
	cout << "Please enter order number: ";
	cin >> orderNumber
	printBill(orderNumber);
}*/
	
	return 0;
}

//Function to output greeting with servers name
void welcomeServer(int _sNumber){
	for (int i =0; i < servers.size(); i++)
	{
		if (_sNumber == servers[i].serverNumber)
		{
			cout << "Welcome " << servers[i].serverName << endl;
		}
	}
};

//Function to take drink orders
void getDrinks(){
	for (int i =1; i <= numOfCustomers; i++)
{
	cout << "Please enter number for customer " << i  << "s drink: ";
	cin >> itemNumber;
	for (int j=0; j < foodItem.size(); j++)
	{
		if (itemNumber == foodItem[j].itemNumber)
		{
			newOrderItem.addFoodItem(foodItem[j]);
			j = foodItem.size();
		}
	}
}
	//Summarized drink order
	cout << "You're drink order is : " << endl;
	for (int i = 0; i < newOrderItem.foodOrder.size(); i++)
	{
		cout << newOrderItem.foodOrder[i].name << endl;
	}
}

//Function to take food order
void getfoodOrder(){
	for (int i =1; i <= numOfCustomers; i++)
{
	cout << "Please enter number for customer " << i  << "s food: ";
	cin >> itemNumber;
	for (int j=0; j < foodItem.size(); j++)
	{
		if (itemNumber == foodItem[j].itemNumber)
		{
			newOrderItem.addFoodItem(foodItem[j]);
			j = foodItem.size();
		}
	}
}
	//summarized food order
	cout << "You're food order is : " << endl;
	for (int i = 0; i < newOrderItem.foodOrder.size(); i++)
	{
		cout << newOrderItem.foodOrder[i].name << endl;
	}
}

/*void printBill(int orderNumber)
{
	for (int i = 0; i < foodOrder.size(); i++)
	{
		if (orderNumber = foodOrder[i].orderNum)
		{
			cout << 
			for (int i = 0; i < newOrderItem.foodOrder.size(); i++)
			{
			cout << newOrderItem.foodOrder[i].name << endl;
			}
		}
	}
}*/
