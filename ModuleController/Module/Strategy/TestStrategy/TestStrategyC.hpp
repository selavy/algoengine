#ifndef __TEST_STRATEGY_C_HPP__
#define __TEST_STRATEGY_C_HPP__

#include "../Strategy.hpp"

#include <cstdlib>
#include <ctime>
#include <string>
#include <gmpxx.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <utility>

class TestStrategyC : public Strategy
{
public:
  TestStrategyC();

  virtual ~TestStrategyC() {}
  virtual std::pair<mpz_class, mpf_class> execute( std::string aCompany, boost::posix_time::ptime aDate );
};

#endif
