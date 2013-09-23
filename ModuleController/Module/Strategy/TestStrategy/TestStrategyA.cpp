#include "TestStrategyA.hpp"

TestStrategyA::TestStrategyA()
{
  srand( time( NULL ) );
} /* end TestStrategyA::TestStrategyA() */

std::pair<mpz_class, mpf_class> TestStrategyA::execute( std::string aCompany, boost::posix_time::ptime aDate )
{
  return std::make_pair( mpz_class( rand() % 100 ), mpf_class( rand() % 50 ) );
} /* end TestStrategyA::execute() */
