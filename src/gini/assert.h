#ifndef __ASSERT_H
#define __ASSERT_H

#include "trace.h"
#include "wrap_stdlib.h"

#ifdef ASSERTION
#define ASSERT(expr, format, ...) \
    if (!(expr)) \
    { \
        TRACE_ERROR(format, ## __VA_ARGS__); \
        w_exit(EXIT_FAILURE); \
    }
#else
#define ASSERT(expr, format, ...)
#endif // ASSERT

#endif // __ASSERT_H
