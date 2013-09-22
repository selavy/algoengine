#ifndef __TEST_STRATEGY_B_HPP__
#define __TEST_STRATEGY_B_HPP__

#include "../Strategy.hpp"

#include <cstdlib>
#include <ctime>
#include <string>

class TestStrategyB : public Strategy
{
public:
  TestStrategyB();

  virtual ~TestStrategyB() {}
  virtual double execute( std::string aCompany, boost::gregorian::date aDate );
};

#endif
