#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>
#include <iostream>
#include "Context.hpp"
#include "TestStrategy/TestStrategyA.hpp"
#include "TestStrategy/TestStrategyB.hpp"
#include "TestStrategy/TestStrategyC.hpp"
#include <stdexcept> /* std::out_of_range */

int main( int argc, char ** argv )
{
  Context * ContextA = new Context( new TestStrategyA );
  Context * ContextB = new Context( new TestStrategyB );
  Context * ContextC = new Context( new TestStrategyC );

  try
    {
      boost::gregorian::date testDay( 2013, boost::gregorian::Sep, 22 );
      std::string company = "GOOGL";

      std::cout << "ContextA : " << ContextA->executeStrategy( company, testDay ) << std::endl;
      std::cout << "ContextB : " << ContextB->executeStrategy( company, testDay ) << std::endl;
      std::cout << "ContextC : " << ContextC->executeStrategy( company, testDay ) << std::endl;
    }
  catch( const std::out_of_range& oor )
    {
      std::cerr << oor.what() << std::endl;
      return 1;
    }

  return 0;
}
