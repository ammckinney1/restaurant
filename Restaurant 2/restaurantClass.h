#ifndef RESTUARANTCLS_H
#define RESTUARANTCLS_H
#include <string>
using namespace std;

class Restaurant {
	private:
		string restaurantName;
		string serverName;
		int capacity;

	public:
		void setRestaurantName(string _restaurantName);
		void setCapacity(int _capacity);
	public:
		string getRestaurantName();
		int getCapacity();
};
#endif
