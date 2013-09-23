#include "Portfolio.hpp"

//#define __DEBUG__

#ifdef __DEBUG__
#include<iostream>
#endif

Portfolio::Portfolio(
		     Module& module
		     )
{
  _connection = module.connect( boost::bind(&Portfolio::process, this, _1 ) );
} /* end Portfolio::Portfolio() */

Portfolio::~Portfolio()
{
  _connection.disconnect();
} /* end Portfolio::~Portfolio() */

mpf_class Portfolio::getValue() const throw()
{
  return _value;
} /* end Portfolio::getValue() */

std::unordered_map<std::string, mpz_class> Portfolio::getHoldings() const throw()
{
  return _holdings;
} /* end Portfolio::getHoldings() */

void Portfolio::process(
		       Event* event
		       )
{
  std::string type = event->type();

  if( type == "NewModuleEvent" )
    {
      processNewModuleEvent( event );
    }
  else if( type == "BuyEvent" )
    {
      processBuyEvent( event );
    }
  else if( type == "SellEvent" )
    {
      processSellEvent( event );
    }
} /* end Portfolio::action() */

void Portfolio::processNewModuleEvent(
				      Event* e
				      )
{
  NewModuleEvent * event = (NewModuleEvent*) e;
  event->lock();
  _value = event->getInitialWorth();
  _holdings = event->getHoldings();
  event->unlock();
} /* end Portfolio::processNewModuleEvent() */

void Portfolio::processBuyEvent(
				Event* e
				)
{
  BuyEvent * event = (BuyEvent*) e;
  event->lock();
  std::string company = event->getCompany();
  mpz_class amount = event->getAmount();
  mpf_class shareprice = event->getSharePrice();
  event->unlock();

  action( company, amount, shareprice );
} /* end Portfolio::processBuyEvent() */

void Portfolio::processSellEvent(
				 Event* e
				 )
{
  SellEvent * event = (SellEvent*) e;
  event->lock();
  std::string company = event->getCompany();
  mpz_class amount = event->getAmount();
  mpf_class shareprice = event->getSharePrice();
  event->unlock();

  action( company, mpz_class(-1) * amount, shareprice );
} /* end Portfolio::processSellEvent() */

void Portfolio::action(
		       std::string company,
		       mpz_class amount,
		       mpf_class price
		       )
{
#ifdef __DEBUG__
  mp_exp_t exp = 24;
  std::cout << "value before: " << _value.get_str(exp) << std::endl;
#endif

  _value = _value - mpf_class( price * amount );

#ifdef __DEBUG__
  std::cout << "value after subtracting " << mpf_class( price * amount ).get_str(exp) << " : " << _value.get_str(exp) << std::endl;
#endif

  std::unordered_map<std::string, mpz_class>::iterator got = _holdings.find( company );

  if( got == _holdings.end() )
    {
      _holdings.emplace( company, amount );
    }
  else
    {
      got->second += amount;
    }
} /* end Portfolio::action() */

