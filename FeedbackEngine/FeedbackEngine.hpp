#ifndef __FEEDBACK_ENGINE_HPP__
#define __FEEDBACK_ENGINE_HPP__

#include "./Ledger/Ledger.hpp"
#include "../ModuleController/ModuleController.hpp"
#include <vector>
#include <boost/signals2/connection.hpp>
#include <boost/bind.hpp>

// forward declaration
class ModuleController;

class FeedbackEngine
{
public:
  FeedbackEngine();
  virtual ~FeedbackEngine();

  void addModuleController( ModuleController& modulecontroller );
  void listen( Module * module );

  // TODO
  /* add fstream parameter so can print to logs */
  /* probably will want to pass a vector list of logs */
  void print();

private:
  std::vector<Ledger*> LedgerList;
  boost::signals2::connection _connection;
};

#endif
