#include <errno.h>
#include <string.h>

#include "trace.h"
#include "wrap_stdlib.h"

void
w_exit(int status)
{
    TRACE_ERROR("errno = %d err = \"%s\"", errno, strerror(errno));
    exit(status);
}
