/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */

#include"Client.H"
#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>

#include "SIMPLESOCKET.H"

#include "IntelliStrat.H"
#include "BruteForce.H"
#include "Random.H"



using namespace std;


void restart(TCPclient c);


int main(int argc, const char **argv) {

	if (argc != 3){

		char a;
		cout<<"Input not correct"<< endl;
		cout<<"Input are two numbers"<< endl;
		cout<<"The first number states how often the strategy should be repeated, you can choose any unsigned integer"<<endl;
		cout<<"The second number is for a strategy 0: BRUTEFORCE, 1: BRUTEFORCEDIAGONAL, 2: RANDSHOOT, 3: RANDSHOOTIS, 4: INTELLISTRAT, 5: INTELLISTRATDIAGONAL,"<<endl;
		cout<<"For example: ./Client 15 4"<< endl;
		exit (-1);

	}

	srand(time(NULL));

	int anz; // anzahl der durchlaufe pro Stategie
	sscanf(argv[1],"%i",&anz);
	//printf("Parameter : %d ",anz);
	//printf("\n");

	int meth;
	sscanf(argv[2],"%i",&meth);
	//printf("Strategienummer: %d \n", meth);

	TCPclient c;
	string host = "localhost";

	//connect to host
	c.conn(host , 2021);

	cout << "strategy: ";
		switch(meth){
					case 0: printf("BRUTEFORCE");break;
					case 1: printf("BRUTEFORCEDIAGONAL");break;
					case 2: printf("RANDSHOOT");break;
					case 3: printf("RANDSHOOTIS");break;
					case 4: printf("INTELLISTRAT");break;
					case 5: printf("INTELLISTRATDIAGONAL");break;
					default: printf("Die Strategie existiert nicht.\n");break;exit(0); // Fehlermeldung wird nur einmal erzeugt und nicht anz-mal ausgegeben
					}

		 cout << endl;

	int moves;

	for(int i=0; i<anz; i++){
		switch(meth){
			case 0: moves = BruteForce(c);break;
			case 1: moves = BruteForceDiagonal(c);break;
			case 2: moves = RandShoot(c);break;
			case 3: moves = RandShootiS(c);break;
			case 4: moves = IntelliStrat(c);break;
			case 5: moves = IntelliStratDiagonal(c);break;
			default: printf("Die Strategie existiert nicht.\n");break;exit(0); // Fehlermeldung wird nur einmal erzeugt und nicht anz-mal ausgegeben
			}
	cout << moves << endl;
	moves = 0;
	restart(c);
	}


	c.sendData("BYEBYE");

}

void restart(TCPclient c){
	string msg = "RESTART     ";
	// cout << "client sends:" << msg << endl;
	c.sendData(msg);
	msg = c.receive(32);

	if(msg.compare(0,9,"RESTARTED")==0); // cout<< "got response:" << msg<<endl;
	else{ cout<< "ERROR beim erstellen eines neuen Spieles"<<endl;
	}
}



//Ausgab fehlt noch



