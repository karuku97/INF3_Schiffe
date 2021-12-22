#ifndef SPIELFELDVERWALTUNG_H
#define SPIELFELDVERWALTUNG_H


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

    void Statusreport(int x, int y, string m);

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

    string neighbour(int i , int j , int& moves, bool shot[10][10], TCPclient c);

    void markShip(vector<pair<int,int>> ship, bool shot[10][10]);

    #endif /* SPIELFELDVERWALTUNG_H */