/* -*- C++ -*- */

// $Id$

// ============================================================================
//
// = LIBRARY
//    examples
// 
// = FILENAME
//    Driver.h
//
// = DESCRIPTION
//   // @@ Please comment me
//
// = AUTHORS
//    Sergio Flores-Gaitan <sergio@cs.wustl.edu>
// 
// ============================================================================

#if !defined (_DRIVER_H_)
#define _DRIVER_H_

#include "ace/Task.h"
#include "ace/Timer_Heap_T.h"
#include "ace/Timer_Queue_Adapters.h"

typedef ACE_Event_Handler_Handle_Timeout_Upcall<ACE_Null_Mutex> 
	Upcall;
typedef ACE_Timer_Heap_T<ACE_Event_Handler *,
	                 ACE_Event_Handler_Handle_Timeout_Upcall<ACE_Null_Mutex>,
			 ACE_Null_Mutex>
	Timer_Heap;
typedef ACE_Timer_Heap_Iterator_T<ACE_Event_Handler *,
                                  ACE_Event_Handler_Handle_Timeout_Upcall<ACE_Null_Mutex>,
				  ACE_Null_Mutex> 
        Timer_Heap_Iterator;
typedef ACE_Thread_Timer_Queue_Adapter<Timer_Heap>
        Thread_Timer_Queue;

template <class Receiver>
class Command 
{
public:
  typedef int (Receiver::*Action) (void *);

  Command (Receiver &recvr, Action action) 
    : receiver_(recvr), 
      action_(action)
    {}

  virtual int execute (void *arg)
    {
      return (receiver_.*action_) (arg);
    }

private:
  Receiver &receiver_;
  Action action_;
};

template <class TQ, class Receiver>
class Timer_Queue_Test_Driver
{
public:
  virtual int parse_commands (const char *buf);

  virtual int run_test (void);
  
  // = Template Methods.
    
  virtual int display_menu (void)=0;
  
  virtual int init (void)=0;
  
  virtual int get_next_request (void);

  virtual ssize_t read_input (char *buf, size_t bufsiz);

protected:
  TQ timer_queue_;

  Command<Receiver> *schedule_cmd_;
  Command<Receiver> *cancel_cmd_;
  Command<Receiver> *list_cmd_;
  Command<Receiver> *shutdown_cmd_;

};

#endif /* _DRIVER_H_ */
