/*
 * IntelliStrat.H
 *
 *  Created on: 22.12.2021
 *      Author: kkuckelsberg
 */

/**
 *
 * \file IntelliStrat.H
 *
 * \brief contains two intelligent strategies.
 */

#ifndef INTELLISTRAT_H
#define INTELLISTRAT_H


#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>
#include "SIMPLESOCKET.H"


/**
  *
  * \brief The function shoot, talks to the Server and shoots on the gameboard
  *
  *	\param int x, x position
  *
  *	\param int y, y position
  *
  *	\param bool shoot[10][10] 2D Array of the aleready marked positions
  *
  *	\param TCPclient c, client object
  *
  */
string shoot(int x, int y,TCPclient c);


/**
  *
  * \brief The function marks the destroyed ship and the neigbour cells.
  *
  *	\param vector<pair> ship, the destroyed ship, saved as Vector of a pair with the x and y positions of the ship.
  *
  *	\param bool shoot[10][10] 2D Array of the aleready marked positions
  *
  *
  *
  */
void markShip(vector<pair<int,int>> ship, bool shot[10][10]);


/**
  *
  * \brief The neigbour function shoots on every neigbour cell until the ship is destroyed. After that it calls the markShip Function.
  *
  *	\param int i, x Poition of the first hit
  *
  *	\param int j, y Poition of the first hit
  *
  *	\param int& moves reference of the shot counter variable
  *
  *	\param bool shoot[10][10] 2D Array of the aleready marked positions
  *
  *	\param TCPclient c, client object
  *
  * \return string last return Value from Server
  *
  */
string neigbour(int i , int j , int& moves, bool shot[10][10], TCPclient c);

/**
  *
  * \brief The strategie will shoots on every row and collum, if the Position is not marked. Until the Game returnes "GameOver". It marks the positions already shot. If it hit a target, it will call the neigbour Function.
  *
  *	\param TCPclient c, client Object
  *
  * \return int How many shoots the stategie had done.
  *
  */
int IntelliStrat(TCPclient c);


/**
  *
  * \brief The strategie will shoots on every diagonal line, if the Position is not marked. Until the Game returnes "GameOver". It marks the positions already shot. If it hit a target, it will call the neigbour Function.
  *
  *	\param TCPclient c, client Object
  *
  * \return int How many shoots the stategie had done.
  *
  */
int IntelliStratDiagonal(TCPclient c);

#endif /*   INTELLISTRAT_H*/
