#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "trace.h"
#include "wrap_netdb.h"

struct hostent*
w_gethostbyname(const char* name)
{
    struct hostent* host = gethostbyname(name);
    if (host == NULL)
    {
        TRACE_ERROR("%s", strerror(errno));
        w_exit(EXIT_FAILURE);
    }

    return host;
}
