#include "SellEvent.hpp"

SellEvent::SellEvent(
		   std::string company,
		   mpz_class amount,
		   mpf_class shareprice
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
  mp_exp_t exp = 12;
  std::string retStr = boost::posix_time::to_simple_string( _timestamp );
  retStr += " Sell Event : " + _amount.get_str() + " shares of " + _company + " at " + _shareprice.get_str(exp);

  return retStr.c_str();

} /* end SellEvent::what() */

std::string SellEvent::type() const throw()
{
  return "SellEvent";
} /* end SellEvent::type() */

std::string SellEvent::getCompany() const throw()
{
  return _company;
} /* end SellEvent::getCompany() */

mpz_class SellEvent::getAmount() const throw()
{
  return _amount;
} /* end SellEvent::getAmount() */

mpf_class SellEvent::getSharePrice() const throw()
{
  return _shareprice;
} /* end SellEvent::getSharePrice() */
