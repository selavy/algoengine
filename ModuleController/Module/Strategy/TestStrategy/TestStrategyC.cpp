#include "TestStrategyC.hpp"

TestStrategyC::TestStrategyC()
{
  srand( time( NULL ) );
} /* end TestStrategyC::TestStrategyC() */

double TestStrategyC::execute( std::string aCompany, boost::gregorian::date aDate )
{
  return rand() % 10;
} /* end TestStrategyC::execute() */
