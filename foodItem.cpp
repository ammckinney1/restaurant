#include "foodItem.h"

void foodItem::setName(string _name) {
	name = _name;
}

void foodItem::setType(string _type){
	type = _type;
}

void foodItem::setnotes(string _note){
	notes = _note;
}

void foodItem::setPrice(double _price){
	price = _price;
}

string foodItem::getName(){
	return name;
}

string foodItem::getType(){
	return type;
}

string foodItem::getnotes(){
	return notes;
}

double foodItem::getPrice(){
	return price;
}

foodItem foodItem::copy() {
	foodItem retval;
	retval.setName(this.getName());
	retval.setPrice(this.getPrice());
	retval.setType(this.getType());
	retval.setnotes(this.getnotes());
	return retval;
}
