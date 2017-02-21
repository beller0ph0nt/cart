#include <errno.h>
#include <string.h>

#include <wrap/socket.h>
#include <wrap/stdlib.h>

#include <debug/trace.h>
#include <debug/profiler.h>

int
w_socket(int domain, int type, int protocol)
{
    PROFILER_PROLOG;
    int sock = socket(domain, type, protocol);
    if (sock < 0)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }

    PROFILER_EPILOG;
    return sock;
}

void
w_bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen)
{
    PROFILER_PROLOG;
    if (bind(sockfd, addr, addrlen) < 0)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }
    PROFILER_EPILOG;
}

void
w_listen(int sockfd, int backlog)
{
    PROFILER_PROLOG;
    if (listen(sockfd, backlog) < 0)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }
    PROFILER_EPILOG;
}

int
w_accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen)
{
    PROFILER_PROLOG;
    int sock = accept(sockfd, addr, addrlen);
    if (sock < 0)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }

    PROFILER_EPILOG;
    return sock;
}
