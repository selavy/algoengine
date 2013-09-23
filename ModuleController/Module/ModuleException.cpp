#include "ModuleException.hpp"

ModuleException::ModuleException(
				 std::string message
				 )
  :
  _message( message )
{
} /* ModuleException::ModuleException() */

const char * ModuleException::what() const throw()
{
  return _message.c_str();
} /* end Module::what() */
