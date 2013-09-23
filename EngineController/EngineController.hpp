#ifndef __ENGINE_CONTROLLER_HPP__
#define __ENGINE_CONTROLLER_HPP__

#include "../ModuleController/ModuleController.hpp"
#include "../FeedbackEngine/FeedbackEngine.hpp"

class EngineController
{
public:
  static const long long int DAY;

public:
  EngineController( std::string startdate, std::string enddate, long long int granularity /* in mins */ );
  virtual ~EngineController();

  unsigned int addModule( std::string name, std::string initialvalue, std::unordered_map<std::string, std::string> holdings, Strategy * strategy );

  void loadCompanyList( std::vector<std::string> companylist );
  void run();
  // TODO
  /* allow print to file */
  void print();

private:
  boost::gregorian::date _start;
  boost::gregorian::date _end;
  boost::gregorian::day_iterator _curr;

  ModuleController * _modcontrol;
  FeedbackEngine * _fbengine;
};

#endif
