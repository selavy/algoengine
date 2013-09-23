#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "boost/date_time/posix_time/posix_time.hpp"
#include <mutex>

class Event
{
public:
  Event();
  virtual ~Event() {}

  virtual const char * what() const throw() = 0;
  virtual std::string type() const throw() = 0;

  void lock();
  void unlock();
protected:
  boost::posix_time::ptime _timestamp;
  std::mutex _mtx;
};

#endif
