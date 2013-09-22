#include "NewModuleEvent.hpp"

NewModuleEvent::NewModuleEvent(
			       std::string name,
			       double initialworth,
			       std::unordered_map<std::string, int> initialholdings
			       )
  :
  Event(),
  _name( name ),
  _initialworth( initialworth ),
  _initialholdings( initialholdings )
{
} /* end NewModuleEvent::NewModuleEvent() */

const char * NewModuleEvent::what() const throw()
{
  std::string retStr = boost::posix_time::to_simple_string( _timestamp );
  retStr += " : New Module Event : " + _name + " => $" + std::to_string( _initialworth );

  for( auto it = std::begin( _initialholdings ); it != std::end( _initialholdings ); ++it )
    {
      retStr += "\n\tInitial Holding: " + std::to_string( it->second ) + " shares of " + it->first;
    }

  return retStr.c_str();
} /* end NewModuleEvent::what() */
