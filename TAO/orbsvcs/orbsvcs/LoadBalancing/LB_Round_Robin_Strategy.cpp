// -*- C++ -*-

#include "LB_Round_Robin_Strategy.h"
#include "ReplicaProxy.h"

ACE_RCSID (LoadBalancing,
           LB_Round_Robin_Strategy,
           "$Id$")


TAO_LB_Round_Robin_Strategy::TAO_LB_Round_Robin_Strategy (void)
{
}

TAO_LB_Round_Robin_Strategy::~TAO_LB_Round_Robin_Strategy (void)
{
}

CORBA::Object_ptr
TAO_LB_Round_Robin_Strategy::replica (TAO_LB_ObjectGroup_Map_Entry *entry,
                                      CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                    guard,
                    entry->lock,
                    CORBA::Object::_nil ());

  if (entry->replica_infos.is_empty ())
    {
      // @@ What do we do if the set is empty?
      // @@ Ossama: i'm throwing the OBJECT_NOT_EXIST exception, but
      // maybe TRANSIENT is a better choice.... please read the
      // relevant section of the CORBA spec and let me know what you
      // think.
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        CORBA::Object::_nil ());
    }

  // If we're at the end of the Replica set, then rewind to the
  // beginning of the set.
  if (this->next_replica_ == this->proxies_.end ())
    this->next_replica_ = this->proxies_.begin ();

  TAO_LB_ReplicaProxy * proxy_servant = *(this->next_replica_);

  // Advance to the next Replica in the set in preparation for the
  // next call to this method.
  this->next_replica_++;

  // @@ Ossama: once we select a replica, shouldn't we temporarily
  // change its load so it does not get swamped with all the new
  // clients. Think about the current scenario:
  // - Replica A has the lowest load, by far.
  // - 5 clients connect at the same time.
  // - If the load on A does not grow fast enough all 5 clients will
  // end up on replica A, and then they will be kicked out and
  // shuffled around.
  // While if we bump the load for a few seconds then the next client
  // will go to other place.  Or set a flag that says 'load
  // invalidated, waiting for an update' (i like the latter better).
  return proxy_servant->replica ();
}

int
TAO_LB_Round_Robin_Strategy::insert (TAO_LB_ReplicaProxy *proxy)
{
  ACE_MT (ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                            guard,
                            this->lock_,
                            -1));

  int r = this->proxies_.insert (proxy);
  this->next_replica_ = this->proxies_.begin ();
  return r;
}

int
TAO_LB_Round_Robin_Strategy::remove (TAO_LB_ReplicaProxy *proxy)
{
  ACE_MT (ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                            guard,
                            this->lock_,
                            -1));

  int r = this->proxies_.remove (proxy);
  this->next_replica_ = this->proxies_.begin ();
  return r;
}
