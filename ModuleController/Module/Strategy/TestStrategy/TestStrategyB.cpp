#include "TestStrategyB.hpp"

TestStrategyB::TestStrategyB()
{
  srand( time( NULL ) );
} /* end TestStrategyB::TestStrategyB() */

std::pair<mpz_class, mpf_class> TestStrategyB::execute( std::string aCompany, boost::posix_time::ptime aDate )
{
  int r = rand() % 50 + 200;
  return std::make_pair( mpz_class( r ), mpf_class( 1.0 ) );
} /* end TestStrategyB::execute() */
