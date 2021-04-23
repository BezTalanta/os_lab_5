CC = gcc

all: run

run: libstat.a libdynn.so mainStat.o mainDyn.o
	$(CC) -o stat-prog mainStat.o -L. -lstat -lm
	$(CC) -o dyn-prog mainDyn.o -L. -ldynn -ldl

libstat.a: statLib.o
	ar rc libstat.a statLib.o

statLib.o: statLib.c
	$(CC) -c statLib.c

mainStat.o: mainStat.c
	$(CC) -c mainStat.c

libdynn.so: dynLib.o
	$(CC) -shared -o libdynn.so dynLib.o

dynLib.o: dynLib.c
	$(CC) -c -fPIC dynLib.c -lm

mainDyn.o: mainDyn.c
	$(CC) -c mainDyn.c -lm

clean: 
	rm *.o *.a libdynn.so stat-prog dyn-prog