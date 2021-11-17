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

int BruteForce(TCPclient c);
void restart(TCPclient c);


int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";


	//connect to host
	c.conn(host , 2020);

	int anz = 10;
	double movesAvg = 0.0;

	for(int i = 0; i< anz;i++){
		if(i==0){
			movesAvg = BruteForce(c);
			restart(c);
		}
		else{
			movesAvg = (movesAvg+BruteForce(c)) /2;
			restart(c);
		}
	}


	cout<< "AvarageMoves: "<< movesAvg<<endl;



}

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

					if(msg.compare(0,9,"Game Over")==0)goto Part1;

					//sleep(1);
				}
			}
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

