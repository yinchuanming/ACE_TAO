// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.7
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1277

#include "B_exec.h"

namespace CIAO_B_Impl
{
  //============================================================
  // Facet Executor Implementation Class: A_exec_i
  //============================================================
  
  A_exec_i::A_exec_i (void)
  {
  }
  
  A_exec_i::~A_exec_i (void)
  {
  }
  
  // Operations from ::A
  
  //============================================================
  // Component Executor Implementation Class: B_exec_i
  //============================================================
  
  B_exec_i::B_exec_i (void)
  {
  }
  
  B_exec_i::~B_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  ::CCM_A_ptr
  B_exec_i::get_a_port (void)
  {
    /* Your code here. */
    return ::CCM_A::_nil ();
  }
  
  // Operations from Components::SessionComponent.
  
  void
  B_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::CCM_B_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  B_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  B_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  B_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  B_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C" B_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_B_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      B_exec_i);
    
    return retval;
  }
}

