#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "boost/date_time/posix_time/posix_time.hpp"

class Event
{
public:
  Event();
  virtual ~Event() {}

  virtual const char * what() const throw() = 0;
protected:
  boost::posix_time::ptime _timestamp;
};

#endif
