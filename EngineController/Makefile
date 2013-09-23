CC = g++
CFLAGS = -Wall -Werror -g -ansi -pedantic -std=c++11
GMP = -lgmpxx -lgmp
BOOST = -I/usr/include/boost/date_time/gregorian -lboost_date_time
THREAD = -lpthread

all: driver
	./driver/driver
driver: Module.o NewModuleEvent.o TestStrategyA.o TestStrategyB.o TestStrategyC.o CurrencyDisplay.o Ledger.o ModuleController.o FeedbackEngine.o EngineController.o EngineControllerDriver.o
	$(CC) $(CFLAGS) $(BOOST) ./build/Module.o ./build/Portfolio.o ./build/Event.o ./build/BuyEvent.o ./build/SellEvent.o ./build/NewModuleEvent.o ./build/Context.o ./build/TestStrategyA.o ./build/TestStrategyB.o ./build/TestStrategyC.o ./build/CurrencyDisplay.o ./build/Ledger.o ./build/FeedbackEngine.o ./build/ModuleController.o ./build/EngineController.o ./build/EngineControllerDriver.o $(GMP) $(THREAD) -o ./driver/driver
Module.o: Portfolio.o Event.o BuyEvent.o SellEvent.o Context.o
	$(CC) $(CFLAGS) -c ../ModuleController/Module/Module.cpp -o ./build/Module.o
Portfolio.o:
	$(CC) $(CFLAGS) -c ../ModuleController/Module/Portfolio/Portfolio.cpp -o ./build/Portfolio.o
Event.o:
	$(CC) $(CFLAGS) -c ../FeedbackEngine/Ledger/Event/Event.cpp -o ./build/Event.o
BuyEvent.o:
	$(CC) $(CFLAGS) -c ../FeedbackEngine/Ledger/Event/BuyEvent.cpp -o ./build/BuyEvent.o
SellEvent.o:
	$(CC) $(CFLAGS) -c ../FeedbackEngine/Ledger/Event/SellEvent.cpp -o ./build/SellEvent.o
NewModuleEvent.o:
	$(CC) $(CFLAGS) -c ../FeedbackEngine/Ledger/Event/NewModuleEvent.cpp -o ./build/NewModuleEvent.o
Context.o:
	$(CC) $(CFLAGS) -c ../ModuleController/Module/Strategy/Context.cpp -o ./build/Context.o
TestStrategyA.o:
	$(CC) $(CFLAGS) -c ../ModuleController/Module/Strategy/TestStrategy/TestStrategyA.cpp -o ./build/TestStrategyA.o
TestStrategyB.o:
	$(CC) $(CFLAGS) -c ../ModuleController/Module/Strategy/TestStrategy/TestStrategyB.cpp -o ./build/TestStrategyB.o
TestStrategyC.o:
	$(CC) $(CFLAGS) -c ../ModuleController/Module/Strategy/TestStrategy/TestStrategyC.cpp -o ./build/TestStrategyC.o
CurrencyDisplay.o:
	$(CC) $(CFLAGS) -c ../ModuleController/Module/CurrencyDisplay/CurrencyDisplay.cpp -o ./build/CurrencyDisplay.o
Ledger.o:
	$(CC) $(CFLAGS) -c ../FeedbackEngine/Ledger/Ledger.cpp -o ./build/Ledger.o
EngineControllerDriver.o: ModuleController.o FeedbackEngine.o EngineController.o
	$(CC) $(CFLAGS) -c EngineControllerDriver.cpp -o ./build/EngineControllerDriver.o
ModuleController.o:
	$(CC) $(CFLAGS) -c ../ModuleController/ModuleController.cpp -o ./build/ModuleController.o
FeedbackEngine.o: ModuleController.o
	$(CC) $(CFLAGS) -c ../FeedbackEngine/FeedbackEngine.cpp -o ./build/FeedbackEngine.o
EngineController.o:
	$(CC) $(CFLAGS) -c EngineController.cpp -o ./build/EngineController.o
clean:
	rm -rf *.o *~ ./build/* ./driver/driver
