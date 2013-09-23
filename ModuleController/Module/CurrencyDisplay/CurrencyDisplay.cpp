#include "CurrencyDisplay.hpp"

CurrencyDisplay::CurrencyDisplay(
		mpf_class currency
		)
  :
  _currency( currency )
{
} /* end CurrencyDisplay::CurrencyDisplay() */

std::ostream& CurrencyDisplay::print( std::ostream& os ) const
{
  mp_exp_t exp;
  std::string significant;

  significant = _currency.get_str(exp);
  exp -= significant.size();

  if( exp == 0 )
    {
      os << "$" << significant << ".00";
      return os;
    }
  else if( exp < 0 )
    {
      exp = significant.size() + exp;

      /* sanity check */
      if( exp < 0 )
	return os;

      os << "$";
      unsigned int i;
      for( i = 0; i < exp; ++i )
	os << significant.at(i);

      os << ".";

      for( ; i < significant.size(); ++i )
	os << significant.at(i);
    }
  else /* exp > 0 ) */
    {
      os << "$" << significant;
      for( int i = 0; i < exp; ++i )
	os << "0";

      os << ".00";
    }
      return os;
} /* end CurrencyDisplay::print() */

std::ostream& operator<<( std::ostream& os, const CurrencyDisplay& currency )
{
  return currency.print( os );
}
