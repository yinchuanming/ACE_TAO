
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl FT_Session_Container
// ------------------------------
#ifndef FT_SESSION_CONTAINER_EXPORT_H
#define FT_SESSION_CONTAINER_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (FT_SESSION_CONTAINER_HAS_DLL)
#  define FT_SESSION_CONTAINER_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && FT_SESSION_CONTAINER_HAS_DLL */

#if !defined (FT_SESSION_CONTAINER_HAS_DLL)
#  define FT_SESSION_CONTAINER_HAS_DLL 1
#endif /* ! FT_SESSION_CONTAINER_HAS_DLL */

#if defined (FT_SESSION_CONTAINER_HAS_DLL) && (FT_SESSION_CONTAINER_HAS_DLL == 1)
#  if defined (FT_SESSION_CONTAINER_BUILD_DLL)
#    define FT_Session_Container_Export ACE_Proper_Export_Flag
#    define FT_SESSION_CONTAINER_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define FT_SESSION_CONTAINER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* FT_SESSION_CONTAINER_BUILD_DLL */
#    define FT_Session_Container_Export ACE_Proper_Import_Flag
#    define FT_SESSION_CONTAINER_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define FT_SESSION_CONTAINER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* FT_SESSION_CONTAINER_BUILD_DLL */
#else /* FT_SESSION_CONTAINER_HAS_DLL == 1 */
#  define FT_Session_Container_Export
#  define FT_SESSION_CONTAINER_SINGLETON_DECLARATION(T)
#  define FT_SESSION_CONTAINER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* FT_SESSION_CONTAINER_HAS_DLL == 1 */

// Set FT_SESSION_CONTAINER_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (FT_SESSION_CONTAINER_NTRACE)
#  if (ACE_NTRACE == 1)
#    define FT_SESSION_CONTAINER_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define FT_SESSION_CONTAINER_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !FT_SESSION_CONTAINER_NTRACE */

#if (FT_SESSION_CONTAINER_NTRACE == 1)
#  define FT_SESSION_CONTAINER_TRACE(X)
#else /* (FT_SESSION_CONTAINER_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define FT_SESSION_CONTAINER_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (FT_SESSION_CONTAINER_NTRACE == 1) */

#endif /* FT_SESSION_CONTAINER_EXPORT_H */

// End of auto generated file.
