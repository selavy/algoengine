#include "ModuleController.hpp"

ModuleController::ModuleController()
  :
  _nextid( 0 )
{
} /* end ModuleController::ModuleController() */

ModuleController::~ModuleController()
{
  for( std::vector<Module*>::iterator it = _modulelist.begin(); it != _modulelist.end(); ++it )
    {
      delete (*it);
    }

  _modulelist.clear();
  _companylist.clear();
} /* end ModuleController::~ModuleController() */

unsigned int ModuleController::newModule(
					 std::string name,
					 mpf_class initialvalue,
					 std::unordered_map<std::string, mpz_class> holdings,
					 Strategy * strategy /* = NULL */
					 )
{
  Module * module = new Module( getNextId() );
  
  if( strategy != NULL )
    {
      module->loadStrategy( strategy );
    }


  /* send out message to FeedbackEngine that new module was created */
  _sig( module );

  /* send out NewModuleEventMessage to all Ledgers */
  NewModuleEvent * event = new NewModuleEvent( module->getId(), name, initialvalue, holdings );
  module->sendEvent( event );

  /* add module id to lookup map */
  _modulelookup.emplace( name, module->getId() );

  /* add module to list */
  _modulelist.push_back( module );
  return module->getId();
} /* end ModuleController::newModule() */

unsigned int ModuleController::getModuleIdByName( std::string name )
{
  // TODO
  /* Right now just hoping that all module names are unique */
  std::unordered_map<std::string, unsigned int>::const_iterator got = _modulelookup.find( name );

  if( got == _modulelookup.end() )
    return not_found;

  else
    return got->second;
} /* end ModuleController::getModuleIdByName() */

void ModuleController::loadStrategy(
				    unsigned int moduleid,
				    Strategy * strategy
				    )
{
  for( std::vector<Module*>::iterator it = _modulelist.begin(); it != _modulelist.end(); ++it )
    {
      if( (*it)->getId() == moduleid )
	{
	  (*it)->loadStrategy( strategy );
	  return;
	}
    }
} /* end ModuleController::loadStrategy() */

void ModuleController::loadCompanyList( std::vector<std::string> companylist )
{
  for( std::vector<std::string>::const_iterator it = companylist.begin(); it != companylist.end(); ++it )
    {
      _companylist.push_back( *it );
    }
} /* end ModuleController::loadCompanyList() */

void ModuleController::run( boost::gregorian::date day )
{
  // TODO
  /* Set hours to opening time of stock market */
  boost::posix_time::ptime timestamp( day, boost::posix_time::hours(10) );

  for( std::vector<Module*>::iterator it = _modulelist.begin(); it != _modulelist.end(); ++it )
    {
      _threads.push_back( new std::thread( &ModuleController::runModule, this, *it, timestamp ) ); 
    }

  for( std::vector<std::thread*>::iterator it = _threads.begin(); it != _threads.end(); ++it )
    {
      (*it)->join();
    }

  _threads.clear();
} /* end ModuleController::run() */

boost::signals2::connection ModuleController::connect(
						      const signal_t::slot_type& subscriber
						      )
{
  return _sig.connect( subscriber );
} /* end ModuleController::connect() */

unsigned int ModuleController::getNextId()
{
  // TODO
  /* add check for if going past UINT_MAX */
  /* shouldn't matter for now */
  return _nextid++;
} /* end ModuleController::getNextId() */

void ModuleController::runModule(
				 Module * module,
				 boost::posix_time::ptime date
				 )
{
  // TODO
  /* add threads */
  /* move company list to module */
  for( std::vector<std::string>::const_iterator it = _companylist.begin(); it != _companylist.end(); ++it )
    {
      module->run( *it, date );
    }
} /* end ModuleController::runModule() */
