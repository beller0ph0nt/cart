#include <errno.h>
#include <string.h>

#include "trace.h"
#include "wrap_socket.h"
#include "wrap_stdlib.h"

int
w_socket(int domain, int type, int protocol)
{
    int sock = socket(domain, type, protocol);
    if (sock == -1)
    {
        TRACE_ERROR("%s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return sock;
}
