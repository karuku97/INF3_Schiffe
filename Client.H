
#include"Client.C"


void restart(TCPclient c){
	string msg = "RESTART     ";
	// cout << "client sends:" << msg << endl;
	c.sendData(msg);
	msg = c.receive(32);

	if(msg.compare(0,9,"RESTARTED")==0); // cout<< "got response:" << msg<<endl;
	else{ cout<< "ERROR beim erstellen eines neuen Spieles"<<endl;
	}
}

int main(int argc, const char **argv);
