#ifndef __PROFILER_H
#define __PROFILER_H

#include <wrap/time.h>
#include <wrap/stdio.h>

#include <debug/trace.h>

#define NSEC_IN_SEC     1000000000

#define CLOCK_ID        CLOCK_REALTIME

#ifdef PROFILER
#define PROFILER_PROLOG \
    struct timespec __profiler_start; \
    w_clock_gettime(CLOCK_ID, &__profiler_start);

#define PROFILER_EPILOG \
    struct timespec __profiler_stop; \
    w_clock_gettime(CLOCK_ID, &__profiler_stop); \
    long __profiler_sec = \
        __profiler_stop.tv_sec - __profiler_start.tv_sec; \
    long __profiler_nsec = \
        __profiler_stop.tv_nsec - __profiler_start.tv_nsec; \
    double __profiler_nsec_diff = \
        NSEC_IN_SEC * __profiler_sec + __profiler_nsec; \
    double __profiler_sec_diff = \
        __profiler_nsec_diff / NSEC_IN_SEC; \
    TRACE_INFO("=======> time: %.9f (sec) func: %s <=======", \
           __profiler_sec_diff, \
           __FUNCTION__);
#else
#define PROFILER_PROLOG
#define PROFILER_EPILOG
#endif // PROFILER

#endif // __PROFILER_H
