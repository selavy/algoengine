#include "ModuleController.hpp"
#include "./Module/Strategy/TestStrategy/TestStrategyA.hpp"
#include "./Module/Strategy/TestStrategy/TestStrategyB.hpp"
#include "./Module/Strategy/TestStrategy/TestStrategyC.hpp"

int main( int argc, char ** argv )
{
  ModuleController * controller = new ModuleController();
  FeedbackEngine * FBEngine = new FeedbackEngine();

  FBEngine->addModuleController( *controller );

  std::unordered_map<std::string, mpz_class> holdingsA;
  std::unordered_map<std::string, mpz_class> holdingsB;
  std::unordered_map<std::string, mpz_class> holdingsC;

  holdingsA.emplace( "GOOGL", mpz_class("1000") );
  holdingsA.emplace( "YHOO", mpz_class("50000") );
  holdingsA.emplace( "AMZN", mpz_class("4000") );

  controller->newModule( "first", mpf_class("10000.00"), holdingsA, new TestStrategyA ); 

  holdingsB.emplace( "PETER", mpz_class("500") );

  controller->newModule( "second", mpf_class("500000.00"), holdingsB, new TestStrategyB );

  holdingsC.emplace( "TEST", mpz_class("1") );
  holdingsC.emplace( "ANOTHER", mpz_class("2") );

  controller->newModule( "third", mpf_class("40000.00"), holdingsC, new TestStrategyC );

  boost::gregorian::date aday( boost::gregorian::day_clock::local_day() );

  std::vector<std::string> companies;

  companies.push_back( std::string( "GOOGL" ) );
  companies.push_back( std::string( "YHOO" ) );
  companies.push_back( std::string( "AMZN" ) );
  companies.push_back( std::string( "MSFT" ) );
  companies.push_back( std::string( "NEW" ) );

  controller->loadCompanyList( companies );
  controller->run( aday );

  FBEngine->print();
  return 0;
}
