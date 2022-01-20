/*
 *  created on: 01.12.2021
 *      Author: pascalpiel
 */

/**
 *
 * \file Random.H
 *
 * \brief contains the declarations of the two random strategies.
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <sstream>
#include <vector>
#include "SIMPLESOCKET.H"
#include "SpielFeldverwaltung.H"


 /**
  *
  * \brief The strategy shoots with the rand()-function on the world. The coordinates are generated
  * in the function. The shoots are not saved, so that one field can be shoot more than once whitout
  * a limit.
  *
  */
int RandShoot(TCPclient c);

/*
 *  added on: 01.12.2021
 *      Author: pascalpiel
 */

/**
 *
 * \brief The strategy shoots with the rand()-function on the world. The coordinates are generated
 * in the function. The shoots are saved in an array brain[][]. Every field can be shooted only once.
 *
 */
int RandShootiS(TCPclient c);

#endif /* RANDOM_H */