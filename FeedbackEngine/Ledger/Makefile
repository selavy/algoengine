CC = g++
CFLAGS = -Wall -Werror -g -ansi -pedantic -std=c++11
GMP = -lgmpxx -lgmp
BOOST = -I/usr/include/boost -lboost_date_time

all: driver
	./driver/driver
driver: Module.o NewModuleEvent.o TestStrategyA.o TestStrategyB.o TestStrategyC.o CurrencyDisplay.o Ledger.o LedgerDriver.o
	$(CC) $(CFLAGS) $(BOOST) ./build/Module.o ./build/Portfolio.o ./build/Event.o ./build/BuyEvent.o ./build/SellEvent.o ./build/NewModuleEvent.o ./build/Context.o ./build/TestStrategyA.o ./build/TestStrategyB.o ./build/TestStrategyC.o ./build/CurrencyDisplay.o ./build/Ledger.o ./build/LedgerDriver.o $(GMP) -o ./driver/driver
Module.o: Portfolio.o Event.o BuyEvent.o SellEvent.o Context.o
	$(CC) $(CFLAGS) -c ../../ModuleController/Module/Module.cpp -o ./build/Module.o
Portfolio.o:
	$(CC) $(CFLAGS) -c ../../ModuleController/Module/Portfolio/Portfolio.cpp -o ./build/Portfolio.o
Event.o:
	$(CC) $(CFLAGS) -c ./Event/Event.cpp -o ./build/Event.o
BuyEvent.o:
	$(CC) $(CFLAGS) -c ./Event/BuyEvent.cpp -o ./build/BuyEvent.o
SellEvent.o:
	$(CC) $(CFLAGS) -c ./Event/SellEvent.cpp -o ./build/SellEvent.o
NewModuleEvent.o:
	$(CC) $(CFLAGS) -c ./Event/NewModuleEvent.cpp -o ./build/NewModuleEvent.o
Context.o:
	$(CC) $(CFLAGS) -c ../../ModuleController/Module/Strategy/Context.cpp -o ./build/Context.o
TestStrategyA.o:
	$(CC) $(CFLAGS) -c ../../ModuleController/Module/Strategy/TestStrategy/TestStrategyA.cpp -o ./build/TestStrategyA.o
TestStrategyB.o:
	$(CC) $(CFLAGS) -c ../../ModuleController/Module//Strategy/TestStrategy/TestStrategyB.cpp -o ./build/TestStrategyB.o
TestStrategyC.o:
	$(CC) $(CFLAGS) -c ../../ModuleController/Module/Strategy/TestStrategy/TestStrategyC.cpp -o ./build/TestStrategyC.o
CurrencyDisplay.o:
	$(CC) $(CFLAGS) -c ../../ModuleController/Module/CurrencyDisplay/CurrencyDisplay.cpp -o ./build/CurrencyDisplay.o
Ledger.o:
	$(CC) $(CFLAGS) -c Ledger.cpp -o ./build/Ledger.o
LedgerDriver.o:
	$(CC) $(CFLAGS) -c LedgerDriver.cpp -o ./build/LedgerDriver.o
clean:
	rm -rf *.o *~ ./build/* ./driver/driver
