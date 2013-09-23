#include "NewModuleEvent.hpp"
#include "../../../ModuleController/Module/CurrencyDisplay/CurrencyDisplay.hpp"

NewModuleEvent::NewModuleEvent(
			       unsigned int moduleid,
			       std::string name,
			       mpf_class initialworth,
			       std::unordered_map<std::string, mpz_class> initialholdings
			       )
  :
  Event(),
  _moduleid( moduleid ),
  _name( name ),
  _initialworth( initialworth ),
  _initialholdings( initialholdings )
{
} /* end NewModuleEvent::NewModuleEvent() */

const char * NewModuleEvent::what() const throw()
{
  std::string retStr = boost::posix_time::to_simple_string( _timestamp );
  retStr += " : New Module Event : " + _name + " => " + CurrencyDisplay( _initialworth ).toString();

  for( auto it = std::begin( _initialholdings ); it != std::end( _initialholdings ); ++it )
    {
      retStr += "\n\tInitial Holding: " + (it->second).get_str() + " shares of " + it->first;
    }

  return retStr.c_str();
} /* end NewModuleEvent::what() */

std::string NewModuleEvent::type() const throw()
{
  return "NewModuleEvent";
} /* end NewModuleEvent::type() */

unsigned int NewModuleEvent::getId() const throw()
{
  return _moduleid;
} /* end NewModuleEvent::getId() */

std::string NewModuleEvent::getName() const throw()
{
  return _name;
} /* end NewModuleEvent::getName() */

mpf_class NewModuleEvent::getInitialWorth() const throw()
{
  return _initialworth;
} /* end NewModuleEvent::getInitialWorth() */

std::unordered_map<std::string, mpz_class> NewModuleEvent::getHoldings() const throw()
{
  return _initialholdings;
} /* end NewModuleEvent::getHoldings() */
