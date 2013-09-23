#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__

#include "Strategy.hpp"
#include <string>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <utility>
#include <gmpxx.h>

class Context
{
public:
  Context();
  virtual ~Context();

  void setStrategy( Strategy * strategy );
  virtual std::pair<mpz_class, mpf_class> executeStrategy( std::string company, boost::posix_time::ptime currDate );

private:
  Strategy * _strategy;
};

#endif
