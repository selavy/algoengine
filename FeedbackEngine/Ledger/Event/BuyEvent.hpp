#ifndef __BUY_EVENT_HPP__
#define __BUY_EVENT_HPP__

#include "Event.hpp"
#include <string>

class BuyEvent : public Event
{
public:
  BuyEvent( std::string company, int amount, double shareprice );
  virtual ~BuyEvent() {}

  virtual const char * what() const throw();
private:
  std::string _company;
  int _amount;
  double _shareprice;
};

#endif
