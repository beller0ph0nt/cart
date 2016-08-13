#include <string.h>

#include "trace.h"
#include "client.h"
#include "config.h"
#include "wrap_netdb.h"
#include "wrap_stdio.h"
#include "wrap_socket.h"
#include "wrap_stdlib.h"
#include "wrap_unistd.h"

int
main(int argc, char** argv)
{
    if (argc < 2)
        usage(argv[0]);

    servers_list_t  list = config_cre_server_list(argv[1]);
    servers_count_t list_len = config_get_server_count();

    pid_t pid = w_fork();
    if (pid == 0)
    {
//        int i;
//        for (i = 0; i < list_len; i++)
//        {
//            TRACE_INFO("%d.%d.%d.%d:%d",
//                       list[i].ip.b1,
//                       list[i].ip.b2,
//                       list[i].ip.b3,
//                       list[i].ip.b4,
//                       list[i].port);
//        }
    }
    else
    {
//        int i;
//        for (i = 0; i < list_len; i++)
//        {
//            TRACE_INFO("%d.%d.%d.%d:%d",
//                       list[i].ip.b1,
//                       list[i].ip.b2,
//                       list[i].ip.b3,
//                       list[i].ip.b4,
//                       list[i].port);
//        }
    }

    config_del_server_list(list);

    return EXIT_SUCCESS;
}

void
create_client(const char* host, int port)
{
    int sock = w_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct hostent* server = w_gethostbyname(host);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    strncpy((char *) &serv_addr.sin_addr.s_addr,
            (char *) server->h_addr,
            server->h_length);
    serv_addr.sin_port = htons(port);

    close(sock);
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
