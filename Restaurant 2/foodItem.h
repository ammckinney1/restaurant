#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
using namespace std;

class foodItem {
	public:
		string name, type, notes;
		double price;
		int itemNumber;

	public:
		void setName(string _name);
		void setType(string _type);
		void setnotes(string _notes);
		void setPrice(double _price);
		void setItemNumber(int _itemNumber);
	public:
		string getName();
		string getType();
		string getnotes();
		double getPrice();
		int getItemNumber();
		foodItem copy();
};
#endif

