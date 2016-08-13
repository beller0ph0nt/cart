#include <errno.h>
#include <string.h>

#include "trace.h"
#include "assert.h"
#include "wrap_stdlib.h"

void
w_exit(int status)
{
    TRACE_ERROR("errno = %d strerror = \"%s\"", errno, strerror(errno));
    exit(status);
}

void*
w_malloc(size_t size)
{
    ASSERT(size > 0, "malloc size <= 0");

    void* ptr = malloc(size);
    if (ptr == NULL)
    {
        TRACE_ERROR("malloc failure");
        w_exit(EXIT_FAILURE);
    }

    TRACE_DEBUG(" allocate ptr: %p size: %d", ptr, size);

    return ptr;
}

void
w_free(void* ptr)
{
    ASSERT(ptr != NULL, "free NULL pointer");
    TRACE_DEBUG(" free ptr: %p", ptr);

    free(ptr);
}

void*
w_calloc(size_t nmemb, size_t size)
{
    ASSERT(nmemb > 0, "calloc nmemb <= 0");
    ASSERT(size > 0, "calloc size <= 0");

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
    ASSERT(ptr != NULL || size > 0, "realloc NULL pointer with size <= 0");

    void* p = realloc(ptr, size);
    if (p == NULL)
    {
        TRACE_ERROR("realloc failure");
        w_exit(EXIT_FAILURE);
    }

    TRACE_DEBUG(" allocate ptr: %p size: %d", p, size);

    return p;
}
