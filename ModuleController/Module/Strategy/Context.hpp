#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__

#include "Strategy.hpp"
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"

class Context
{
public:
  Context( Strategy * strategy );
  ~Context();
  virtual double executeStrategy( std::string company, boost::gregorian::date currDate );

private:
  Strategy * _strategy;
};

#endif
