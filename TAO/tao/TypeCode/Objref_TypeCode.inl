// -*- C++ -*-
//
// $Id$


template <typename StringType, class RefCountPolicy>
ACE_INLINE
TAO::TypeCode::Objref<StringType, RefCountPolicy>::Objref (char const * id,
                                                           char const * name)
  : RefCountPolicy (),
    attributes_ (id, name)
{
}
