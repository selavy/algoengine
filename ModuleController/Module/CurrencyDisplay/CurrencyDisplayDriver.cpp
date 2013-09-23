#include <iostream>
#include "CurrencyDisplay.hpp"
#include <gmpxx.h>

int main( int argc, char ** argv )
{
  mpf_class a("1.234");
  mpf_class b("100000000");
  mpf_class c("1000000000000000");
  mpf_class d("1000000000000000.00");
  mpf_class e("109092340849823.99");

  std::cout << CurrencyDisplay( a ) << std::endl;
  std::cout << CurrencyDisplay( b ) << std::endl;
  std::cout << CurrencyDisplay( c ) << std::endl;
  std::cout << CurrencyDisplay( d ) << std::endl;
  std::cout << CurrencyDisplay( e ) << std::endl;
  return 0;
}
