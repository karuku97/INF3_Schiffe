/*
 * StrategienM.C
 *
 *  Created on: 22.12.2021
 *      Author: pascalpiel
 */



#include "StrategienM.H"




 int VerbrannteFelder (TCPclient c){


	SpielfeldVerwaltung field;

	 string msg; //Serverantworten
	 int moves=0;//counter fuer Schuesse


		int x=2;
		int y=1;
	

		do {

			

			if (x>10){

				y++;			
				x=(y%2)+1;
				// if (y%2==0){

				// 	x = 2;

				// }

				// if (y%2!=0){

				// 	x = 1;
				
				// }
			}




			field.Statusreport(x,y,shootPos(x,y,c));
			moves++;

			if (field.getLastFieldStatus()==2){

				Nachbar(x,y,moves,c,field);
			}

			x+=2;

			for (int i=0; i<=100; i++){
				
				int n=1;
				int m=1;

				if (field.getLastFieldStatus()==2){

					field.Statusreport(n,m-1, "Water");
					field.Statusreport(n,m+1, "Water");
				}

				if (field.getLastFieldStatus()==3){

					field.Statusreport(n+1,m, "Water");
				}

				n++;

				if (n<10){

					m++;
					n=1;
				}
				

			}


		}while(field.getLastFieldStatus()!=4);




		// int quadrant = 1;
		// Quadrantenparameter q = getQuadrant(quadrant);

		// while (msg.compare("GameOver")!=0){




		// 	for (y=q.ymin; y <= q.ymax; x++){// For Schleife raus und durch if ersezten, while schleife alleine reicht

		// 	 x = q.Xmin;



		// 	//Wenn noch nicht auf das Feld geschossen
		// 		 if(field.getFeldstatus((y*10)+x)==0){
		// 			 //schiesse auf das Feld
		// 			 msg = shootPos(x,y,c);
		// 			 moves++;

		// 			 field.Statusreport(x, y, msg);


		// 			//  //Schiff zerstoeren bei Treffer
		// 			//  if(msg.compare(0,7,"ShipHit")==0){
		// 			// 	 msg = checkNeigbour(x,y,moves,shot,c);
		// 			//  }
		// 			//Wenn Game Over gib die aktuelle Anzahl an Schuessen zurueck
		// 			 //if(msg.compare(0,8,"GameOver")==0)return moves;

		// 		 }
		// 		 //Laufparameter veraendern
		// 		 if (x == 5){

		// 		 x=0;
		// 		 y+=1;
		//          }




		// 	quadrant++;
		// 	q = getQuadrant(quadrant);

		// }



 
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



