#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <string>
 #include <iostream>
 #include <unistd.h> //contains various constants
 #include <sstream>
 #include <vector>
#include "SIMPLESOCKET.H"

int BruteForceDiagonal(TCPclient c);
//Versuche alle Felder von Oben nach unten und links nach recht bis das Spiel zuende ist

int BruteForce(TCPclient c);

#endif /* BRUTEFORCE_H */
