incsLoc=..
linksLoc=..
rccLoc=..
graphic=
CC=g++

all: exec

exec:	resource.o test.o
	$(CC) resource.o test.o -L$(linksLoc) -lReSourcer_Lib `pkg-config --libs sfml-all` -o exec

test.o: test.cpp
	$(CC) -c test.cpp -I$(incsLoc) $(graphic)  

resource.o: resource.cpp
	$(CC) -c resource.cpp

resource.cpp: resource.rcc
	$(rccLoc)/ReSourcer_RCC resource.rcc -o resource.cpp

.PHONY: clean

clean:
	rm -f exec resource.o resource.cpp test.o
