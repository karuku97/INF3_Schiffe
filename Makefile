CC=g++

CFLAGS=$(shell pkg-config --cflags opencv) 
LIBS=$(shell pkg-config --libs opencv) 

OBJS= main.o   TASK3.o  SIMPLESOCKET.o 
DEMOTARGET=main myServer myClient


SIMPLESOCKET.o:	SIMPLESOCKET.C
	$(CC) -c $<  -std=c++11



TASK3.o:	TASK3.C
	$(CC) -c $<  -std=c++11


main.o:	main.C
	$(CC) -c $<  -std=c++11	


	
myClient.o:	myClient.C
	$(CC) -c $<  -std=c++11

myServer.o:	myServer.C
	$(CC) -c $<  -std=c++11
	




main:	$(OBJS)
	$(CC) -o $@ $^ -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11 -lpthread $(LIBS)



myServer:	myServer.o
	$(CC) -o myServer myServer.o  SIMPLESOCKET.o TASK3.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11

myClient:	myClient.o
	$(CC) -o myClient myClient.o SIMPLESOCKET.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11

clean:
	-rm -r -f   $(DEMOTARGET) *.o DOXYGENDOC  *.txt

doc:
	doxygen Doxyfile 


all:	$(DEMOTARGET)
	make clean  && make main &&make myServer && make myClient

run:	main	
	./main

