#ifndef __TEST_STRATEGY_C_HPP__
#define __TEST_STRATEGY_C_HPP__

#include "../Strategy.hpp"

#include <cstdlib>
#include <ctime>
#include <string>

class TestStrategyC : public Strategy
{
public:
  TestStrategyC();

  virtual ~TestStrategyC() {}
  virtual double execute( std::string aCompany, boost::gregorian::date aDate );
};

#endif
