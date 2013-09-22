#ifndef __TEST_STRATEGY_A_HPP__
#define __TEST_STRATEGY_A_HPP__

#include "../Strategy.hpp"

#include <cstdlib>
#include <ctime>
#include <string>

class TestStrategyA : public Strategy
{
public:
  TestStrategyA();

  virtual ~TestStrategyA() {}
  virtual double execute( std::string aCompany, boost::gregorian::date aDate );
};

#endif
