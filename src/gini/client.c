#include <stdio.h>

#include "wrap_netdb.h"
#include "wrap_socket.h"
#include "wrap_stdlib.h"

int
main(int argc, char** argv)
{
    int sock = w_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);



    close(sock);

    return EXIT_SUCCESS;
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
