#include <errno.h>
#include <string.h>

#include "trace.h"
#include "wrap_stdlib.h"
#include "wrap_unistd.h"

pid_t
w_fork(void)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        TRACE_ERROR("fork failure  msg: %s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }

    return pid;
}
