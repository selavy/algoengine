#include "Context.hpp"

Context::Context()
  :
  _strategy( NULL )
{
} /* end Context::Context() */

Context::~Context()
{
  if( _strategy )
    delete _strategy;
} /* end Context::~Context() */

void Context::setStrategy(
			  Strategy * strategy
			  )
{
  _strategy = strategy;
} /* end Context::setStrategy() */

std::pair<mpz_class, mpf_class> Context::executeStrategy(
							   std::string company,
							   boost::posix_time::ptime currDate
							   )
{
  if( _strategy )
    return _strategy->execute( company, currDate ); 

  else
    return std::make_pair( mpz_class( 0 ), mpf_class( 0.0 ) );
} /* end Context::executeStrategy() */
