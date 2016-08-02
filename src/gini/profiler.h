#ifndef __PROFILER_H
#define __PROFILER_H

#include <time.h>
#include <stdio.h>

#define NSEC_IN_SEC 1000000000

#ifdef PROFILER
#define PROFILER_PROLOG \
    struct timespec __profiler_start; \
    clock_gettime(CLOCK_REALTIME, &__profiler_start);

#define PROFILER_EPILOG \
    struct timespec __profiler_stop; \
    clock_gettime(CLOCK_REALTIME, &__profiler_stop); \
    long __profiler_sec = \
        __profiler_stop.tv_sec - __profiler_start.tv_sec; \
    long __profiler_nsec = \
        __profiler_stop.tv_nsec - __profiler_start.tv_nsec; \
    double __profiler_nsec_diff = \
        NSEC_IN_SEC * __profiler_sec + __profiler_nsec \
    double __profiler_sec_diff = \
        __profiler_nsec_diff / NSEC_IN_SEC \
    printf("%s profile: %.9f sec", __FUNCTION__, __profiler_sec_diff);
#else
#define PROFILER_PROLOG
#define PROFILER_EPILOG
#endif // PROFILER

#endif // __PROFILER_H
