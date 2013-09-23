#ifndef __NEW_MODULE_EVENT_HPP__
#define __NEW_MODULE_EVENT_HPP__

#include "Event.hpp"
#include <string>
#include <unordered_map>
#include <mutex>
#include <gmpxx.h>

class NewModuleEvent : public Event
{
public:
  NewModuleEvent( unsigned int moduleid, std::string name, mpf_class initialworth, std::unordered_map<std::string, mpz_class> initialholdings );
  virtual ~NewModuleEvent() {}

  virtual const char * what() const throw();
  virtual std::string type() const throw();
  unsigned int getId() const throw();
  std::string getName() const throw();
  mpf_class getInitialWorth() const throw();
  std::unordered_map<std::string, mpz_class> getHoldings() const throw();

private:
  unsigned int _moduleid;
  std::string _name;
  mpf_class _initialworth;
  std::unordered_map<std::string, mpz_class> _initialholdings;
};

#endif
