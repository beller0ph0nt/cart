#include <string.h>

#include <netinet/in.h>

#include "wrap_socket.h"
#include "wrap_stdlib.h"

int
main(int argc, char** argv)
{
    int sock = w_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in serv_addr;
    memset((char*) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    int port = atoi(argv[1]);
    serv_addr.sin_port = htons(port);

    return EXIT_SUCCESS;
}

//void
//usage()
//{
//    printf("");
//}
