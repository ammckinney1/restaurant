#include "serverClass.h"

void Server::setServerName(string _serverName){
	serverName = _serverName;
};

void Server::setServerNumber(int _serverNumber){
	serverNumber = _serverNumber;
};

string Server::getServerName(){
	return serverName;
};

int Server::getServerNumber(){
	return serverNumber;
};


