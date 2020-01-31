main:Thread.o Server.o main.o
	gcc Thread.o Server.o main.o -lpthread -DEBUG -o main
Thread.o:Thread.c
	gcc -DEBUG -c Thread.c
Server.o:Server.c
	gcc -DEBUG -c Server.c

.PHONY:clean
clean:
	-rm *.o main
