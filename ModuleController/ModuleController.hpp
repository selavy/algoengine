#ifndef __MODULE_CONTROLLER_HPP__
#define __MODULE_CONTROLLER_HPP__

#include "./Module/Module.hpp"
#include "../FeedbackEngine/FeedbackEngine.hpp"
#include <boost/signals2/connection.hpp>
#include <boost/bind.hpp>
#include <vector>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <unordered_map>
#include <gmpxx.h>
#include <thread>
#include <climits>

class ModuleController
{
public:
  typedef boost::signals2::signal<void (Module*)> signal_t;
  const unsigned int not_found = UINT_MAX;

public:
  ModuleController();
  virtual ~ModuleController();

  unsigned int newModule( std::string name, mpf_class initialvalue, std::unordered_map<std::string, mpz_class> holdings, Strategy * strategy = NULL );
  unsigned int getModuleIdByName( std::string name );
  void loadStrategy( unsigned int moduleid, Strategy * strategy );
  void loadCompanyList( std::vector<std::string> companylist );
  void run( boost::gregorian::date day );

  boost::signals2::connection connect( const signal_t::slot_type &subscriber );

private:
  unsigned int getNextId();
  void runModule( Module * module, boost::posix_time::ptime date );

  unsigned int _nextid;
  std::vector<Module*> _modulelist;
  std::unordered_map<std::string, unsigned int> _modulelookup;

  // TODO
  /* Let each module maintain its own company list */
  /* Just a simplication for now that all modules run on same company list */
  std::vector<std::string> _companylist;
  std::vector<std::thread*> _threads;
  signal_t _sig;
};

#endif
