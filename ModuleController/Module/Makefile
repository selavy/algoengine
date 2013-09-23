CC = g++
CFLAGS = -Wall -Werror -g -ansi -pedantic -std=c++11
GMP = -lgmpxx -lgmp
BOOST = -I/usr/include/boost -lboost_date_time

all: driver
	./driver/driver
driver: Module.o NewModuleEvent.o TestStrategyA.o TestStrategyB.o TestStrategyC.o ModuleDriver.o CurrencyDisplay.o
	$(CC) $(CFLAGS) $(BOOST) ./build/Module.o ./build/Portfolio.o ./build/Event.o ./build/BuyEvent.o ./build/SellEvent.o ./build/NewModuleEvent.o ./build/Context.o ./build/TestStrategyA.o ./build/TestStrategyB.o ./build/TestStrategyC.o ./build/ModuleDriver.o ./build/CurrencyDisplay.o $(GMP) -o ./driver/driver
ModuleDriver.o:
	$(CC) $(CFLAGS) -c ModuleDriver.cpp -o ./build/ModuleDriver.o
Module.o: Portfolio.o Event.o BuyEvent.o SellEvent.o Context.o
	$(CC) $(CFLAGS) -c Module.cpp -o ./build/Module.o
Portfolio.o:
	$(CC) $(CFLAGS) -c ./Portfolio/Portfolio.cpp -o ./build/Portfolio.o
Event.o:
	$(CC) $(CFLAGS) -c ../../FeedbackEngine/Ledger/Event/Event.cpp -o ./build/Event.o
BuyEvent.o:
	$(CC) $(CFLAGS) -c ../../FeedbackEngine/Ledger/Event/BuyEvent.cpp -o ./build/BuyEvent.o
SellEvent.o:
	$(CC) $(CFLAGS) -c ../../FeedbackEngine/Ledger/Event/SellEvent.cpp -o ./build/SellEvent.o
NewModuleEvent.o:
	$(CC) $(CFLAGS) -c ../../FeedbackEngine/Ledger/Event/NewModuleEvent.cpp -o ./build/NewModuleEvent.o
Context.o:
	$(CC) $(CFLAGS) -c ./Strategy/Context.cpp -o ./build/Context.o
TestStrategyA.o:
	$(CC) $(CFLAGS) -c ./Strategy/TestStrategy/TestStrategyA.cpp -o ./build/TestStrategyA.o
TestStrategyB.o:
	$(CC) $(CFLAGS) -c ./Strategy/TestStrategy/TestStrategyB.cpp -o ./build/TestStrategyB.o
TestStrategyC.o:
	$(CC) $(CFLAGS) -c ./Strategy/TestStrategy/TestStrategyC.cpp -o ./build/TestStrategyC.o
CurrencyDisplay.o:
	$(CC) $(CFLAGS) -c ./CurrencyDisplay/CurrencyDisplay.cpp -o ./build/CurrencyDisplay.o
clean:
	rm -rf *.o *~ ./build/* ./driver/driver
