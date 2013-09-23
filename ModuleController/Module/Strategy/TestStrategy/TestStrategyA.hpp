#ifndef __TEST_STRATEGY_A_HPP__
#define __TEST_STRATEGY_A_HPP__

#include "../Strategy.hpp"

#include <cstdlib>
#include <ctime>
#include <string>
#include <utility> /* std::pair */
#include <gmpxx.h>

class TestStrategyA : public Strategy
{
public:
  TestStrategyA();

  virtual ~TestStrategyA() {}
  virtual std::pair<mpz_class, mpf_class> execute( std::string aCompany, boost::posix_time::ptime aDate );
};

#endif
