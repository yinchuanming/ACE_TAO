/**
 * @file Loopback_Pair.cpp
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

#include "Loopback_Pair.h"
#include "Auto_Disconnect.h"

#if !defined(__ACE_INLINE__)
#include "Loopback_Pair.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(TAO_PERF_RTEC, Loopback_Pair, "$Id$")

void
Loopback_Pair::init (CORBA::Long experiment_id,
                     CORBA::Long base_event_type)
{
  this->loopback_supplier_ = new Loopback_Supplier (experiment_id,
                                                    base_event_type + 1);
  this->loopback_consumer_ = new Loopback_Consumer (experiment_id,
                                                    base_event_type,
                                                    loopback_supplier_.in ());
}

void
Loopback_Pair::connect (RtecEventChannelAdmin::EventChannel_ptr ec
                       ACE_ENV_ARG_DECL)
{
  this->loopback_supplier_->connect (ec ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  Auto_Disconnect<Loopback_Supplier> loopback_supplier_disconnect (this->loopback_supplier_);

  this->loopback_consumer_->connect (ec ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  Auto_Disconnect<Loopback_Consumer> loopback_consumer_disconnect (this->loopback_consumer_);

  loopback_consumer_disconnect.release ();
  loopback_supplier_disconnect.release ();
}

void
Loopback_Pair::disconnect (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  Auto_Disconnect<Loopback_Supplier> loopback_supplier_disconnect (this->loopback_supplier_);
  Auto_Disconnect<Loopback_Consumer> loopback_consumer_disconnect (this->loopback_consumer_);
}
