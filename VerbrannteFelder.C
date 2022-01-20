/*
 * StrategienM.C
 *
 *  Created on: 22.12.2021
 *      Author: pascalpiel
 */



#include "VerbrannteFelder.H""




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


			if (field.getFieldstatus(x , y)==0){

			field.Statusreport(x,y,shootPos(x,y,c));
			moves++;
			}

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




		


 
	return moves;
 }





