#ifndef __WRAP_TIME_H
#define __WRAP_TIME_H

#include <time.h>

void
w_clock_gettime(clockid_t clk_id, struct timespec* tp);

#endif // __WRAP_TIME_H
