/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>

#include "SIMPLESOCKET.H"

using namespace std;

int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg;

	//connect to host
	c.conn(host , 2021);

	string x,y;
	int i=0;
	bool goOn=1;
	while(goOn){ // send and receive data

		cout<< "X: "; cin >> x;
		cout << endl << "Y: "; cin >> y;
		cout << endl;

		stringstream ss;
		ss << x << "/" << y;
		msg = ss.str();

		cout << "client sends:" << msg << endl;
		c.sendData(msg);
		msg = c.receive(32);
		cout << "got response:" << msg << endl;
		sleep(1);


	}
}
