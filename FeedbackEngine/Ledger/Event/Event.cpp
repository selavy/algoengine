#include "Event.hpp"

Event::Event()
  :
  _timestamp( boost::posix_time::second_clock::local_time() )
{
} /* end Event::Event() */

void Event::lock()
{
  _mtx.lock();
} /* end Event::lock() */

void Event::unlock()
{
  _mtx.unlock();
} /* end Event::unlock() */
