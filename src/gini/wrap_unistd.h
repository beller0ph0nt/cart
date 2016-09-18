#ifndef __WRAP_UNISTD_H
#define __WRAP_UNISTD_H

#include <unistd.h>

#define CHILD_PROCESS_PID	0

pid_t
w_fork(void);

#endif // __WRAP_UNISTD_H
