#ifndef RESTUARANTCLS_H
#define RESTUARANTCLS_H
#include <string>
using namespace std;

class Restaurant {
	private:
		string restaurantName;
		string serverName;
		int capacity;

	private:
		void setRestaurantName(string _restaurantName);
		void setServerName(string _serverName);
		void setCapacity(int _capacity);
	public:
		string getRestaurantName();
		string getServerName();
		int getCapacity();
};
#endif
