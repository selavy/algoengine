#include "TestStrategyB.hpp"

TestStrategyB::TestStrategyB()
{
  srand( time( NULL ) );
} /* end TestStrategyB::TestStrategyB() */

double TestStrategyB::execute( std::string aCompany, boost::gregorian::date aDate )
{
  return ( rand() % 50 ) + 200;
} /* end TestStrategyB::execute() */
