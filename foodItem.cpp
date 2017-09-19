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
};

void setName(string _name){
	name = _name;
};

void setType(string _type){
	type = _type;
};

void setnotes(string _note){
	note = _note;
};

string getName(){
	return name;
};

string getType(){
	return type;
};

string getnotes(){
	return notes;
};
