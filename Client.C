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

#include "SIMPLESOCKET.H"

#include "IntelliStrat.H"
#include"BruteForce.H"
#include "Random.H"



using namespace std;


void restart(TCPclient c);



int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";


	//connect to host
	c.conn(host , 2021);


	int anz = 10; // anzahl der durchlaufe pro Stategie
	vector<pair<string,double>> strategien;
	pair<string,double> strat;
	string stratName;
	double movesAvg = 0.0;



	//Bruteforce
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
	strat.first = "BruteForce";
	strat.second = movesAvg;
	strategien.push_back(strat);

	movesAvg = 0.0;
	//BruteforceDiagonal
	for(int i = 0; i< anz;i++){
		if(i==0){
			movesAvg = BruteForceDiagonal(c);
			restart(c);
		}
		else{
			movesAvg = (movesAvg+BruteForceDiagonal(c)) /2;
			restart(c);
		}
	}
	strat.first = "BruteForceDiagonal";
	strat.second = movesAvg;
	strategien.push_back(strat);

	movesAvg = 0.0;
	//Random
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
	strat.first = "RandomShoot";
	strat.second = movesAvg;
	strategien.push_back(strat);

	movesAvg = 0.0;
	//IntelliStrat
	for(int i = 0; i< anz;i++){
		if(i==0){
			movesAvg = IntelliStrat(c);
			restart(c);
		}
		else{
			movesAvg = (movesAvg+IntelliStrat(c)) /2;
			restart(c);
		}
	}
	strat.first = "IntelliStrat";
	strat.second = movesAvg;
	strategien.push_back(strat);

	movesAvg = 0.0;
	//IntelliStratDiagonal
	for(int i = 0; i< anz;i++){
		if(i==0){
			movesAvg = IntelliStratDiagonal(c);
			restart(c);
		}
		else{
			movesAvg = (movesAvg+IntelliStratDiagonal(c)) /2;
			restart(c);
		}
	}
	strat.first = "IntelliStratDiagonal";
	strat.second = movesAvg;
	strategien.push_back(strat);



	//Ausgabe der Strategien
	cout<<endl<< "----------";
	for(int i = 0 ; i< strategien.size();i++){
		strat = strategien.at(i);
		cout<<endl<< strat.first <<" : "<< strat.second<<endl;
	}
	cout<<endl<< "----------"<<endl;


	c.sendData("BYEBYE");

}



//Ausgab fehlt noch

void restart(TCPclient c){
	string msg = "RESTART     ";
	cout << "client sends:" << msg << endl;
	c.sendData(msg);
	msg = c.receive(32);

	if(msg.compare(0,9,"RESTARTED")==0) cout<< "got response:" << msg<<endl;
	else{ cout<< "ERROR beim erstellen eines neuen Spieles"<<endl;

	}
}

