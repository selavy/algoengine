#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__

#include<string>
#include "boost/date_time/gregorian/gregorian.hpp"

class Strategy
{
public:
  virtual ~Strategy() {}
  virtual double execute( std::string companyName, boost::gregorian::date currDate ) = 0;

  // TODO
  /* Add access methods to the Database */
};

#endif
