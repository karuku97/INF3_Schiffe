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

		if(msg.compare(0,9,"Game Over")==0)goto Part1;

					//sleep(1);
		}

		Part1:
		//cout << "Moves: "<< moves <<endl;
		return moves;
}
