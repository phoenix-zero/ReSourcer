incsLoc=..
linksLoc=..
rccLoc=..
CC_FLAG=-std=c++17
CC=g++

all: exec

exec:	resource.o main.o
	$(CC) resource.o main.o -L$(linksLoc) -lReSourcer_Lib `pkg-config --libs sfml-all` -o exec

main.o: main.cpp
	$(CC) -c main.cpp -I$(incsLoc) $(graphic) $(CC_FLAG) 

resource.o: resource.cpp
	$(CC) -c resource.cpp

resource.cpp: resource.rcc
	$(rccLoc)/ReSourcer_RCC resource.rcc -o resource.cpp

.PHONY: clean

clean:
	rm -f exec resource.o resource.cpp main.o
