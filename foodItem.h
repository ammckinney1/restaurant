#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
using namespace std;

class foodItem {
	private:
		string name, type, notes;
		double price;

	private:
		void setName(string _name);
		void setType(string _type);
		void setnotes(string _notes);
	public:
		string getName();
		string getType();
		string getnotes();
};
#endif

