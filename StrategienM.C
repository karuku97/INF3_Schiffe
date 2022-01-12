/*
 * StrategienM.C
 *
 *  Created on: 22.12.2021
 *      Author: pascalpiel
 */


#include <string>
#include "StrategienM.H"


//Testkommentar

enum Feldstatus { NICHT_BESCHOSSEN = 0,
	              WASSER = 1 ,
	              SHIFF_GETROFFEN = 2,
	              SHIFF_ZERSTOERT = 3
};



string shootPos(int x, int y,TCPclient c){
	stringstream ss;	//stringstream for Massage Protocoll
	string msg;			// msg for return massage from server

	ss.str("");
	ss<<"KORDSX"<<( x) << "Y" <<( y)<<"#";
	msg = ss.str();
	cout << "client sends:" << msg << endl;
	c.sendData(msg);
	msg = c.receive(32);
	cout << "got response:" << msg << endl;
	return msg;
 }
 class SpielfeldVerwaltung{

 protected:

	Feldstatus Spielfeld [100] = {NICHT_BESCHOSSEN};

	int lastPos;


	public:

	int getFeldstatus(int n){

	return Spielfeld[n];

	}

	//SpielfeldVerwaltung::SpielfeldVerwaltung (){};


		void Statusreport(int x, int y, string m){

		int pos = (y*10)+x;
		lastPos = pos;


			Spielfeld[pos] = ServerStringToEnum(m);


	 } 	// speichert ob getroffen wurde oder nicht auf dem Array Spielfeld.

	Feldstatus ServerStringToEnum (string msg){

        if (msg.compare("ShipDestroyed") == 0){

			return SHIFF_ZERSTOERT;

		}

		 if (msg.compare("Water") == 0){

			return WASSER;

		}

		 if (msg.compare("ShipHit") == 0){

			return SHIFF_GETROFFEN;

		}
		//Switch case draus machen
	}

	int searchShipclass (){


		int fuenfer = 1;
		int vierer = 2;
		int dreier = 3;
		int zweier = 4;

		if (fuenfer !=0 ){

			return 5;
		}

		if (vierer !=0 ){

			return 4;
		}

		if (dreier !=0 ){

			return 3;
		}

		if (zweier !=0 ){

			return 2;
		}

		return -1;
 	}
 };

 struct Quadrantenparameter
	{
		int Xmin;
		int Xmax;
		int ymin;
		int ymax;
	}//Q1, Q2, Q3, Q4;

	Q1 = {0, 4, 0, 4},
	Q2 = {5, 9, 0, 4},
	Q3 = {0, 4, 5, 9},
	Q4 = {5, 9, 5, 9};

Quadrantenparameter getQuadrant(int id){
	switch(id){
		case 1:
			return Q1;
		break;
		case 2:
			return Q2;
		break;
		case 3:
			return Q3;
		break;
		case 4:
			return Q4;
		break;

		default:
		return Q1;
	}

}




// //nach getroffenen Ziel alle Nachbar Punkte überprüfen und Schiff zerstören
//  //nach getroffenen Ziel alle Nachbar Punkte überprüfen und Schiff zerstören
// string neighbour(int i , int j , int& moves, bool shot[10][10], TCPclient c){

// 	SpielfeldVerwaltung nextdoor;

// 	int slep = 0; 				//slep fuer Debug
// 	string msg ;				//msg fuer Server Antwort
// 	pair<int,int> cords;		//Koordinaten von einem Punkt des Schiffes
// 	vector <pair<int,int>> ship;//Schiff als Vektor von mehreren Punkten
// 	int tmpi,tmpj;				//temporaere Koordinaten

// 		//ersten getroffenen Punkt in Vektor schreiben
// 		cords.first = j-1;
// 		cords.second = i-1;
// 		ship.push_back(cords);


// 		tmpi = i;
// 		tmpj = j;
// 		//nach rechts suchen solang getroffen wird
// 		do{
// 			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach rechts
// 			if((tmpi+1)>0&&(tmpi+1)<=10){tmpi++;}else{break;}

// 			//Wenn auf diese Koordnate noch nicht geschossen wurde
// 			if(nextdoor.getFeldstatus((j*10)+i)==0){

// 				//auf Koordinate schießen
// 				msg = shoot(tmpi,tmpj,c);
// 				moves++;

// 				nextdoor.Statusreport(i, j, msg);

// 				//Wenn koodinate getroffen dann zum Schiff hinzufuegen
// 				if(msg.compare(0,7,"ShipHit")==0){
// 					cords.first = tmpj-1;
// 					cords.second = tmpi-1;
// 					ship.push_back(cords);
// 				}
// 				//wenn schiff zerstört
// 				if(msg.compare(0,13,"ShipDestroyed")==0)markShip(ship,shot);

// 				//Debug
// 				sleep(slep);
// 			}
// 		}while(msg.compare(0,7,"ShipHit")==0);



// 		tmpi = i;
// 		tmpj = j;
// 		//nach links suchen solang getroffen wird
// 		do{
// 			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach links
// 			if((tmpi-1)>0&&(tmpi-1)<=10){tmpi--;}else{break;}

// 			//Wenn auf diese Koordnate noch nicht geschossen wurde
// 			if(!shot[tmpj-1][tmpi-1]){
// 				//auf Koordinate schießen
// 				msg = shoot(tmpi,tmpj,c);
// 				moves++;
// 				nextdoor.Statusreport(i, j, msg);

