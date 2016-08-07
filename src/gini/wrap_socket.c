#include <errno.h>
#include <string.h>

#include "trace.h"
#include "wrap_socket.h"
#include "wrap_stdlib.h"

int
w_socket(int domain, int type, int protocol)
{
    int sock = socket(domain, type, protocol);
    if (sock < 0)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }

    return sock;
}

void
w_bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen)
{
    if (bind(sockfd, addr, addrlen) < 0)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }
}

void
w_listen(int sockfd, int backlog)
{
    if (listen(sockfd, backlog) < 0)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }
}

int
w_accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen)
{
    int sock = accept(sockfd, addr, addrlen);
    if (sock < 0)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }

    return sock;
}
