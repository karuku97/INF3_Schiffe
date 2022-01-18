#ifndef SPIELFELDVERWALTUNG_H
#define sPIELFELDVERWALTUNG_H

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
    // {
    //     stringstream ss; // stringstream for Massage Protocoll
    //     string msg;      // msg for return massage from server

    //     ss.str("");
    //     ss << "KORDSX" << (x) << "Y" << (y) << "#";
    //     msg = ss.str();
    //     cout << "client sends:" << msg << endl;
    //     c.sendData(msg);
    //     msg = c.receive(32);
    //     cout << "got response:" << msg << endl;
    //     return msg;
    // }
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
        // {
            
        //     int y = n/10;

        //     int x = n-(y*10);
            
        //     return x;


        // }

        int PositionToCoordsY(int n);
        // {
            
        //     int y = n/10;
            
        //     return y;


        // }

        int getFieldstatus(int x, int y);
        // {

        //     return Spielfeld[coordsToPosition(x,y)];
        // }

        int getLastFieldStatus();
        // {

        //     return Spielfeld[coordsToPosition(lastX,lastY)];
        // }

        // SpielfeldVerwaltung::SpielfeldVerwaltung (){};

        void Statusreport(int x, int y, string m);
        // {
        //     lastX = x;
        //     lastY = y;
        //     lastPos = coordsToPosition(x,y);
            

        //     Spielfeld[lastPos] = ServerStringToEnum(m);

        // } // speichert ob getroffen wurde oder nicht auf dem Array Spielfeld.

        Feldstatus ServerStringToEnum(string msg);
        // {
        
        //     if (msg.compare("ShipDestroyed") == 0)
        //     {

        //         return SCHIFF_ZERSTOERT;
        //     }

        //     if (msg.compare("Water") == 0)
        //     {

        //         return WASSER;
        //     }

        //     if (msg.compare("ShipHit") == 0)
        //     {

        //         return SCHIFF_GETROFFEN;
        //     }

        //     if (msg.compare("GameOver") == 0)
        //     {

        //         return GAMEOVER;
        //     }

        //     return ERROR;
        // }

        int searchShipclass();
        // {

        //     int fuenfer = 1;
        //     int vierer = 2;
        //     int dreier = 3;
        //     int zweier = 4;

        //     if (fuenfer != 0)
        //     {

        //         return 5;
        //     }

        //     if (vierer != 0)
        //     {

        //         return 4;
        //     }

        //     if (dreier != 0)
        //     {

        //         return 3;
        //     }

        //     if (zweier != 0)
        //     {

        //         return 2;
        //     }

        //     return -1;
        // }
    };

    // struct Quadrantenparameter
    // {
    //     int Xmin;
    //     int Xmax;
    //     int ymin;
    //     int ymax;
    // } // Q1, Q2, Q3, Q4;

    // Q1 = {0, 4, 0, 4},
    // Q2 = {5, 9, 0, 4},
    // Q3 = {0, 4, 5, 9},
    // Q4 = {5, 9, 5, 9};

    // Quadrantenparameter getQuadrant(int id);
    // {
    //     switch (id)
    //     {
    //     case 1:
    //         return Q1;
    //         break;
    //     case 2:
    //         return Q2;
    //         break;
    //     case 3:
    //         return Q3;
    //         break;
    //     case 4:
    //         return Q4;
    //         break;

    //     default:
    //         return Q1;
    //     }
    // }

Feldstatus shootline(int tmpX, int tmpY, int Rx, int Ry, int& moves, TCPclient c, SpielfeldVerwaltung& Feld);
// {
 

//     do{

//         tmpX+=Rx;
//         tmpY+=Ry;
//          if (tmpX<1 || tmpX>10 || tmpY<1 ||tmpY>10 ){

//                          break;
//          }
//          if (Feld.getFieldstatus(tmpX, tmpY)==0){
        
//                  Feld.Statusreport(tmpX, tmpY, shootPos(tmpX, tmpY, c));
//                  moves++;
//                 }
//                  //sleep(15);

//     }while(Feld.getFieldstatus(tmpX, tmpY)==2);// 2 = enum ShipHit

//     return WASSER;

// }

Feldstatus Nachbar (int PosX, int PosY, int& moves, TCPclient c, SpielfeldVerwaltung& Feld);
// {

   

//     shootline(PosX, PosY, 1, 0, moves, c, Feld );

//     shootline(PosX, PosY, -1, 0, moves, c, Feld  );

//     shootline(PosX, PosY, 0, 1, moves, c, Feld  );

//     shootline(PosX, PosY, 0, -1, moves, c, Feld  );


//     return SCHIFF_ZERSTOERT;
// }

#endif /* SPIELFELDVERWALTUNG_H*/

