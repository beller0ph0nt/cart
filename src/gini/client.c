#include <stdio.h>

#include "wrap_stdlib.h"

int
main(int argc, char** argv)
{

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
