#include "BruteForceDiagonal.H"
#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>

#include "SIMPLESOCKET.H"

using namespace std;



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
			 if(msg.compare(0,8,"GameOver")==0)return moves;
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
			if(msg.compare(0,8,"GameOver")==0)return moves;
			cout << "got response:" << msg << endl;

			i= i-1;
			j=j+1;
		}

	}



	return moves;
}