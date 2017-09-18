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
		void setRestaurantName();
		void setServerName();
		void setCapacity();
	public:
		string getRestaurantName();
		string getServerName();
		int getCapacity();
};
#endif
