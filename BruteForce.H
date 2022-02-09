/*
 * BruteForce.C
 *
 *  Created on: 22.12.2021
 *      Author: kkuckelsberg
 */

/**
 *
 * \file BruteForce.H
 *
 * \brief contains two Brute Force strategies.
 */
#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <string>
 #include <iostream>
 #include <unistd.h> //contains various constants
 #include <sstream>
 #include <vector>
#include "SIMPLESOCKET.H"
#include "SpielFeldverwaltung.H"



/**
  *
  * \brief The strategie shoots on every diagonal line. Until the Game returnes "GameOver"
  *
  *	\param TCPclient c, client Object
  *
  * \return int how many shoots the stategie had done.
  *
  */
int BruteForceDiagonal(TCPclient c);


/**
  *
  * \brief The strategie shoots on every row and collum. Until the Game returnes "GameOver"
  *
  *
  *	\param TCPclient c, client Object
  *
  * \return int how many shoots the stategie had done.
  *
  */
int BruteForce(TCPclient c);

#endif /* BRUTEFORCE_H */
