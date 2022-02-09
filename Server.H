/*
 * Server.H
 *
 *  Created on: 14.11.2021
 *      Author: kkuckelsberg
 */

/**
 *
 * \file Server.H
 *
 * \brief contains the Battleship Server
 */


#ifndef SERVER_H
#define SERVER_H


#include "SIMPLESOCKET.H"
#include <string>
#include "TASK3.H"
#include <vector>
#include <sstream>
/**
 *
 *  \class myServer
 *  \brief The class defining individual Server of Battleships
 *
 */
class myServer : public TCPserver{
public:
/**
*
*  \brief constructor
*
*  \param port int number the server listens.
*  \param maxDataSizeRecv int maximal size of the messages the server can receive.
*
*/
	myServer(int port, int maxDataSizeRecv) : TCPserver( port,maxDataSizeRecv){};


protected:
/**
*
* \brief Defines the responses to the given received data.
*
* \param input contains the data the server has received.
*
* \return string containing the response of the server.
*
*/
	 string myResponse(string input);

private:
	 TASK3::World w;

	 TASK3::ShootResult res;





};

#endif /* SERVER_H */
