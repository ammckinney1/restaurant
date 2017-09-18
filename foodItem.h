#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
using namespace std;

class foodItem {
	private:
		string name, type, notes;
		double price;

	private:
		void setName();
		void setType();
		void setnotes();
	public:
		string getName();
		string getType();
		string getnotes();
};
#endif
