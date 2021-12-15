/*
 *  created on: 01.12.2021
 *      Author: pascalpiel
 */

int RandShoot(TCPclient c){
	stringstream ss;
	string msg;
	int moves=0;
	while(1){
		int x = (rand()%10)+1;
		int y = (rand()%10)+1;

		ss.str("");
		ss <<"KORDSX"<< x << "Y" << y<<"#";
		msg = ss.str();
		cout << "client sends:" << msg << endl;
		c.sendData(msg);
		moves++;
		msg = c.receive(32);
		cout << "got response:" << msg << endl;

		if(msg.compare(0,8,"GameOver")==0)goto Part1;

					//sleep(1);
		}

		Part1:
		//cout << "Moves: "<< moves <<endl;
		return moves;
}


/*
 *  added on: 01.12.2021
 *      Author: pascalpiel
 */

int RandShootiS(TCPclient c){
	stringstream ss;
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
		ss.str("");
		ss <<"KORDSX"<< x << "Y" << y<<"#";
		msg = ss.str();
		cout << "client sends:" << msg << endl;
		c.sendData(msg);
		brain[x-1][y-1] = true;// setzt beschossenes Feld auf "true"

		moves++;
		msg = c.receive(32);
		cout << "got response:" << msg << endl;


		if(msg.compare(0,9,"GameOver")==0)goto Part1;
		}
					//sleep(1);
		}

		Part1:
		//cout << "Moves: "<< moves <<endl;
		return moves;
}
