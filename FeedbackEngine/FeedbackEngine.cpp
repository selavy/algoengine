#include "FeedbackEngine.hpp"

FeedbackEngine::FeedbackEngine()
{
} /* end FeedbackEngine::FeedbackEngine() */

FeedbackEngine::~FeedbackEngine()
{
  _connection.disconnect();
  
  for( std::vector<Ledger*>::iterator it = LedgerList.begin(); it != LedgerList.end(); ++it )
    {
      delete (*it);
    }

  LedgerList.clear();
} /* end FeedbackEngine::~FeedbackEngine() */

void FeedbackEngine::addModuleController( ModuleController& modulecontroller )
{
  _connection.disconnect();

  _connection = modulecontroller.connect( boost::bind( &FeedbackEngine::listen, this, _1 ) );
} /* end FeedbackEngine::addModuleController() */

void FeedbackEngine::listen( Module * module )
{
  /* Create a new ledger */
  Ledger * ledger = new Ledger( *module );
  LedgerList.push_back( ledger );
} /* end FeedbackEngine::list() */

void FeedbackEngine::print()
{
  for( std::vector<Ledger*>::iterator it = LedgerList.begin(); it != LedgerList.end(); ++it )
    {
      (*it)->print();
    }
} /* end FeedbackEngine::print() */
