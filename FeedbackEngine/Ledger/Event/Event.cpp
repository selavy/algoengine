#include "Event.hpp"

Event::Event()
  :
  _timestamp( boost::posix_time::second_clock::local_time() )
{
} /* end Event::Event() */
