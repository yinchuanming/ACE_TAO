//
// $Id$
//
/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    any_op_ch.h
//
// = DESCRIPTION
//    Concrete visitor for the forward declared Eventtype node.
//    This one provides code generation for the Any operators.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

#ifndef _BE_EVENTTYPE_FWD_ANY_OP_CH_H_
#define _BE_EVENTTYPE_FWD_ANY_OP_CH_H_

class be_visitor_eventtype_fwd_any_op_ch : public be_visitor_decl
{
  //
  // = TITLE
  //   be_visitor_eventtype_fwd_any_op_ch
  //
  // = DESCRIPTION
  //   This is a concrete visitor for forward declared eventtypes that
  //   generates the Any operator declaration.
  //

public:
  be_visitor_eventtype_fwd_any_op_ch (be_visitor_context *ctx);
  // constructor

  ~be_visitor_eventtype_fwd_any_op_ch (void);
  // destructor

  virtual int visit_eventtype_fwd (be_eventtype_fwd *node);
  // visit valuetype_fwd
};

#endif /* _BE_EVENTTYPE_FWD_ANY_OP_CH_H_ */
