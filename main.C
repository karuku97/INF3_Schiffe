//============================================================================
// Name        : INF3_Prak.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <string>
#include <iostream>

#include <cstdio>      /* printf, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

#include <unistd.h>

#include<sstream>
#include<vector>

#include "TASK3.H"



using namespace std;


int main(){

	int x,y;

	string str = "1/5";

	istringstream ss {str};
	vector<string> stringV;

	while(ss.good()){
		string substr = "1";
		std::getline(ss,substr, '/');
		stringV.push_back(substr);
	}


	cout<< "x: " << stringV[0] << " y: " << stringV[1]<< endl;


    return 0;
}





