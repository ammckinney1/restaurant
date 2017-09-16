Class foodItem 
{
private:
    string name, type, notes;
    double price;

public:
	void setName(string _name);
	void setType(string _type);
	void setnotes(string _note);
	string getName() const;
	string getType() const;
	string getnotes() const;
}
