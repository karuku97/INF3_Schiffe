
#include "SpielFeldverwaltung.H"


using namespace std;

void restart(TCPclient c){
 	string msg = "RESTART     ";
 	// cout << "client sends:" << msg << endl;
 	c.sendData(msg);
 	msg = c.receive(32);

 	if(msg.compare(0,9,"RESTARTED")==0); // cout<< "got response:" << msg<<endl;
 	else{ cout<< "ERROR beim erstellen eines neuen Spieles"<<endl;
 	}
}


string shootPos(int x, int y, TCPclient c)
    {
        stringstream ss; // stringstream for Massage Protocoll
        string msg;      // msg for return massage from server

        ss.str("");
        ss << "KORDSX" << (x) << "Y" << (y) << "#";
        msg = ss.str();
        // cout << "client sends:" << msg << endl;
        c.sendData(msg);
        msg = c.receive(32);
        // cout << "got response:" << msg << endl;
        return msg;
    }

       
        int SpielfeldVerwaltung::SpielfeldPositionToCoordsX(int n){
            
            int y = n/10;

            int x = n-(y*10);
            
            return x;


        }

        int SpielfeldVerwaltung::SpielfeldPositionToCoordsY(int n){
            
            int y = n/10;
            
            return y;


        }

        int SpielfeldVerwaltung::SchiffePositionToCoordsX(int n){
            
            int y = n/10;

            int x = n-(y*10);
            
            return x;


        }

        int SpielfeldVerwaltung::SchiffePositionToCoordsY(int n){
            
            int y = n/10;
            
            return y;


        }

        int SpielfeldVerwaltung::getFieldstatus(int x, int y)
        {

            return Spielfeld[coordsToPosition(x,y)];
        }

        int SpielfeldVerwaltung::getLastFieldStatus()
        {

            return Spielfeld[coordsToPosition(lastX,lastY)];
        }

        // SpielfeldVerwaltung::SpielfeldVerwaltung (){};

        void SpielfeldVerwaltung::Statusreport(int x, int y, string m)
        {
            lastX = x;
            lastY = y;
            lastPos = coordsToPosition(x,y);
            

            Spielfeld[lastPos] = ServerStringToEnum(m);

        } // speichert ob getroffen wurde oder nicht auf dem Array Spielfeld.

        void SpielfeldVerwaltung::SchiffPosition(int x, int y, string m)
        {

            lastPos = coordsToPosition(x,y);
            

            Schiffe[lastPos] = ServerStringToEnum(m);

        }

        Feldstatus SpielfeldVerwaltung::ServerStringToEnum(string msg)
        {
        
            if (msg.compare("ShipDestroyed") == 0)
            {

                return SCHIFF_ZERSTOERT;
            }

            if (msg.compare("Water") == 0)
            {

                return WASSER;
            }

            if (msg.compare("ShipHit") == 0)
            {

                return SCHIFF_GETROFFEN;
            }

            if (msg.compare("GameOver") == 0)
            {

                return GAMEOVER;
            }

            return ERROR;
        }

        int SpielfeldVerwaltung::searchShipclass()
        {

            int fuenfer = 1;
            int vierer = 2;
            int dreier = 3;
            int zweier = 4;

            if (fuenfer != 0)
            {

                return 5;
            }

            if (vierer != 0)
            {

                return 4;
            }

            if (dreier != 0)
            {

                return 3;
            }

            if (zweier != 0)
            {

                return 2;
            }

            return -1;
        }
   
      

 

Feldstatus shootline(int tmpX, int tmpY, int Rx, int Ry, int& moves, TCPclient c, SpielfeldVerwaltung& Feld){
 

    do{

        // if (Feld.getFieldstatus(tmpX, tmpY)==2){

        //     Feld.SchiffPosition(tmpX, tmpY, "ShipHit");
        // }

        // if (Feld.getFieldstatus(tmpX, tmpY)==3 ){

        //     Feld.SchiffPosition(tmpX, tmpY, "Destroyed");
        // }

        tmpX+=Rx;
        tmpY+=Ry;
         if (tmpX<1 || tmpX>10 || tmpY<1 ||tmpY>10 ){

                         break;
         }
         if (Feld.getFieldstatus(tmpX, tmpY)==0){
        
                 Feld.Statusreport(tmpX, tmpY, shootPos(tmpX, tmpY, c));
                 moves++;
                }
                 //sleep(15);

    }while(Feld.getFieldstatus(tmpX, tmpY)==2);// 2 = enum ShipHit

    return WASSER;

}

Feldstatus Nachbar (int PosX, int PosY, int& moves, TCPclient c, SpielfeldVerwaltung& Feld){

   

    shootline(PosX, PosY, 1, 0, moves, c, Feld );

    shootline(PosX, PosY, -1, 0, moves, c, Feld  );

    shootline(PosX, PosY, 0, 1, moves, c, Feld  );

    shootline(PosX, PosY, 0, -1, moves, c, Feld  );


    return SCHIFF_ZERSTOERT;
}
