#ifndef SPIELFELDVERWALTUNG_H
#define SPIELFELDVERWALTUNG_H

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>

#include "SIMPLESOCKET.H"

using namespace std;

// void restart(TCPclient c)
// {
//     string msg = "RESTART     ";
//     // cout << "client sends:" << msg << endl;
//     c.sendData(msg);
//     msg = c.receive(32);

//     if (msg.compare(0, 9, "RESTARTED") == 0)
//         ; // cout<< "got response:" << msg<<endl;
//     else
//     {
//         cout << "ERROR beim erstellen eines neuen Spieles" << endl;
//     }

// }

    enum Feldstatus
    {
        NICHT_BESCHOSSEN = 0,
        WASSER = 1,
        SCHIFF_GETROFFEN = 2,
        SCHIFF_ZERSTOERT = 3,
        GAMEOVER = 4,
        ERROR = -1
    };

    string shootPos(int x, int y, TCPclient c);

    void restart(TCPclient c);

    class SpielfeldVerwaltung
    {

    protected:
        Feldstatus Spielfeld[100] = {NICHT_BESCHOSSEN};

        int lastX;
        int lastY;
        int lastPos;
        
        int coordsToPosition(int x, int y)
        {
                return ((y-1) * 10) + x-1;
            
            }
    public:

        int PositionToCoordsX(int n);


        int PositionToCoordsY(int n);


        int getFieldstatus(int x, int y);


        int getLastFieldStatus();


        void Statusreport(int x, int y, string m);

        Feldstatus ServerStringToEnum(string msg);


        int searchShipclass();

    };



Feldstatus shootline(int tmpX, int tmpY, int Rx, int Ry, int& moves, TCPclient c, SpielfeldVerwaltung& Feld);


Feldstatus Nachbar (int PosX, int PosY, int& moves, TCPclient c, SpielfeldVerwaltung& Feld);


#endif /* SPIELFELDVERWALTUNG_H*/

