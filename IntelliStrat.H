#ifndef INTELLISTRAT_H
#define INTELLISTRAT_H


#include <string>
 #include <iostream>
 #include <unistd.h> //contains various constants
 #include <sstream>
 #include <vector>
#include "SIMPLESOCKET.H"



string shoot(int x, int y,TCPclient c);


//Makiert ein Schiff unf alle umliegenden Felder in Matrix
void markShip(vector<pair<int,int>> ship, bool shot[10][10]);


//nach getroffenen Ziel alle Nachbar Punkte überprüfen und Schiff zerstören
string neigbour(int i , int j , int& moves, bool shot[10][10], TCPclient c);

//Inteligente Strategie (verlauf: Horizontal/Vertikal)
int IntelliStrat(TCPclient c);


//Inteligente Strategie (verlauf: jede zweite Diagonale)
int IntelliStratDiagonal(TCPclient c);

#endif /*   INTELLISTRAT_H*/