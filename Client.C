/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>

#include "SIMPLESOCKET.H"

using namespace std;

int BruteForce(TCPclient c);
void restart(TCPclient c);
int BruteForceDiagonal(TCPclient c);
int intelliSearch(TCPclient c);
string shoot(int x , int y, TCPclient c);

int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";


	//connect to host
	c.conn(host , 2020);

	cout<<endl << "Moves: " <<intelliSearch(c)<<endl;;

	//cout<<"Moves: "<<BruteForceDiagonal(c)<<endl;;

	/*
	int anz = 10;
	double movesAvg = 0.0;

	for(int i = 0; i< anz;i++){
		if(i==0){
			movesAvg = BruteForce(c);
			restart(c);
		}
		else{
			movesAvg = (movesAvg+BruteForce(c)) /2;
			restart(c);
		}
	}


	cout<<endl<< "----------"<<endl<< "AvarageMoves(BruteForce): "<< movesAvg<<endl<<"-----------"<<endl;


*/
}
string shoot(int x, int y,TCPclient c){
	stringstream ss;
	string msg;

	ss.str("");
	ss<<"KORDSX"<<( x) << "Y" <<( y)<<"#";
	msg = ss.str();
	cout << "client sends:" << msg << endl;
	c.sendData(msg);
	msg = c.receive(32);
	cout << "got response:" << msg << endl;
	return msg;
}

int intelliSearch(TCPclient c){
	stringstream ss;
	string msg;
	int moves=0;
	int tmpi,tmpj;
	vector<pair<int,int>> ship;
	pair<int, int> cords;
	ship.clear();
	int slep = 0;


	bool shot[10][10];
	//alle false setzen
	for(int i = 0 ; i<10 ; i++){
			for( int j = 0 ; j<10 ;j++){
				shot[i][j] = false;
			}
	}


	for(int i = 1 ; i<=10 ; i++){
		for( int j = 1 ; j<=10 ;j++){




				cout<<endl;
				if(!shot[j-1][i-1]){


				msg = shoot(i,j,c);
				moves++;
				shot[j-1][i-1] = true;

				sleep(slep);


				if(msg.compare(0,8,"Ship Hit")==0){
					cords.first = j-1;
					cords.second = i-1;
					ship.push_back(cords);
					//nach rechts
						 tmpi = i;
						 tmpj = j;

					do{
						if((tmpi+1)>0&&(tmpi+1)<=10){tmpi++;}else{break;}

						if(!shot[tmpj-1][tmpi-1]){
							msg = shoot(tmpi,tmpj,c);
							moves++;
							shot[tmpj-1][tmpi-1] = true;
							if(msg.compare(0,8,"Ship Hit")==0){
								cords.first = tmpj-1;
								cords.second = tmpi-1;
								ship.push_back(cords);
							}
							cout<<endl<<"rechts"<<endl;
							if(msg.compare(0,14,"Ship Destroyed")==0)goto Part2;
							sleep(slep);
						}
					}while(msg.compare(0,8,"Ship Hit")==0);

					//nach links

						 tmpi = i;
						 tmpj = j;
					do{

						if((tmpi-1)>0&&(tmpi-1)<=10){tmpi--;}else{break;}
						if(!shot[tmpj-1][tmpi-1]){
							msg = shoot(tmpi,tmpj,c);
							moves++;
							shot[tmpj-1][tmpi-1] = true;
							if(msg.compare(0,8,"Ship Hit")==0){
								cords.first = tmpj-1;
								cords.second = tmpi-1;
								ship.push_back(cords);
							}
							cout<<endl<<"links"<<endl;
							if(msg.compare(0,14,"Ship Destroyed")==0)goto Part2;
							sleep(slep);
						}
					}while(msg.compare(0,8,"Ship Hit")==0);

					//nach unten

						 tmpi = i;
						 tmpj = j;
					do{

						if((tmpj+1)>0&&(tmpj+1)<=10){tmpj++;}else{break;}
						if(!shot[tmpj-1][tmpi-1]){
							msg = shoot(tmpi,tmpj,c);
							moves++;
							shot[tmpj-1][tmpi-1] = true;
							if(msg.compare(0,8,"Ship Hit")==0){
								cords.first = tmpj-1;
								cords.second = tmpi-1;
								ship.push_back(cords);
							}
							cout<<endl<<"unten"<<endl;
							if(msg.compare(0,14,"Ship Destroyed")==0)goto Part2;
							sleep(slep);
						}
					}while(msg.compare(0,8,"Ship Hit")==0);

					//nach oben
						 tmpi = i;
						 tmpj = j;
					do{

						if((tmpj-1)>0&&(tmpj-1)<=10){tmpj--;}else{break;}

						if(!shot[tmpj-1][tmpi-1]){
							msg = shoot(tmpi,tmpj,c);
							moves++;
							shot[tmpj-1][tmpi-1] = true;
							if(msg.compare(0,8,"Ship Hit")==0){
								cords.first = tmpj-1;
								cords.second = tmpi-1;
								ship.push_back(cords);
							}
							cout<<endl<<"oben"<<endl;
							if(msg.compare(0,14,"Ship Destroyed")==0)goto Part2;
							sleep(slep);
						}
					}while(msg.compare(0,8,"Ship Hit")==0);
				Part2:
				//cout<<endl<<endl<<"-------"<<endl<<ship.size()<<endl<<"-------"<<endl;
					for(int k = 0; k<ship.size();k++){
						cords = ship.at(k);
						//cout << endl<< "KORDS: X" << cords.first<<"Y: " <<cords.second<<endl;
						for(int l = (cords.first-1); l<=(cords.first+1);l++){
							for(int o = (cords.second-1); o<=(cords.second+1);o++){
								//cout<<"l:"<<l <<"o: "<<o << endl;
								if(l>=0&&l<=9&&o>=0&&o<=9){
									shot[l][o]=true;
									//cout<< endl<< "kordsweg: "<< l << ", "<< o <<endl;

								}
							}

						}
					}
					ship.clear();

				}
				if(msg.compare(0,9,"Game Over")==0)goto Part1;
				cout << "got response:" << msg << endl;
				//sleep(slep);
			}




		}
	}







Part1:
	/*for(int i = 0 ; i<10 ; i++){
			for( int j = 0 ; j<10 ;j++){
				cout<<shot[i][j] ;
			}
			cout<<endl;
	}*/

	return moves;
}


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
			 if(msg.compare(0,9,"Game Over")==0)goto Part1;
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
			if(msg.compare(0,9,"Game Over")==0)goto Part1;
			cout << "got response:" << msg << endl;

			i= i-1;
			j=j+1;
		}

	}
	Part1:


	return moves;
}

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

					if(msg.compare(0,9,"Game Over")==0)goto Part1;

					//sleep(1);
				}
			}
		}

		Part1:
		//cout << "Moves: "<< moves <<endl;
		return moves;
}

void restart(TCPclient c){
	c.sendData("RESTART    ");
	if(c.receive(32).compare(0,9,"RESTARTED")==0) cout<< "neues Spiel!"<<endl;
	else{ cout<< "ERROR beim erstellen eines neuen Spieles"<<endl;

	}
}

