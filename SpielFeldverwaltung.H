#ifndef SPIELFELDVERWALTUNG_H
#define SPIELFELDVERWALTUNG_H

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>
#include <algorithm>
#include <array>

#include "SIMPLESOCKET.H"



void restart(TCPclient c);

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

        Feldstatus Schiffe[5] = {NICHT_BESCHOSSEN};

        int lastX;
        int lastY;
        int lastPos;
        
        int coordsToPosition(int x, int y)
        {
                return ((y-1) * 10) + x-1;
            
            }

        // Feldstatus SortSchiffe(Feldstatus *Schiffe){

        //         std::sort(Schiffe, Schiffe + sizeof Schiffe / sizeof Schiffe[0]);

        //         return Schiffe;

        // }
    public:

        int SpielfeldPositionToCoordsX(int n);


        int SpielfeldPositionToCoordsY(int n);


        int SchiffePositionToCoordsX(int n);


        int SchiffePositionToCoordsY(int n);


        int getFieldstatus(int x, int y);


        int getLastFieldStatus();


        void Statusreport(int x, int y, string m);

        void SchiffPosition(int x, int y, string m);

        Feldstatus ServerStringToEnum(string msg);


        int searchShipclass();

    };



Feldstatus shootline(int tmpX, int tmpY, int Rx, int Ry, int& moves, TCPclient c, SpielfeldVerwaltung& Feld);


Feldstatus Nachbar (int PosX, int PosY, int& moves, TCPclient c, SpielfeldVerwaltung& Feld);


#endif /* SPIELFELDVERWALTUNG_H*/

