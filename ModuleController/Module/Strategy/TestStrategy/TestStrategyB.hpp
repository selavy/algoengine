#ifndef __TEST_STRATEGY_B_HPP__
#define __TEST_STRATEGY_B_HPP__

#include "../Strategy.hpp"

#include <cstdlib>
#include <ctime>
#include <string>
#include <utility>
#include <gmpxx.h>
#include <boost/date_time/posix_time/posix_time.hpp>

class TestStrategyB : public Strategy
{
public:
  TestStrategyB();

  virtual ~TestStrategyB() {}
  virtual std::pair<mpz_class, mpf_class> execute( std::string aCompany, boost::posix_time::ptime aDate );
};

#endif
