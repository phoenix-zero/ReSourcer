incsLoc=..
linksLoc=..
rccLoc=..
graphic=
CC=g++

ifneq ($(graphic),)
graphicS := `pkg-config --libs sfml-all`
endif

all: exec

exec:	resource.o test.o
	$(CC) resource.o test.o -L$(linksLoc) -lReSourcer_Lib $(graphicS) -o exec

test.o: test.cpp
	$(CC) -c test.cpp -I$(incsLoc) $(graphic)  

resource.o: resource.cpp
	$(CC) -c resource.cpp

resource.cpp: resource.rcc
	$(rccLoc)/ReSourcer_RCC resource.rcc -o resource.cpp

.PHONY: clean

clean:
	rm -f exec resource.o resource.cpp test.o
