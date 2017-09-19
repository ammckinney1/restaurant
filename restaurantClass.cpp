Class Restaurant 
{
private:
    string restaurantName;
    string serverName;
    int capacity;
public:
	void setRestaurantName(string _restaurantName);
	void setServerName(string _serverName);
	void setCapacity(int _capacity);
	string getRestaurantName() const;
	string getServerName() const;
	int getCapacity() const;
};

void setRestaurantName(string _restaurantName){
	restaurantName = _restaurantName;
};

void setServerName(string _serverName){
	serverName = _serverName;
};

void setCapacity(int _capacity){
	capacity = _capacity;
};

string getRestaurantName(){
	return restaurantName
};

string getServerName(){
	return serverName;
};

int getCapacity(){
	return capacity;
};
