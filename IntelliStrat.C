#include "IntelliStrat.H"
#include "SpielfeldVerwaltung.H"
#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>

#include "SIMPLESOCKET.H"

using namespace std;


//Inteligente Strategie (verlauf: Horizontal/Vertikal)
int IntelliStrat(TCPclient c){

	string msg;
	int moves=0; //counter fuer Schuesse
	int slep = 0;//Debug Timer
	bool shot[10][10];	//Wahrheitswert Matrix mit bereitsgeschossenen Feldern

	//alle Felder der Matrix false setzen
	for(int i = 0 ; i<10 ; i++){
			for( int j = 0 ; j<10 ;j++){
				shot[i][j] = false;
			}
	}

	//Durchlaufe das Spielfeld von unten nach oben und links nach rechts
	for(int i = 1 ; i<=10 ; i++){
		for( int j = 1 ; j<=10 ;j++){

			//Wenn noch nicht auf das Feld geschossen wurde..
			if(!shot[j-1][i-1]){
				//schieße auf das Feld
				msg = shoot(i,j,c);
				moves++;		//addiere den schuss zum counter
				shot[j-1][i-1] = true;	//makiere das Feld als geschossen

				//Debug
				sleep(slep);

				//Shiff zerstoeren wenn ein teffer Vorliegt
				if(msg.compare(0,7,"ShipHit")==0){
					neigbour(i,j,moves,shot,c);

				}
				//Wenn Game Over dann die derzeitige Anzahl der Schuesse zurueck geben
				if(msg.compare(0,8,"GameOver")==0){return moves;}

				//sleep(slep);
			}




		}
	}
	return moves;

}

int IntelliStratDiagonal(TCPclient c){
		string msg; //Serverantworten
		int moves=0;//counter fuer Schuesse
		bool shot[10][10];	//Wahrheitswert Matrix mit bereitsgeschossenen Feldern
		int slep = 0; //Debug parameter

		//zeilen und Spalten
		int m = 10;
		int n= 10;

		//laufparameter (Koordinaten)
		int i;
		int j;

		//alle Felder der Matrix false setzen
		for(int k = 0; k<10 ;k++){
			for( int l = 0; l<10;l++){
				shot[k][l] = false;
			}
		}

		//fuer jede zweite Dagonale (erste haelfte)
		for (int k=0;k<=m-1;k = k+2){
			 i = k;
			 j = 0;
			 while(i>=0){

				 //Wenn noch nicht auf das Feld geschossen
				 if(!shot[j][i]){
					 //schiesse auf das Feld
					 msg = shoot(i+1,j+1,c);
					 moves++;
					 shot[j][i] = true;


					 //Schiff zerstoeren bei Treffer
					 if(msg.compare(0,7,"ShipHit")==0){
						 msg = neigbour(i+1,j+1,moves,shot,c);
					 }
					 //Wenn Game Over gib die aktuelle Anzahl an Schuessen zurueck
					 if(msg.compare(0,8,"GameOver")==0)return moves;

				 }
				 //Laufparameter veraendern
				 i=i-1;
				 j= j+1;

				 //Debug
				 sleep(slep);

			 }

		}
		//fuer jede zweite Dagonale (zweite haelfte)
		for (int k = 1; k<=n-1;k = k+2){
			i=m-1;
			j=k;
			while(j<=n-1){

				//Wenn noch nicht auf das Feld geschossen
				if(!shot[j][i]){
					msg = shoot(i+1,j+1,c);
					moves++;
					shot[j][i] = true;

					//Schiff zerstoeren bei Treffer
					if(msg.compare(0,7,"ShipHit")==0){
						msg = neigbour(i+1,j+1,moves,shot,c);
					}
					//Wenn Game Over gib die aktuelle Anzahl an Schuessen zurueck
					if(msg.compare(0,8,"GameOver")==0){return moves;}
				}
				//Laufparameter veraendern
				i= i-1;
				j=j+1;

				//Debug
				sleep(slep);
			}

		}
		return moves;
}