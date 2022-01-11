
#include <string>



enum Feldstatus { NICHT_BESCHOSSEN = 0,
	              WASSER = 1 , 
	              SHIFF_GETROFFEN = 2,
	              SHIFF_ZERSTOERT = 3
};



string shootPos(int x, int y,TCPclient c);



class SpielfeldVerwaltung{

 protected:

	Feldstatus Spielfeld [100] = {NICHT_BESCHOSSEN};

	int lastPos;
	
	
	public:

	int getFeldstatus(int n);

	//SpielfeldVerwaltung::SpielfeldVerwaltung (){};


		void Statusreport(int x, int y, string m); 	// speichert ob getroffen wurde oder nicht auf dem Array Spielfeld.

	Feldstatus ServerStringToEnum (string msg);
		
	int searchShipclass ();
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

Quadrantenparameter getQuadrant(int id);




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

 int geteilteSuche (TCPclient c);

int Schiffsuche (TCPclient c);


