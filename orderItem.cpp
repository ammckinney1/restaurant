Class orderItem 
{
private:
    string customerName, serverName;
    boolean paid;
    double total, tax, tip;
    int tableNumber, serverRating, numOfCustomers;

public:
	void setCustomerName(string _name);
	void setServerName(string _name);
	void setPaid(boolean _paid);
	void setTotal(double _total);
	void setTax(double _tax);
	void setTip(double _tip);
	void setTableNumber(int _tableNumber);
	void setServerRating(int _serverRating);
	void setNumOfCustomers(int _numOfCustomers);
	
	string getCustomerName() const;
	string  getServerName() const;
	boolean getPaid() const;
	double getTotal() const;
	double getTax() const;
	double getTip() const;
	int getTableNumber() const;
	int getServerRating() const;
	int getNumOfCustomers() const;
};

 void setCustomerName(string _name){
 	customerName = _name;
 };
 
void setServerName(string _name){
	serverName = _name;
};

void setPaid(){
	if (paid = false){
		paid = true;
	}
	else{
		paid = false;
	}
};

void setTotal(double _total){
	total = _total;
};

void setTax(double _tax){
	tax = _tax;
};

void setTip(double _tip){
	tip = _tip;
};

void setTableNumber(int _tableNumber){
	tableNumber = _tableNumber;
};

void setServerRating(int _serverRating){
	serverRating = _serverRating;
};

void SetNumOfCustomers(int _numOfCustomers){
	numOfCustomers = _numOfCustomers;
};

string getCustomerName(){
	return customerName;
};

string  getServerName(){
	return serverName;
};

boolean getPaid(){
	return paid;
};

double getTotal(){
	return total;
};

double getTax(){
	return tax;
};

double getTip(){
	return tip;
};

int getTableNumber(){
	return tableNumber;
};

int getServerRating(){
	return serverRating;
};

int getNumOfCustomers(){
	return numOfCustomers;
};

