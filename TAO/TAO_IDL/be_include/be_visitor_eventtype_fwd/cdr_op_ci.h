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
//    cdr_op_ci.h
//
// = DESCRIPTION
//    Concrete visitor for the forward declared Eventtype node.
//    This one provides code generation for the CDR operators.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

#ifndef _BE_EVENTTYPE_FWD_CDR_OP_CI_H_
#define _BE_EVENTTYPE_FWD_CDR_OP_CI_H_

class be_visitor_eventtype_fwd_cdr_op_ci : public be_visitor_decl
{
  //
  // = TITLE
  //   be_visitor_eventtype_fwd_cdr_op_ci
  //
  // = DESCRIPTION
  //   This is a concrete visitor for forward declared eventtypes that
  //   generates the CDR operator declaration.
  //

public:
  be_visitor_eventtype_fwd_cdr_op_ci (be_visitor_context *ctx);
  // constructor

  ~be_visitor_eventtype_fwd_cdr_op_ci (void);
  // destructor

  virtual int visit_eventtype_fwd (be_eventtype_fwd *node);
  // visit valuetype_fwd
};

#endif /* _BE_EVENTTYPE_FWD_CDR_OP_CI_H_ */
