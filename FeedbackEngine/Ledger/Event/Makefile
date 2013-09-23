CC = g++
CFLAGS = -Wall -Werror -pedantic -ansi -g -std=c++11
GMP = -lgmpxx -lgmp

all: Event.o BuyEvent.o SellEvent.o NewModuleEvent.o

Event.o:
	$(CC) $(CFLAGS) -c Event.cpp
BuyEvent.o:
	$(CC) $(CFLAGS) -c BuyEvent.cpp
SellEvent.o:
	$(CC) $(CFLAGS) -c SellEvent.cpp
NewModuleEvent.o:
	$(CC) $(CFLAGS) -c NewModuleEvent.cpp
clean:
	rm -rf *.o *~
