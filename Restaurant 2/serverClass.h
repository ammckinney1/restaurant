#ifndef serverClass_H
#define serverClass_H
#include <string>
using namespace std;

class Server {
	public:
		string serverName;
		int serverNumber;

	public:
		void setServerName(string _serverName);
		void setServerNumber(int _serverNumber);
		string getServerName();
		int getServerNumber();
		
};
#endif
