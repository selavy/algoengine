#include "Module.hpp"

//#define __DEBUG__

#ifdef __DEBUG__
#include <iostream>
#endif

Module::Module(
	       unsigned int id
	       )
  :
  _id( id )
{
  _context = new Context();
} /* end Module::Module() */

Module::~Module()
{
  delete _context;
} /* end Module::~Module() */

boost::signals2::connection Module::connect( const signal_t::slot_type& subscriber )
{
  return _sig.connect( subscriber );
} /* end Module::connect() */

void Module::loadStrategy(
			  Strategy * strategy
			  )
{
  _context->setStrategy( strategy );
} /* end Module::loadStrategy() */

void Module::run(
		 std::string company,
		 boost::posix_time::ptime date
		 )
{
  std::pair<mpz_class, mpf_class> result = _context->executeStrategy( company, date );

  if( result.first == mpz_class( 0 ) && result.second == mpf_class( 0 ) )
    return;

  else 
    {
      Event * event;

#ifdef __DEBUG__
      mp_exp_t exp = 12;
      std::cout << "new event : " << (result.first).get_str() << " , " << (result.second).get_str(exp) << std::endl;
#endif
      if( result.first > mpz_class( 0 ) )
	{
	  /* construct event and send it out */
	  event = new BuyEvent( company, result.first, result.second );
	}
      else
	{
	  event = new SellEvent( company, result.first, result.second );
	}

      _sig( event );
    }
} /* end Module::run() */

unsigned int Module::getId() const throw()
{
  return _id;
} /* end Module::getId() */

void Module::sendEvent( Event * e )
{
  _sig( e );
} /* end Module::sendEvent() */
