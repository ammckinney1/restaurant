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
}
