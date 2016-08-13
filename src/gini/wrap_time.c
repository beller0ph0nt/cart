#include "trace.h"
#include "wrap_time.h"
#include "wrap_stdlib.h"

void
w_clock_gettime(clockid_t clk_id, struct timespec* tp)
{
    if (clock_gettime(clk_id, tp) == -1)
    {
        TRACE_ERROR("clock_gettime failure");
        w_exit(EXIT_FAILURE);
    }
}
