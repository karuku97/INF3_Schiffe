CC=g++

CFLAGS=$(shell pkg-config --cflags opencv) 
LIBS=$(shell pkg-config --libs opencv) 

OBJS= main.o   TASK3.o  SIMPLESOCKET.o 
DEMOTARGET=main Server Client BruteForceDiagonal BruteForce


SIMPLESOCKET.o:	SIMPLESOCKET.C
	$(CC) -c $<  -std=c++11



TASK3.o:	TASK3.C
	$(CC) -c $<  -std=c++11


main.o:	main.C
	$(CC) -c $<  -std=c++11	

BruteForce.o:	BruteForce.C SIMPLESOCKET.o main.o
	$(CC) -c $<  -o -std=c++11

BruteForceDiagonal.o:	BruteForceDiagonal.C SIMPLESOCKET.o main.o
	$(CC) -c $<  -o -std=c++11

Client.o:	Client.C
	$(CC) -c $<  -std=c++11

Server.o:	Server.C
	$(CC) -c $<  -std=c++11



	




main:	$(OBJS)
	$(CC) -o $@ $^ -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11 -lpthread $(LIBS)


BruteForce: BruteForce.o
	$(CC) -o BruteForce BruteForce.o  BruteForce.C SIMPLESOCKET.o main.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11

BruteForceDiagonal: BruteForceDiagonal.o
	$(CC) -o BruteForceDiagonal BruteForceDiagonal.o  BruteForceDiagonal.C SIMPLESOCKET.o main.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11

Server:	Server.o
	$(CC) -o Server Server.o  SIMPLESOCKET.o TASK3.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11

Client:	Client.o
	$(CC) -o Client Client.o SIMPLESOCKET.o BruteForce.o BruteForceDiagonal.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11


clean:
	-rm -r -f   $(DEMOTARGET) *.o DOXYGENDOC  *.txt

doc:
	doxygen Doxyfile 


all:	$(DEMOTARGET)
	make clean  &&make BruteForce &&make BruteForceDiagonal && make main &&make Server && make Client 

run:	main	
	./main

