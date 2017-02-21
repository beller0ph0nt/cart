#include <errno.h>
#include <string.h>

#include <wrap/stdlib.h>
#include <wrap/unistd.h>

#include <debug/trace.h>

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
