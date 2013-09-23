#ifndef __SELL_EVENT_HPP__
#define __SELL_EVENT_HPP__

#include "Event.hpp"
#include <string>
#include <gmpxx.h>

class SellEvent : public Event
{
public:
  SellEvent( std::string company, mpz_class amount, mpf_class shareprice );
  virtual ~SellEvent() {}

  virtual const char * what() const throw();
  virtual std::string type() const throw();

  std::string getCompany() const throw();
  mpz_class getAmount() const throw();
  mpf_class getSharePrice() const throw();

private:
  std::string _company;
  mpz_class _amount;
  mpf_class _shareprice;
};

#endif
