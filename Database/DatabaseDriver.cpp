#include <iostream>
#include <string>
#include "Database.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

int main( int argc, char ** argv )
{
  boost::posix_time::ptime d;
  std::cout << Database::getInstance()->placeHolder( "GOOGL", d ) << std::endl;
  return 0;
}
