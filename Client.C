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
#include <vector>

#include "IntelliStrat.H"
#include"BruteForce.H"
#include "Random.H"
#include "SIMPLESOCKET.H"


using namespace std;


void restart(TCPclient c);

//int intelliStrat(TCPclient c);
//string shoot(int x , int y, TCPclient c);

int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";


	//connect to host
	c.conn(host , 2021);



	//cout<<endl << "Moves: " <<intelliStratDiagonal(c)<<endl;


	//cout<<"Moves: "<<BruteForceDiagonal(c)<<endl;;


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


	cout<<endl<< "----------"<<endl<< "AvarageMoves(BruteForce): "<< movesAvg<<endl<<"-----------"<<endl;

	c.sendData("BYEBYE");

}





void restart(TCPclient c){
	c.sendData("RESTART    ");
	if(c.receive(32).compare(0,9,"RESTARTED")==0) cout<< "neues Spiel!"<<endl;
	else{ cout<< "ERROR beim erstellen eines neuen Spieles"<<endl;

	}
}

