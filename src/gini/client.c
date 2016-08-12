#include <stdio.h>
#include <string.h>

#include "wrap_netdb.h"
#include "wrap_socket.h"
#include "wrap_stdlib.h"
#include "wrap_unistd.h"

int
main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}

pid_t
create_client(const char* host, int port)
{
    pid_t pid = w_fork();
    if (pid > 0)
        return pid;

    int sock = w_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct hostent* server = w_gethostbyname(host);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    strncpy((char *) &serv_addr.sin_addr.s_addr,
            (char *) server->h_addr,
            server->h_length);
    serv_addr.sin_port = htons(port);

    close(sock);

    return pid;
}

void
usage(char* app_name)
{
    printf("usage: %s [-c config]\n"
           "  options:\n"
           "    -c config: servers ip file name with struct <ip>[:<port>]\n"
           "               (default: server.conf)\n",
           app_name);
    w_exit(EXIT_FAILURE);
}
