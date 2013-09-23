#include "BuyEvent.hpp"

BuyEvent::BuyEvent(
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
} /* end BuyEvent::BuyEvent() */

const char * BuyEvent::what() const throw()
{
  mp_exp_t exp = 12;
  std::string retStr = boost::posix_time::to_simple_string( _timestamp );
  retStr += " Buy Event : " + _amount.get_str() + " shares of " + _company + " at " + _shareprice.get_str(exp);

  return retStr.c_str();

} /* end BuyEvent::what() */

std::string BuyEvent::type() const throw()
{
  return "BuyEvent";
} /* end BuyEvent::type() */

std::string BuyEvent::getCompany() const throw()
{
  return _company;
} /* end BuyEvent::getCompany() */

mpz_class BuyEvent::getAmount() const throw()
{
  return _amount;
} /* end BuyEvent::getAmount() */

mpf_class BuyEvent::getSharePrice() const throw()
{
  return _shareprice;
} /* end BuyEvent::getSharePrice() */
