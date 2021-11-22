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
#include "SIMPLESOCKET.H"


using namespace std;

int BruteForce(TCPclient c);
void restart(TCPclient c);
int BruteForceDiagonal(TCPclient c);
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
			movesAvg = intelliStratDiagonal(c);
			restart(c);
		}
		else{
			movesAvg = (movesAvg+intelliStratDiagonal(c)) /2;
			restart(c);
		}
	}


	cout<<endl<< "----------"<<endl<< "AvarageMoves(BruteForce): "<< movesAvg<<endl<<"-----------"<<endl;



}



int BruteForceDiagonal(TCPclient c){
	stringstream ss;
	string msg;
	int moves=0;


	int m = 10;
	int n= 10;
	int i;
	int j;



	for (int k=0;k<=m-1;k++){
		 i = k;
		 j = 0;
		 while(i>=0){

			 ss.str("");
			 ss<<"KORDSX"<<( i+1) << "Y" <<( j+1)<<"#";
			 msg = ss.str();
			 cout << "client sends:" << msg << endl;
			 c.sendData(msg);
			 moves++;
			 msg = c.receive(32);
			 if(msg.compare(0,9,"Game Over")==0)goto Part1;
			 cout << "got response:" << msg << endl;

			 i=i-1;
			 j= j+1;
			 //sleep(1);
		 }

	}

	for (int k = 1; k<=n-1;k++){
		i=m-1;
		j=k;
		while(j<=n-1){

			ss.str("");
			ss<<"KORDSX"<<( i+1) << "Y" << (j+1)<<"#";
			msg = ss.str();
			cout << "client sends:" << msg << endl;
			c.sendData(msg);
			moves++;
			msg = c.receive(32);
			if(msg.compare(0,9,"Game Over")==0)goto Part1;
			cout << "got response:" << msg << endl;

			i= i-1;
			j=j+1;
		}

	}
	Part1:


	return moves;
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

