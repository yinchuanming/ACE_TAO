// -*- C++ -*-

//=============================================================================
/**
 *  @file    Empty_Param_TypeCode.h
 *
 *  $Id$
 *
 *  Header file for @c CORBA::TypeCodes with empty parameter lists.
 *
 *  @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_EMPTY_PARAM_TYPECODE_H
#define TAO_EMPTY_PARAM_TYPECODE_H

#include /**/ "ace/pre.h"

#include "tao/TypeCode.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  namespace TypeCode
  {

    /**
     * @class Empty_Param
     *
     * @brief @c CORBA::TypeCode implementation for OMG IDL types with
     *        empty parameter lists.
     *
     * This class implements a @c CORBA::TypeCode for OMG IDL types
     * with empty parameter lists.
     *
     * @note @c Empty_Param @c TypeCodes are not reference counted in
     *       TAO since they are static, exist as constants for the
     *       length of a given OS process, and cannot be created
     *       through the @c CORBA::ORB or @c CORBA::TypeCodeFactory
     *       interfaces.
     */
    class Empty_Param : public CORBA::TypeCode
    {
    public:

      /// Constructor.
      Empty_Param (CORBA::TCKind k);

      /**
       * @name TAO-specific @c CORBA::TypeCode Methods
       *
       * Methods required by TAO's implementation of the
       * @c CORBA::TypeCode class.
       *
       * @see @c CORBA::TypeCode
       */
      //@{
      virtual bool tao_marshal (TAO_OutputCDR & cdr) const;
      virtual void tao_add_ref (void);
      virtual void tao_remove_ref (void);
      //@}

    protected:

      /**
       * @name @c TAO CORBA::TypeCode Template Methods
       *
       * @c CORBA::TypeCode template methods specific to @c TypeCodes
       * with empty parameter lists.
       *
       * @see @c CORBA::TypeCode
       */
      //@{
      virtual CORBA::Boolean equal_i (CORBA::TypeCode_ptr tc
                                      ACE_ENV_ARG_DECL) const;
      virtual CORBA::Boolean equivalent_i (CORBA::TypeCode_ptr tc
                                           ACE_ENV_ARG_DECL) const;
      virtual CORBA::TCKind kind_i (ACE_ENV_SINGLE_ARG_DECL) const;
      virtual CORBA::TypeCode_ptr get_compact_typecode_i (
        ACE_ENV_SINGLE_ARG_DECL) const;

    private:

      /// Kind of this @c TypeCode.
      CORBA::TCKind const kind_;

    };

  }  // End namespace TypeCode
}  // End namespace TAO


#ifdef __ACE_INLINE__
# include "tao/Empty_Param_TypeCode.inl"
#endif  /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_EMPTY_PARAM_TYPECODE_H */
