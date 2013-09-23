#include <iostream>
#include <string>

#include "Ledger.hpp"
#include "./Event/Event.hpp"
#include "./Event/BuyEvent.hpp"
#include "./Event/SellEvent.hpp"
#include "./Event/NewModuleEvent.hpp"

int main( int argc, char ** argv )
{
  NewModuleEvent * moduleEvent;
  BuyEvent * buyEvent;
  SellEvent * sellEvent;
  std::unordered_map<std::string, int> initialholdings;


  moduleEvent = new NewModuleEvent( "module name", 10000, initialholdings );
  buyEvent = new BuyEvent( "GOOGL", 100, 20 );
  sellEvent = new SellEvent( "GOOGL", 50, 34 );

  Ledger * ledger = new Ledger( moduleEvent );
  ledger->record( buyEvent );
  ledger->record( sellEvent );


  ledger->print( std::cout );
  return 0;
}
