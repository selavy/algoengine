#ifndef __LEDGER_HPP__
#define __LEDGER_HPP__

#include "./Event/Event.hpp"
#include <vector>
#include <fstream>
#include <iostream>

class Ledger
{
public:
  Ledger();
  virtual ~Ledger();

  void record( Event* event );
private:
  void print( std::ostream & os );

  unsigned int _moduleid;
  std::string _name;
  vector<Event*> _eventlist;
  std::ofstream _logfile;
};

#endif
