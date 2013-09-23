#ifndef __MODULE_HPP__
#define __MODULE_HPP__

#include <boost/date_time/posix_time/posix_time.hpp> /* ptime */
#include <utility> /* std::pair */
#include <gmpxx.h>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>
#include "./Strategy/Context.hpp"
#include "./Strategy/Strategy.hpp"
#include "../../FeedbackEngine/Ledger/Event/Event.hpp"
#include "../../FeedbackEngine/Ledger/Event/NewModuleEvent.hpp"
#include "../../FeedbackEngine/Ledger/Event/BuyEvent.hpp"
#include "../../FeedbackEngine/Ledger/Event/SellEvent.hpp"

class Module
{
public:
  typedef boost::signals2::signal<void (Event*)> signal_t;

public:
  Module( unsigned int aId );
  virtual ~Module();

  boost::signals2::connection connect( const signal_t::slot_type& subscriber );

  void loadStrategy( Strategy * strategy );
  void run( std::string company, boost::posix_time::ptime date );
  unsigned int getId() const throw();

  void sendEvent( Event * e );

private:
  unsigned int _id;
  Context * _context;
  signal_t _sig;
};

#endif
