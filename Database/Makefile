CC = g++
CFLAGS = -Wall -Werror -g -ansi -pedantic -std=c++11

all: driver
	./driver/driver
driver: Database.o DatabaseDriver.o
	$(CC) $(CFLAGS) ./driver/Database.o ./driver/DatabaseDriver.o -o ./driver/driver
Database.o:
	$(CC) $(CFLAGS) -c Database.cpp -o ./driver/Database.o
DatabaseDriver.o:
	$(CC) $(CFLAGS) -c DatabaseDriver.cpp -o ./driver/DatabaseDriver.o
clean:
	rm -rf ./driver/* *~
