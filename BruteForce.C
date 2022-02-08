/*
 * BruteForce.C
 *
 *  Created on: 22.12.2021
 *      Author: pascalpiel
 */
#include "BruteForce.H"

int BruteForceDiagonal(TCPclient c){
	
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


			 msg = shootPos(i+1, j+1, c);

			 moves++;

			 if(msg.compare(0,8,"GameOver")==0)return moves;
		
			 i=i-1;
			 j= j+1;

		 }

	}

	for (int k = 1; k<=n-1;k++){
		i=m-1;
		j=k;
		while(j<=n-1){

			msg = shootPos(i+1, j+1, c);

			 moves++;

			if(msg.compare(0,8,"GameOver")==0)return moves;


			i= i-1;
			j=j+1;
		}

	}



	return moves;
}
//Versuche alle Felder von Oben nach unten und links nach recht bis das Spiel zuende ist
int BruteForce(TCPclient c){

	string msg;
	int moves=0;


		
			 for(int x =1; x <= 10 ; x++){
			 	for(int y =1 ; y<= 10 ; y++){

			msg = shootPos(x, y, c);
			moves++;


					if(msg.compare(0,8,"GameOver")==0)return moves;


				}
			}
		
		return moves;

}


