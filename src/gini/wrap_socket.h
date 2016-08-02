#ifndef __SOCKET_H
#define __SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>

int
w_socket(int domain, int type, int protocol);

#endif // __SOCKET_H
