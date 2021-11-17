/*
 * RandClientwS.C
 *
 *  Created on: 17.11.2021
 *      Author: pascalpiel
 */

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>

#include "SIMPLESOCKET.H"

using namespace std;

int RandShoot(TCPclient c);
void restart(TCPclient c);


int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";


	//connect to host
	c.conn(host , 2020);


	double movesAvg = 0.0;
	int anz=10;

	for(int i = 0; i< anz;i++){
			if(i==0){
				movesAvg = RandShoot(c);
				restart(c);
			}
			else{
				movesAvg = (movesAvg+RandShoot(c)) /2;
				restart(c);
			}
		}




	cout<<endl<< "----------"<<endl<< "AvarageMoves(Random): "<< movesAvg<<endl<<"-----------"<<endl;



}

int RandShoot(TCPclient c){
	stringstream ss;
	string msg;
	int moves=0;
	while(1){
		int x = (rand()%10)+1;
		int y = (rand()%10)+1;

		ss.str("");
		ss <<"KORDSX"<< x << "Y" << y<<"#";
		msg = ss.str();
		cout << "client sends:" << msg << endl;
		c.sendData(msg);
		moves++;
		msg = c.receive(32);
		cout << "got response:" << msg << endl;

		if(msg.compare(0,9,"Game Over")==0)goto Part1;

					//sleep(1);
		}

		Part1:
		//cout << "Moves: "<< moves <<endl;
		return moves;
}

void restart(TCPclient c){
	c.sendData("RESTART    ");
	if(c.receive(32).compare(0,9,"RESTARTED")==0) cout<< "neues Spiel!"<<endl;
	else{ cout<< "ERROR beim erstellen eines neuen Spieles"<<endl;

	}
}





