// $Id$

#ifndef TAO_OBJREF_TYPECODE_CPP
#define TAO_OBJREF_TYPECODE_CPP

#include "tao/Objref_TypeCode.h"

#ifndef __ACE_INLINE__
# include "tao/Objref_TypeCode.inl"
#endif  /* !__ACE_INLINE__ */


template <typename StringType, class RefCountPolicy>
bool
TAO::TypeCode::Objref<StringType, RefCountPolicy>::tao_marshal (
  TAO_OutputCDR &) const
{
  // A tk_objref TypeCode has a "complex" parameter list type (see
  // Table 15-2 in Section 15.3.5.1 "TypeCode" in the CDR section of
  // the CORBA specification), meaning that it must be marshaled into
  // a CDR encapsulation.

  // Create a CDR encapsulation.
  cdr << TAO_ENCAP_BYTE_ORDER;
  cdr << this->attributes_.id ();
  cdr << this->attributes_.name ();

  return true;
}

template <typename StringType, class RefCountPolicy>
void
TAO::TypeCode::Objref<StringType, RefCountPolicy>::tao_add_ref (void)
{
  this->RefCountPolicy::add_ref (void);
}

template <typename StringType, class RefCountPolicy>
void
TAO::TypeCode::Objref<StringType, RefCountPolicy>::tao_remove_ref (void)
{
  this->RefCountPolicy::remove_ref (void);
}

template <typename StringType, class RefCountPolicy>
CORBA::Boolean
TAO::TypeCode::Objref<StringType, RefCountPolicy>::equal_i (
  CORBA::TypeCode_ptr /* tc */
  ACE_ENV_ARG_DECL_NOT_USED) const
{
  // Equality has already been established in the
  // CORBA::TypeCode base class.

  return 1;
}

template <typename StringType, class RefCountPolicy>
CORBA::Boolean
TAO::TypeCode::Objref<StringType, RefCountPolicy>::equivalent_i (
  CORBA::TypeCode_ptr tc
  ACE_ENV_ARG_DECL) const
{
  // We could refactor this code to the CORBA::TypeCode::equivalent()
  // method but doing so would force us to determine the unaliased
  // kind of this TypeCode.  Since we already know the unaliased kind
  // of this TypeCode, choose to optimize away the additional kind
  // unaliasing operation rather than save space.

  CORBA::TCKind const tc_kind =
    TAO::unaliased_kind (tc
                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  // Call kind_i() instead of using CORBA::tk_objref directly since a
  // subclass, such as Home_TypeCode, can use this equivalent_i()
  // implementation.
  CORBA::TCKind const this_kind =
    this->kind_i (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (tc_kind != this_kind)
    return 0;

  char const * const this_id = this->attributes_.id ();
  char const * const tc_id   = tc->id (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (ACE_OS::strcmp (this_id, tc_id) != 0)
    return 0;

  return 1;
}

template <typename StringType, class RefCountPolicy>
CORBA::TCKind
TAO::TypeCode::Objref<StringType, RefCountPolicy>::kind_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return CORBA::tk_objref;
}

template <typename StringType, class RefCountPolicy>
CORBA::TypeCode_ptr
TAO::TypeCode::Objref<StringType, RefCountPolicy>::get_compact_typecode_i (
  ACE_ENV_SINGLE_ARG_DECL) const
{
  TAO_TypeCodeFactory_Adapter * adapter =
    ACE_Dynamic_Service<TAO_TypeCodeFactory_Adapter>::instance (
        TAO_ORB_Core::typecodefactory_adapter_name ()
      );

  if (adapter == 0)
    {
      ACE_THROW_RETURN (CORBA::INTERNAL (),
                        CORBA::TypeCode::_nil ());
    }

  return adapter->create_interface_tc (this->attributes_.id (),
                                       ""  /* empty name */
                                       ACE_ENV_ARG_PARAMETER);
}

#endif  /*  TAO_OBJREF_TYPECODE_CPP */
