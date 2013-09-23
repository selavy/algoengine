#include <gmpxx.h>
#include <iostream>

// TODO
/* add ability to change the currency type */

class CurrencyDisplay
{
public:
  CurrencyDisplay( mpf_class money );
  virtual ~CurrencyDisplay() {}

  std::ostream& print( std::ostream& os ) const;
  friend std::ostream& operator<<( std::ostream& os, const CurrencyDisplay& currency );
private:
  mpf_class _currency;
};
