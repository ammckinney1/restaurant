#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
using namespace std;

class foodItem {
	private:
		string name, type, notes;
		double price;

	public:
		void setName(string _name);
		void setType(string _type);
		void setnotes(string _notes);
		void setPrice(double _price);
	public:
		string getName();
		string getType();
		string getnotes();
		double getPrice();
};
#endif

