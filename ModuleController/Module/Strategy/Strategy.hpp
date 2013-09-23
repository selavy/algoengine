#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__

#include <string>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <gmpxx.h>
#include <utility>

class Strategy
{
public:
  virtual ~Strategy() {}
  virtual std::pair<mpz_class, mpf_class> execute( std::string companyName, boost::posix_time::ptime currDate ) = 0;

  // TODO
  /* Add access methods to the Database */
};

#endif
