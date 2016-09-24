#ifndef __SOCKET_H
#define __SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>

int
w_socket(int domain, int type, int protocol);

void
w_bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen);

void
w_listen(int sockfd, int backlog);

int
w_accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen);

#endif // __SOCKET_H
