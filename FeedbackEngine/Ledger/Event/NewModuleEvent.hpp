#ifndef __NEW_MODULE_EVENT_HPP__
#define __NEW_MODULE_EVENT_HPP__

#include "Event.hpp"
#include <string>
#include <unordered_map>

class NewModuleEvent : public Event
{
public:
  NewModuleEvent( std::string name, double initialworth, std::unordered_map<std::string, int> initialholdings );
  virtual ~NewModuleEvent() {}

  virtual const char * what() const throw();

private:
  std::string _name;
  double _initialworth;
  std::unordered_map<std::string, int> _initialholdings;
};

#endif
