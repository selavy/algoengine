#include <iostream>
#include <string>

#include "Ledger.hpp"
#include "./Event/Event.hpp"
#include "./Event/BuyEvent.hpp"
#include "./Event/SellEvent.hpp"
#include "./Event/NewModuleEvent.hpp"
#include "../../ModuleController/Module/Module.hpp"
#include "../../ModuleController/Module/Strategy/TestStrategy/TestStrategyA.hpp"

int main( int argc, char ** argv )
{
  Module * module = new Module(1);
  std::unordered_map<std::string, mpz_class> initialholdings;
  boost::posix_time::ptime atime;
  std::string companyA = "GOOGL";
  std::string companyB = "YHOO";
  std::string companyC = "MSFT";

  Ledger * ledger = new Ledger(*module);
  module->sendEvent( new NewModuleEvent( 1, std::string( "module name" ), mpf_class( 10000 ), initialholdings ) );

  module->loadStrategy( new TestStrategyA );
  module->run(companyA, atime);
  module->run(companyB, atime);
  module->run(companyC, atime);


  ledger->print();
  return 0;
}
