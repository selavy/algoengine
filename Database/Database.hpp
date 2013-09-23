#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__

#include <string>
#include "boost/date_time/posix_time/posix_time.hpp"

class Database
{
public:
  static Database * getInstance();
  virtual ~Database() {}

  double placeHolder( std::string company, boost::posix_time::ptime datestamp );
private:
  Database();
  static Database * _pinstance;
};

#endif
