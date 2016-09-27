#ifndef __ASSERT_H
#define __ASSERT_H

#include "trace.h"
#include "wrap_stdlib.h"

#ifdef ASSERTION
#define ASSERT(expr) \
    if (expr) \
    { \
    } \
    else \
    { \
        TRACE_ERROR("ASSERT (" #expr ") file: %s:%d", __FILE__, __LINE__); \
        w_exit(EXIT_FAILURE); \
    }
#else
#define ASSERT(expr, format, ...)
#endif // ASSERT

#endif // __ASSERT_H
