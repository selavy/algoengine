#include "Context.hpp"

Context::Context(
		 Strategy * strategy
		 )
  :
  _strategy( strategy )
{
} /* end Context::Context() */

Context::~Context()
{
  delete _strategy;
} /* end Context::~Context() */

double Context::executeStrategy(
				std::string company,
				boost::gregorian::date currDate
				)
{
  return _strategy->execute( company, currDate ); 
} /* end Context::executeStrategy() */
