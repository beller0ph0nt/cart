#ifndef __TRACE_H
#define __TRACE_H

#include "wrap_stdio.h"

#define TRACE_ERROR(format, ...) \
    printf("error: " format "\n", ## __VA_ARGS__)

#define TRACE_WARNING(format, ...) \
    printf("warning: " format "\n", ## __VA_ARGS__)

#define TRACE_INFO(format, ...) \
    printf("info: " format "\n", ## __VA_ARGS__)

#ifdef DEBUG
#define TRACE_DEBUG(format, ...) \
    printf("[%s:%d] " format "\n", __FUNCTION__, __LINE__, ## __VA_ARGS__)
#else
#define TRACE_DEBUG(format, ...)
#endif // DEBUG

#endif // __TRACE_H
