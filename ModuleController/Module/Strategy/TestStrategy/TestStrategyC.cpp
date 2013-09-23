#include "TestStrategyC.hpp"

TestStrategyC::TestStrategyC()
{
  srand( time( NULL ) );
} /* end TestStrategyC::TestStrategyC() */

std::pair<mpz_class, mpf_class> TestStrategyC::execute( std::string aCompany, boost::posix_time::ptime aDate )
{
  return std::make_pair( mpz_class( rand() % 10 ), mpf_class( 1 ) );
} /* end TestStrategyC::execute() */
