#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include <iostream>
#include "Context.hpp"
#include "TestStrategy/TestStrategyA.hpp"
#include "TestStrategy/TestStrategyB.hpp"
#include "TestStrategy/TestStrategyC.hpp"
#include <stdexcept> /* std::out_of_range */
#include <utility>

int main( int argc, char ** argv )
{
  Context * ContextA = new Context();
  Context * ContextB = new Context();
  Context * ContextC = new Context();

  ContextA->setStrategy( new TestStrategyA );
  ContextB->setStrategy( new TestStrategyB );
  ContextC->setStrategy( new TestStrategyC );

  try
    {
      boost::posix_time::ptime testDay;
      std::string company = "GOOGL";

      std::cout << "ContextA : " << (ContextA->executeStrategy( company, testDay )).first.get_str() << std::endl;
      std::cout << "ContextB : " << (ContextB->executeStrategy( company, testDay )).first.get_str() << std::endl;
      std::cout << "ContextC : " << (ContextC->executeStrategy( company, testDay )).first.get_str() << std::endl;
    }
  catch( const std::out_of_range& oor )
    {
      std::cerr << oor.what() << std::endl;
      return 1;
    }

  return 0;
}
