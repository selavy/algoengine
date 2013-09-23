CC = g++
CFLAGS = -Wall -Werror -pedantic -ansi -g -std=c++11
GMP = -lgmpxx -lgmp

all: CurrencyDisplay.o CurrencyDisplayDriver.o
	$(CC) $(CFLAGS) CurrencyDisplay.o CurrencyDisplayDriver.o $(GMP) -o driver
	./driver
CurrencyDisplay.o:
	$(CC) $(CFLAGS) -c CurrencyDisplay.cpp
CurrencyDisplayDriver.o:
	$(CC) $(CFLAGS) -c CurrencyDisplayDriver.cpp
clean:
	rm -rf *.o *~ driver
