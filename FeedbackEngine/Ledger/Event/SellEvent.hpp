#ifndef __SELL_EVENT_HPP__
#define __SELL_EVENT_HPP__

#include "Event.hpp"
#include <string>

class SellEvent : public Event
{
public:
  SellEvent( std::string company, int amount, double shareprice );
  virtual ~SellEvent() {}

  virtual const char * what() const throw();
private:
  std::string _company;
  int _amount;
  double _shareprice;
};

#endif
