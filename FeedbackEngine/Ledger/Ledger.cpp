#include "Ledger.hpp"

Ledger::Ledger(
	       Module& module
	       )
{
  _moduleid = module.getId();
  _connection = module.connect(boost::bind(&Ledger::record, this, _1));
} /* end Ledger::Ledger() */

Ledger::~Ledger()
{
} /* end Ledger::~Ledger() */

void Ledger::record(
		    Event* event
		    )
{
  _eventlist.push_back( event );
} /* end Ledger::record() */

void Ledger::print()
{
  if( _logfile.is_open() )
    {
      printToStream( _logfile );
    }
  else
    {
      printToStream( std::cout );
    }
} /* end Ledger::print() */

void Ledger::setLogFile(
			std::string& logfile
			)
{
  if( _logfile.is_open() )
    _logfile.close();

  _logfile.open( logfile.c_str(), std::ofstream::out );
} /* end Ledger::setLogFile() */

void Ledger::printToStream(
			   std::ostream& os
			   )
{
  os << "Module : " << _moduleid << std::endl;
  for( std::vector<Event*>::const_iterator it = _eventlist.begin(); it != _eventlist.end(); ++it )
    {
      os << (*it)->what() << std::endl;
    }
} /* end Ledger::printToStream() */

	    
