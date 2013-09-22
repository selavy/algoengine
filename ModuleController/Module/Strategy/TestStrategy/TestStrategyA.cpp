#include "TestStrategyA.hpp"

TestStrategyA::TestStrategyA()
{
  srand( time( NULL ) );
} /* end TestStrategyA::TestStrategyA() */

double TestStrategyA::execute( std::string aCompany, boost::gregorian::date aDate )
{
  return rand() % 100;
} /* end TestStrategyA::execute() */
