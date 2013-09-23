#ifndef __LEDGER_HPP__
#define __LEDGER_HPP__

#include "./Event/Event.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include "../../ModuleController/Module/Module.hpp"
#include <boost/signals2/connection.hpp>
#include <boost/bind.hpp>

class Ledger
{
public:
  Ledger( Module& module );
  virtual ~Ledger();

  void record( Event* event );
  void print();
  void setLogFile( std::string& logfile );
private:
  void printToStream( std::ostream& os );

  unsigned int _moduleid;
  std::vector<Event*> _eventlist;
  std::ofstream _logfile;
  boost::signals2::connection _connection;
};

#endif
