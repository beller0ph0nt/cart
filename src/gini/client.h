#ifndef __CLIENT_H
#define __CLIENT_H

#include "wrap_unistd.h"

pid_t
create_client(const char* host, int port);

void
usage(char* app_name);

#endif // __CLIENT_H
