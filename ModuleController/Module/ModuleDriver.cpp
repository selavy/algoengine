#include "Module.hpp"
#include <iostream>
#include <string>
#include "./Portfolio/Portfolio.hpp"
#include <unordered_map>
#include <gmpxx.h>
#include "./Strategy/TestStrategy/TestStrategyA.hpp"
#include "./Strategy/TestStrategy/TestStrategyB.hpp"
#include "./Strategy/TestStrategy/TestStrategyC.hpp"
#include "./CurrencyDisplay/CurrencyDisplay.hpp"


void print( Portfolio * p )
{
  std::cout << "Printing portfolio:" << std::endl;
  std::cout << "Value : " << CurrencyDisplay( p->getValue() ) << std::endl;

  std::cout << "Holdings : " << std::endl;

  std::unordered_map<std::string, mpz_class> holdings = p->getHoldings();
  for( auto it = std::begin( holdings ); it != std::end( holdings ); ++it )
    {
      std::cout << it->first << " : " << (it->second).get_str() << std::endl;
    }

  std::cout << std::endl;
}

int main( int argc, char ** argv )
{
  Module * module;
  Portfolio * portfolio;
  Event * event;
  boost::posix_time::ptime date;
  std::string company = "GOOGL";
  std::unordered_map<std::string, mpz_class> holdings;

  holdings.emplace( "YHOO", mpz_class( 1000 ) );
  holdings.emplace( "MSFT", mpz_class( 5000 ) );
  holdings.emplace( "AMZN", mpz_class( 9000 ) );

  module = new Module(1);
  event = new NewModuleEvent( 1, "My Module", mpf_class( 100000 ), holdings);
  portfolio = new Portfolio( *module );
  module->sendEvent( event );
  module->loadStrategy( new TestStrategyA );
  module->run(company, date);
  print( portfolio );
  module->loadStrategy( new TestStrategyB );
  module->run(company, date);
  print( portfolio );
  module->loadStrategy( new TestStrategyC );
  module->run(company, date);
  print( portfolio );

  return 0;
} 
