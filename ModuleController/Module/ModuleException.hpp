#ifndef __MODULE_EXCEPTION_HPP__
#define __MODULE_EXCEPTION_HPP__

#include <exception>
#include <string>

class ModuleException : public std::exception
{
public:
  ModuleException( std::string message );
  virtual ~ModuleException() throw() {}

  virtual const char * what() const throw();

private:
  std::string _message;
};

#endif
