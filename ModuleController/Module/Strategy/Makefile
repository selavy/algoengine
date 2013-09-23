CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -g -std=c++11
GMP = -lgmpxx -lgmp

all: driver
	./driver/driver
driver: TestStrategyA.o TestStrategyB.o TestStrategyC.o Context.o StrategyDriver.o
	$(CC) $(CFLAGS) ./driver/TestStrategyA.o ./driver/TestStrategyB.o ./driver/TestStrategyC.o ./driver/Context.o ./driver/StrategyDriver.o $(GMP) -o ./driver/driver
TestStrategyA.o:
	$(CC) $(CFLAGS) -c ./TestStrategy/TestStrategyA.cpp -o ./driver/TestStrategyA.o
TestStrategyB.o:
	$(CC) $(CFLAGS) -c ./TestStrategy/TestStrategyB.cpp -o ./driver/TestStrategyB.o
TestStrategyC.o:
	$(CC) $(CFLAGS) -c ./TestStrategy/TestStrategyC.cpp -o ./driver/TestStrategyC.o
Context.o:
	$(CC) $(CFLAGS) -c Context.cpp -o ./driver/Context.o
StrategyDriver.o:
	$(CC) $(CFLAGS) -c StrategyDriver.cpp -o ./driver/StrategyDriver.o
clean:
	rm -rf *~ ./driver/* ./TestStrategy/*~


