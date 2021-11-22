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


		int m = 10;
		int n= 10;
		bool b[m][n];
		int i;
		int j;
		for(int f = 0 ; f<10;f++){
			for(int g = 0; g<10 ;g++){
				b[f][g] = false;
			}
		}


		for (int k=0;k<=m-1;k= k+2){
			 i = k;
			 j = 0;
			 while(i>=0){

				 b[j][i] = true;

				 for(int f = 0 ; f<10;f++){
				 			for(int g = 0; g<10 ;g++){
				 				cout<<b[f][g];
				 			}
				 			cout<<endl;
				 		}

				 cout<<endl;
				 i=i-1;
				 j= j+1;
				 sleep(1);
			 }

		}

		for (int k = 1; k<=n-1;k++){
			i=m-1;
			j=k;
			while(j<=n-1){

				b[j][i] = true;

								 for(int f = 0 ; f<10;f++){
								 			for(int g = 0; g<10 ;g++){
								 				cout<<b[f][g];
								 			}
								 			cout<<endl;
								 		}
								 cout<<endl;
				i= i-1;
				j=j+1;
				sleep(1);
			}

		}

    return 0;
}