// 				//Wenn koodinate getroffen dann zum Schiff hinzufuegen
// 				if(msg.compare(0,7,"ShipHit")==0){
// 					cords.first = tmpj-1;
// 					cords.second = tmpi-1;
// 					ship.push_back(cords);
// 				}
// 				//wenn schiff zerstört
// 				if(msg.compare(0,13,"ShipDestroyed")==0)markShip(ship,shot);

// 				//Debug
// 				sleep(slep);
// 			}
// 		}while(msg.compare(0,7,"ShipHit")==0);



// 		tmpi = i;
// 		tmpj = j;
// 		//nach unten suchen solang getroffen wird
// 		do{
// 			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach unten
// 			if((tmpj+1)>0&&(tmpj+1)<=10){tmpj++;}else{break;}

// 			//Wenn auf diese Koordnate noch nicht geschossen wurde
// 			if(nextdoor.getFeldstatus((j*10)+i)==0){
// 				msg = shoot(tmpi,tmpj,c);
// 				moves++;
// 				nextdoor.Statusreport(i, j, msg);

// 				//Wenn koodinate getroffen dann zum Schiff hinzufuegen
// 				if(msg.compare(0,7,"ShipHit")==0){
// 					cords.first = tmpj-1;
// 					cords.second = tmpi-1;
// 					ship.push_back(cords);
// 				}

// 				//wenn schiff zerstört
// 				if(msg.compare(0,13,"ShipDestroyed")==0)markShip(ship,shot);

// 				//Debug
// 				sleep(slep);
// 			}
// 		}while(msg.compare(0,7,"ShipHit")==0);


// 		tmpi = i;
// 		tmpj = j;
// 		//nach oben suchen solang getroffen wird
// 		do{
// 			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach oben
// 			if((tmpj-1)>0&&(tmpj-1)<=10){tmpj--;}else{break;}

// 			//Wenn auf diese Koordnate noch nicht geschossen wurde
// 			if(nextdoor.getFeldstatus((j*10)+i)==0){
// 				msg = shoot(tmpi,tmpj,c);
// 				moves++;
// 				shot[tmpj-1][tmpi-1] = true;

// 				//Wenn koodinate getroffen dann zum Schiff hinzufuegen
// 				if(msg.compare(0,7,"ShipHit")==0){
// 					cords.first = tmpj-1;
// 					cords.second = tmpi-1;
// 					ship.push_back(cords);
// 				}

// 				//wenn schiff zerstört
// 				if(msg.compare(0,13,"ShipDestroyed")==0)markShip(ship,shot);

// 				//Debug
// 				sleep(slep);
// 			}
// 		}while(msg.compare(0,7,"ShipHit")==0);



// 	//Serverantwort zuruek geben
// 	return msg;
// }

 int geteilteSuche (TCPclient c){


	SpielfeldVerwaltung field;

	 string msg; //Serverantworten
	 int moves=0;//counter fuer Schuesse


		int x;
		int y;


		int quadrant = 1;
		Quadrantenparameter q = getQuadrant(quadrant);

		while (msg.compare("GameOver")!=0){




			for (y=q.ymin; y <= q.ymax; x++){// For Schleife raus und durch if ersezten, while schleife alleine reicht

			 x = q.Xmin;



			//Wenn noch nicht auf das Feld geschossen
				 if(field.getFeldstatus((y*10)+x)==0){
					 //schiesse auf das Feld
					 msg = shootPos(x,y,c);
					 moves++;

					 field.Statusreport(x, y, msg);


					//  //Schiff zerstoeren bei Treffer
					//  if(msg.compare(0,7,"ShipHit")==0){
					// 	 msg = checkNeigbour(x,y,moves,shot,c);
					//  }
					//Wenn Game Over gib die aktuelle Anzahl an Schuessen zurueck
					 //if(msg.compare(0,8,"GameOver")==0)return moves;

				 }
				 //Laufparameter veraendern
				 if (x == 5){

				 x=0;
				 y+=1;
		         }




			quadrant++;
			q = getQuadrant(quadrant);

		}



 }
	return moves;
 }








int Schiffsuche (TCPclient c){

	SpielfeldVerwaltung Feld;

 string msg; //Serverantworten
	 int moves=0;//counter fuer Schuesse


		int x = 0;
		int y = 0;

		int Schifftyp = Feld.searchShipclass();

		while (msg.compare("GameOver")!=0){

			for (x;y<=9;x+=Schifftyp){// For Schleife raus und durch if ersezten, while schleife alleine reicht

				if (x > 9){

				 x=0;
				 y+=1;
		         }

				//Wenn noch nicht auf das Feld geschossen
				 //if(Feld.getFeldstatus((y*10)+x)==0){
					 //schiesse auf das Feld
					 msg = shootPos(x,y,c);
					 moves++;

					 Feld.Statusreport(x, y, msg);


					//  //Schiff zerstoeren bei Treffer
					//  if(msg.compare(0,7,"ShipHit")==0){
					// 	 msg = checkNeigbour(x,y,moves,shot,c);
					//  }
					//  //Wenn Game Over gib die aktuelle Anzahl an Schuessen zurueck
					//  if(msg.compare(0,8,"GameOver")==0)return moves;

				 //}
				 //Laufparameter veraendern

				 // Wenn  Schiff eines Typen zerstört worden ist, speicherung in Varibale und erneute Abfrage nach Schifftyp



			}


		}



	return moves;

 }



