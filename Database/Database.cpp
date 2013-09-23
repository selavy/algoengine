#include "Database.hpp"

/* Static Class Member */
Database * Database::_pinstance = NULL;

/* Class method */
Database * Database::getInstance()
{
  if( NULL == _pinstance )
    _pinstance = new Database();

  return _pinstance;
} /* end Database::getInstance() */

double Database::placeHolder(
			     std::string company,
			     boost::posix_time::ptime datestamp
			     )
{
  // TODO
  return 0;
} /* end Database::placeHolder() */

Database::Database()
{
  //TODO
} /* end Database::Database() */
