#include "EngineController.hpp"

/* static data member */
const long long int EngineController::DAY = 86400;

EngineController::EngineController(
				   std::string startdate,
				   std::string enddate,
				   long long int granularity /* granularity in minutes */
				   )
  :
  _start( boost::gregorian::from_string( startdate ) ),
  _end( boost::gregorian::from_string( enddate ) ),
  _curr( _start )
{
  _modcontrol = new ModuleController();
  _fbengine = new FeedbackEngine();

  _fbengine->addModuleController( *_modcontrol );

  // TODO
  /* ignoring granularity for now */
} /* end EngineController::EngineController() */

EngineController::~EngineController()
{
  delete _modcontrol;
  delete _fbengine;
} /* end EngineController::~EngineController() */

unsigned int EngineController::addModule(
					 std::string name,
					 std::string initialvalue,
					 std::unordered_map<std::string, std::string> holdings,
					 Strategy * strategy
					 )
{
  std::unordered_map<std::string, mpz_class> initholdings;

  for( std::unordered_map<std::string, std::string>::const_iterator it = holdings.begin(); it != holdings.end(); ++it )
    {
      initholdings.emplace( it->first, mpz_class( it->second ) );
    }

  return _modcontrol->newModule( name, mpf_class( initialvalue ), initholdings, strategy );
} /* end EngineController::addModule() */

void EngineController::loadCompanyList(
				       std::vector<std::string> companylist
				       )
{
  _modcontrol->loadCompanyList( companylist );
} /* end EngineController::loadCompanyList() */

void EngineController::run()
{
  for( ; _curr <= _end; ++_curr )
    {
      _modcontrol->run( boost::gregorian::date( *_curr ) );
    }
} /* end EngineController::run() */
				     
void EngineController::print()
{
  _fbengine->print();
} /* end EngineController::print() */
