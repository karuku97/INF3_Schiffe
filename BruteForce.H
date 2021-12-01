int BruteForceDiagonal(TCPclient c){
	stringstream ss;
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

			 ss.str("");
			 ss<<"KORDSX"<<( i+1) << "Y" <<( j+1)<<"#";
			 msg = ss.str();
			 cout << "client sends:" << msg << endl;
			 c.sendData(msg);
			 moves++;
			 msg = c.receive(32);
			 if(msg.compare(0,8,"GameOver")==0)return moves;
			 cout << "got response:" << msg << endl;

			 i=i-1;
			 j= j+1;
			 //sleep(1);
		 }

	}

	for (int k = 1; k<=n-1;k++){
		i=m-1;
		j=k;
		while(j<=n-1){

			ss.str("");
			ss<<"KORDSX"<<( i+1) << "Y" << (j+1)<<"#";
			msg = ss.str();
			cout << "client sends:" << msg << endl;
			c.sendData(msg);
			moves++;
			msg = c.receive(32);
			if(msg.compare(0,8,"GameOver")==0)return moves;
			cout << "got response:" << msg << endl;

			i= i-1;
			j=j+1;
		}

	}



	return moves;
}
//Versuche alle Felder von Oben nach unten und links nach recht bis das Spiel zuende ist
int BruteForce(TCPclient c){
	stringstream ss;
	string msg;
	int moves=0;

		while(1){ // funktioniert nicht
			for(int x =1; x <= 10 ; x++){
				for(int y =1 ; y<= 10 ; y++){
					ss.str("");
					ss <<"KORDSX"<< x << "Y" << y<<"#";
					msg = ss.str();
					cout << "client sends:" << msg << endl;
					c.sendData(msg);
					moves++;
					msg = c.receive(32);
					cout << "got response:" << msg << endl;

					if(msg.compare(0,8,"GameOver")==0)return moves;

					//sleep(1);
				}
			}
		}
		return moves;

}
