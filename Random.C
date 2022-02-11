/*
 *  created on: 01.12.2021
 *      Author: pascalpiel
 */



#include "Random.H"

int RandShoot(TCPclient c){

	string msg;
	int moves=0;
	while(1){
		int x = (rand()%10)+1;
		int y = (rand()%10)+1;

		msg = shootPos (x,y,c);

		moves++;


		if(msg.compare(0,8,"GameOver")==0)goto Part1;


		}

		Part1:

		return moves;
}


/*
 *  added on: 01.12.2021
 *      Author: pascalpiel
 */

int RandShootiS(TCPclient c){

	string msg;
	int moves=0;

	bool brain[10][10];	//Wahrheitswert Matrix mit bereitsgeschossenen Feldern

	//alle Felder der Matrix false setzen
			for(int k = 0; k<10 ;k++){
				for( int l = 0; l<10;l++){
					brain[k][l] = false;
				}
			}


	while(1){

		int x = (rand()%10)+1;
		int y = (rand()%10)+1;

		if(brain[x-1][y-1] == false){ // gleicht ab, ob das Feld bereits beschossen wurde

		msg = shootPos (x,y,c);

		brain[x-1][y-1] = true;// setzt beschossenes Feld auf "true"

		moves++;



		if(msg.compare(0,9,"GameOver")==0)goto Part1;
		}
					
		}

		Part1:
		
		return moves;
}
