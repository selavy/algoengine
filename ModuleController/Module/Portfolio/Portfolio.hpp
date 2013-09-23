#ifndef __PORTFOLIO_HPP__
#define __PORTFOLIO_HPP__

#include <string>
#include <unordered_map>
#include <mutex>
#include "../Module.hpp"
#include <gmpxx.h>
#include "../../../FeedbackEngine/Ledger/Event/Event.hpp"
#include "../../../FeedbackEngine/Ledger/Event/BuyEvent.hpp"
#include "../../../FeedbackEngine/Ledger/Event/SellEvent.hpp"
#include "../../../FeedbackEngine/Ledger/Event/NewModuleEvent.hpp"

class Portfolio
{
public:
  Portfolio( Module& module );
  virtual ~Portfolio();

  mpf_class getValue() const throw();
  std::unordered_map<std::string, mpz_class> getHoldings() const throw();

  void process( Event* event );
private:
  void processNewModuleEvent( Event* event );
  void processBuyEvent( Event* event );
  void processSellEvent( Event* event );

  void action( std::string company, mpz_class amount, mpf_class price );

  mpf_class _value;
  std::unordered_map<std::string, mpz_class> _holdings;
  boost::signals2::connection _connection;
  std::mutex _mtx;
};

#endif
