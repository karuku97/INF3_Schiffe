#include "BruteForce.H"
#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>

#include "SIMPLESOCKET.H"


using namespace std;



int BruteForce(TCPclient c){
	stringstream ss;
	string msg;
	int moves=0;

		while(1){ // funktioniert nicht
			for(int x =1; x <= 10 ; x++){
				for(int y =1 ; y<= 10 ; y++){
					ss.str("");
					ss <<"KORDSX"<< x << "Y" << y<<"#";
					msg = ss.str();
					cout << "client sends:" << msg << endl;
					c.sendData(msg);
					moves++;
					msg = c.receive(32);
					cout << "got response:" << msg << endl;

					if(msg.compare(0,8,"GameOver")==0)return moves;

					//sleep(1);
				}
			}
		}
		return moves;

}