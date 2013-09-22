#include "SellEvent.hpp"

SellEvent::SellEvent(
		   std::string company,
		   int amount,
		   double shareprice
		   )
  :
  Event(),
  _company( company ),
  _amount( amount ),
  _shareprice( shareprice )
{
} /* end SellEvent::SellEvent() */

const char * SellEvent::what() const throw()
{
  std::string retStr = boost::posix_time::to_simple_string( _timestamp );
  retStr += " Sell Event : " + std::to_string( _amount ) + " shares of " + _company + " at " + std::to_string( _shareprice );

  return retStr.c_str();

} /* end SellEvent::what() */
