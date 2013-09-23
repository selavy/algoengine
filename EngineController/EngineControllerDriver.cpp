#include <iostream>
#include "EngineController.hpp"
#include "../ModuleController/Module/Strategy/TestStrategy/TestStrategyA.hpp"
#include "../ModuleController/Module/Strategy/TestStrategy/TestStrategyB.hpp"
#include "../ModuleController/Module/Strategy/TestStrategy/TestStrategyC.hpp"

int main( int argc, char ** argv )
{
  EngineController * ec;

  std::string startdate = "2013/9/21";
  std::string enddate = "2013/9/23";
  long long int gran = EngineController::DAY;

  ec = new EngineController( startdate, enddate, gran );

  std::unordered_map<std::string, std::string> holdingsA;
  holdingsA.emplace("GOOGL", "10000");
  holdingsA.emplace("YHOO", "500");
  holdingsA.emplace("AMZN", "250");

  ec->addModule( std::string("first"), std::string("10500.00"), holdingsA, new TestStrategyA );

  std::unordered_map<std::string, std::string> holdingsB;
  ec->addModule( std::string("second"), std::string("500.00"), holdingsB, new TestStrategyB );

  std::unordered_map<std::string, std::string> holdingsC;
  holdingsC.emplace("PETER", "2000000");
  holdingsC.emplace("ANOTHER", "20");

  ec->addModule( "third", "1", holdingsC, new TestStrategyC );

  std::vector<std::string> companies;
  companies.push_back("GOOGL");
  companies.push_back("YHOO");
  companies.push_back("AMZN");
  companies.push_back("AAA");
  companies.push_back("BBB");
  companies.push_back("CCC");
  companies.push_back("DDD");
  companies.push_back("EEE");
  companies.push_back("FFF");
  companies.push_back("GGG");
  companies.push_back("HHH");
  companies.push_back("III");
  ec->loadCompanyList( companies );

  /* magic */
  ec->run();
  ec->print();
  return 0;

}
