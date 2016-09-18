#ifndef __WRAP_NETDB_H
#define __WRAP_NETDB_H

#include <netdb.h>

struct hostent*
w_gethostbyname(const char* name);

#endif // __WRAP_NETDB_H
