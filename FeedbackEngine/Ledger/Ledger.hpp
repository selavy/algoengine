#ifndef __LEDGER_HPP__
#define __LEDGER_HPP__

#include "./Event/Event.hpp"
#include <vector>
#include <fstream>

class Ledger
{
public:
  Ledger( unsigned int ModuleId );
  virtual ~Ledger();

  void record( Event* event );
private:
  void recordAction( Event* event );
  void printToLog( Event* event );

  unsigned int _moduleid;
  vector<Event*> _eventlist;
  std::ofstream _logfile;
};

#endif
