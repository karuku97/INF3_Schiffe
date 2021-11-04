/*
 * server.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */
#include <cstdio> // standard input and output library
#include <cstdlib> // this includes functions regarding memory allocation
#include <cstring> // contains string functions
#include <cerrno> //It defines macros for reporting and retrieving error conditions through error codes
#include <ctime> //contains various functions for manipulating date and time

#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses
#include"myServer.H"
#include <iostream>
#include "TASK3.H"

#include "SIMPLESOCKET.H"


int main(){
	srand(time(nullptr));
	myServer srv(2021,25);



	srv.run();
}

vector<int> myServer::convKord(string input){

		istringstream ss {input};
		vector<int> stringV;

		while(ss.good()){
			string substr ;
			std::getline(ss,substr, '/');
			stringV.push_back(stoi(substr));
		}

	    return stringV;
}


string myServer::myResponse(string input){


	// if(input.compare(0,4)==0){};  alternative zu case?
	// terminal "telnet localhost port"
	vector<int> kords ;

	std::cout << std::endl<<std::endl ;



	std::cout << std::endl<<std::endl ;

	kords = convKord(input);


			string result;
			res = w.shoot(kords[0],kords[1]);
			cout << "shoot: (" << kords[0] << ", " << kords[1] << ") --> " << res << endl;

			switch (res)
			{
			case 0 :
				result =  "water";
				break;
			case 1 :
				result =  "Ship Hit";
				break;
			case 2 :
				result =  "Ship Destroyed";
				break;
			case 3 :
				result =  "All Ships Destroyed";
				break;
			case 4 :
				result =  "Game Over";
				break;


			}

	w.printBoard();
	return result;
}

