/**
 * @file Echo.cpp
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 */
#include "Echo.h"

ACE_RCSID(Portable_Interceptors_AMI, Echo, "$Id$")

Echo::Echo(CORBA::ORB_ptr orb)
  : orb_(CORBA::ORB::_duplicate(orb))
{
}

char *
Echo::echo_operation(char const * the_input)
  ACE_THROW_SPEC((CORBA::SystemException))
{
  return CORBA::string_dup(the_input);
}

void
Echo::shutdown(void)
  ACE_THROW_SPEC((CORBA::SystemException))
{
  this->orb_->shutdown(0);
}
