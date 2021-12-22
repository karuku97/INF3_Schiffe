#include "SpielfeldVerwaltung.H"
#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>

#include "SIMPLESOCKET.H"

using namespace std;



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

int SpielfeldVerwaltung::getFeldstatus(int n){

    return Spielfeld[n];
}

void SpielfeldVerwaltung::Statusreport(int x, int y, string m){

    int pos = (y*10)+x;
		lastPos = pos;
		

			Spielfeld[pos] = ServerStringToEnum(m);
}

Feldstatus SpielfeldVerwaltung::ServerStringToEnum (string msg){

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

int SpielfeldVerwaltung::searchShipclass (){


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

string neighbour(int i , int j , int& moves, bool shot[10][10], TCPclient c);

	SpielfeldVerwaltung nextdoor;

	int slep = 0; 				//slep fuer Debug
	string msg ;				//msg fuer Server Antwort
	pair<int,int> cords;		//Koordinaten von einem Punkt des Schiffes
	vector <pair<int,int>> ship;//Schiff als Vektor von mehreren Punkten
	int tmpi,tmpj;				//temporaere Koordinaten

		//ersten getroffenen Punkt in Vektor schreiben
		cords.first = j-1;
		cords.second = i-1;
		ship.push_back(cords);


		tmpi = i;
		tmpj = j;
		//nach rechts suchen solang getroffen wird
		do{
			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach rechts
			if((tmpi+1)>0&&(tmpi+1)<=10){tmpi++;}else{break;}

			//Wenn auf diese Koordnate noch nicht geschossen wurde
			if(nextdoor.getFeldstatus((j*10)+i)==0){

				//auf Koordinate schießen
				msg = shoot(tmpi,tmpj,c);
				moves++;
				
				nextdoor.Statusreport(i, j, msg);

				//Wenn koodinate getroffen dann zum Schiff hinzufuegen
				if(msg.compare(0,7,"ShipHit")==0){
					cords.first = tmpj-1;
					cords.second = tmpi-1;
					ship.push_back(cords);
				}
				//wenn schiff zerstört
				if(msg.compare(0,13,"ShipDestroyed")==0)markShip(ship,shot);

				//Debug
				sleep(slep);
			}
		}while(msg.compare(0,7,"ShipHit")==0);



		tmpi = i;
		tmpj = j;
		//nach links suchen solang getroffen wird
		do{
			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach links
			if((tmpi-1)>0&&(tmpi-1)<=10){tmpi--;}else{break;}

			//Wenn auf diese Koordnate noch nicht geschossen wurde
			if(!shot[tmpj-1][tmpi-1]){
				//auf Koordinate schießen
				msg = shoot(tmpi,tmpj,c);
				moves++;
				nextdoor.Statusreport(i, j, msg);

				//Wenn koodinate getroffen dann zum Schiff hinzufuegen
				if(msg.compare(0,7,"ShipHit")==0){
					cords.first = tmpj-1;
					cords.second = tmpi-1;
					ship.push_back(cords);
				}
				//wenn schiff zerstört
				if(msg.compare(0,13,"ShipDestroyed")==0)markShip(ship,shot);

				//Debug
				sleep(slep);
			}
		}while(msg.compare(0,7,"ShipHit")==0);



		tmpi = i;
		tmpj = j;
		//nach unten suchen solang getroffen wird
		do{
			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach unten
			if((tmpj+1)>0&&(tmpj+1)<=10){tmpj++;}else{break;}

			//Wenn auf diese Koordnate noch nicht geschossen wurde
			if(nextdoor.getFeldstatus((j*10)+i)==0){
				msg = shoot(tmpi,tmpj,c);
				moves++;
				nextdoor.Statusreport(i, j, msg);

				//Wenn koodinate getroffen dann zum Schiff hinzufuegen
				if(msg.compare(0,7,"ShipHit")==0){
					cords.first = tmpj-1;
					cords.second = tmpi-1;
					ship.push_back(cords);
				}

				//wenn schiff zerstört
				if(msg.compare(0,13,"ShipDestroyed")==0)markShip(ship,shot);

				//Debug
				sleep(slep);
			}
		}while(msg.compare(0,7,"ShipHit")==0);


		tmpi = i;
		tmpj = j;
		//nach oben suchen solang getroffen wird
		do{
			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach oben
			if((tmpj-1)>0&&(tmpj-1)<=10){tmpj--;}else{break;}

			//Wenn auf diese Koordnate noch nicht geschossen wurde
			if(nextdoor.getFeldstatus((j*10)+i)==0){
				msg = shoot(tmpi,tmpj,c);
				moves++;
				shot[tmpj-1][tmpi-1] = true;

				//Wenn koodinate getroffen dann zum Schiff hinzufuegen
				if(msg.compare(0,7,"ShipHit")==0){
					cords.first = tmpj-1;
					cords.second = tmpi-1;
					ship.push_back(cords);
				}

				//wenn schiff zerstört
				if(msg.compare(0,13,"ShipDestroyed")==0)markShip(ship,shot);

				//Debug
				sleep(slep);
			}
		}while(msg.compare(0,7,"ShipHit")==0);



	//Serverantwort zuruek geben
	return msg;
}
void markShip(vector<pair<int,int>> ship, bool shot[10][10]);{

 pair<int,int> cords;
	//Das zerstoerte Schiff und umliegende Felder als bereits geschossen makieren
			//Koordinate laden
			for(int k = 0; k<ship.size();k++){
				cords = ship.at(k);
				//NachbarFelder makieren
				for(int l = (cords.first-1); l<=(cords.first+1);l++){
					for(int o = (cords.second-1); o<=(cords.second+1);o++){
						//ueberpruefen ob Nachbarfeld innerhalb des Spielfeldes ist
						if(l>=0&&l<=9&&o>=0&&o<=9){
							shot[l][o]=true;

						}
					}

				}
			}
			ship.clear();

}