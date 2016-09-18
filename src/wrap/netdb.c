#include <errno.h>
#include <string.h>

#include <wrap/netdb.h>
#include <wrap/stdlib.h>

#include <debug/trace.h>

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
