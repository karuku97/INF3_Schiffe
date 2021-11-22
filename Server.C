/*
 * server.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */
#include "Server.H"

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
#include <iostream>
#include "TASK3.H"

#include "SIMPLESOCKET.H"


int main(){
	srand(time(nullptr));
	myServer srv(2021,25);



	srv.run();
}



string myServer::myResponse(string input){

	if(input.compare(0,5,"KORDS") == 0){
			int xPos = input.find("X");
			int yPos = input.find("Y");
			int end = input.find("#");
			int x = stoi(input.substr(xPos+1,yPos-xPos-1));
			int y = stoi(input.substr(yPos+1,end-yPos-1));
			string result;

			std::cout << std::endl<<std::endl ;

			res = w.shoot(x,y);
			cout << "shoot: (" << x << ", " << y << ") --> " << res << endl;

			switch (res)
			{
				case 0 :
					result =  "Water";
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

	}else if(input.compare(0,7,"RESTART") ==0 ){
		TASK3::World newWorld;
		w =  newWorld;
		w.printBoard();
		return "RESTARTED";
	}
	else{
			return "ERROR";
		}

}

