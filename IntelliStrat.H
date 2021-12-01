string shoot(int x, int y,TCPclient c){
	stringstream ss;	//stringstream for Massage Protocoll
	string msg;			// msg for return massage from server

	//stringstream schreiben
	ss.str("");
	ss<<"KORDSX"<<( x) << "Y" <<( y)<<"#";
	msg = ss.str();
	//string stream an Server senden
	cout << "client sends:" << msg << endl;
	c.sendData(msg);

	//Server Antwort in msg speichern und zurueck geben
	msg = c.receive(32);
	cout << "got response:" << msg << endl;
	return msg;
}
//Makiert ein Schiff unf alle umliegenden Felder in Matrix
void markShip(vector<pair<int,int>> ship, bool shot[10][10]){
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


//nach getroffenen Ziel alle Nachbar Punkte überprüfen und Schiff zerstören
string neigbour(int i , int j , int& moves, bool shot[10][10], TCPclient c){

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
			if(!shot[tmpj-1][tmpi-1]){

				//auf Koordinate schießen
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



		tmpi = i;
		tmpj = j;
		//nach unten suchen solang getroffen wird
		do{
			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach unten
			if((tmpj+1)>0&&(tmpj+1)<=10){tmpj++;}else{break;}

			//Wenn auf diese Koordnate noch nicht geschossen wurde
			if(!shot[tmpj-1][tmpi-1]){
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


		tmpi = i;
		tmpj = j;
		//nach oben suchen solang getroffen wird
		do{
			//ueberpruefen ob Koordniate im Spielfeld liegt sonst abbruch nach oben
			if((tmpj-1)>0&&(tmpj-1)<=10){tmpj--;}else{break;}

			//Wenn auf diese Koordnate noch nicht geschossen wurde
			if(!shot[tmpj-1][tmpi-1]){
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
//Inteligente Strategie (verlauf: jede zweite Diagonale)
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

