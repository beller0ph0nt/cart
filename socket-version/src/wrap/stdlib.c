#include <errno.h>
#include <string.h>

#include <wrap/stdlib.h>

#include <debug/trace.h>
#include <debug/assert.h>
#include <debug/profiler.h>

void
w_exit(int status)
{
    TRACE_ERROR("errno = %d strerror = \"%s\"", errno, strerror(errno));
    exit(status);
}

void*
w_malloc(size_t size)
{
    PROFILER_PROLOG;
    ASSERT(size > 0);

    void* ptr = malloc(size);
    if (ptr == NULL)
    {
        TRACE_ERROR("malloc failure");
        w_exit(EXIT_FAILURE);
    }

    TRACE_DEBUG(" allocate ptr: %p size: %d", ptr, size);

    PROFILER_EPILOG;
    return ptr;
}

void
w_free(void* ptr)
{
    PROFILER_PROLOG;
    ASSERT(ptr != NULL);
    TRACE_DEBUG(" free ptr: %p", ptr);

    free(ptr);
    PROFILER_EPILOG;
}

void*
w_calloc(size_t nmemb, size_t size)
{
    ASSERT(nmemb > 0);
    ASSERT(size > 0);

    void* ptr = calloc(nmemb, size);
    if (ptr == NULL)
    {
        TRACE_ERROR("calloc failure");
        w_exit(EXIT_FAILURE);
    }

    TRACE_DEBUG(" allocate ptr: %p nmemb: %d size: %d", ptr, nmemb, size);

    return ptr;
}

void*
w_realloc(void* ptr, size_t size)
{
    ASSERT(ptr != NULL || size > 0);

    void* p = realloc(ptr, size);
    if (p == NULL)
    {
        TRACE_ERROR("realloc failure");
        w_exit(EXIT_FAILURE);
    }

    TRACE_DEBUG(" allocate ptr: %p size: %d", p, size);

    return p;
}
