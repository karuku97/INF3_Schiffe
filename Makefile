CC=g++

CFLAGS=$(shell pkg-config --cflags opencv) 
LIBS=$(shell pkg-config --libs opencv) 

OBJS= main.o   TASK3.o  SIMPLESOCKET.o Random.o IntelliStrat.o BruteForce.o VerbrannteFelder.o SpielFeldverwaltung.o
DEMOTARGET=main Server Client


SIMPLESOCKET.o:	SIMPLESOCKET.C
	$(CC) -c $<  -std=c++11

Random.o:	Random.C
	$(CC) -c $<  -std=c++11
	
IntelliStrat.o:	IntelliStrat.C
	$(CC) -c $<  -std=c++11
	
BruteForce.o:	BruteForce.C
	$(CC) -c $<  -std=c++11

VerbrannteFelder.o:	VerbrannteFelder.C
	$(CC) -c $<  -std=c++11

SpielFeldverwaltung.o: SpielFeldverwaltung.C
	$(CC) -c $<  -std=c++11


TASK3.o:	TASK3.C
	$(CC) -c $<  -std=c++11


main.o:	main.C
	$(CC) -c $<  -std=c++11	


Client.o:	Client.C
	$(CC) -c $<  -std=c++11

Server.o:	Server.C
	$(CC) -c $<  -std=c++11
	




main:	$(OBJS)
	$(CC) -o $@ $^ -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11 -lpthread $(LIBS)



Server:	Server.o
	$(CC) -o Server Server.o  SIMPLESOCKET.o TASK3.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11

Client:	Client.o
	$(CC) -o Client Client.o SIMPLESOCKET.o BruteForce.o IntelliStrat.o Random.o VerbrannteFelder.o SpielFeldverwaltung.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11


clean:
	-rm -r -f   $(DEMOTARGET) *.o DOXYGENDOC  *.txt

doc:
	doxygen Doxyfile 


all:	$(DEMOTARGET)
	make clean  && make main &&make Server && make Client 

run:	main	
	./main

