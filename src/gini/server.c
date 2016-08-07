#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <netinet/in.h>

#include "server.h"
#include "protocol.h"
#include "wrap_socket.h"
#include "wrap_stdlib.h"

int
main(int argc, char** argv)
{
    int port = DEFAULT_SERVER_PORT;

    char ch;
    while ((ch = getopt(argc,argv,"?hp:")) != -1)
    {
		switch (ch)
		{
		case 'p':
            port = atoi(optarg);
            break;
		case 'h':
		case '?':
		default:
            usage(argv[0]);
        };
	};

	if (optind < argc)
        usage(argv[0]);

    int sock = w_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in serv_addr;
    memset((char*) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    w_bind(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
    w_listen(sock, 1);

    while (1)
    {
        struct sockaddr_in cli_addr;
        socklen_t cli_addr_len = sizeof(cli_addr);
        int cli_sock = w_accept(sock, (struct sockaddr*) &cli_addr, &cli_addr_len);

//        recvfrom(cli_sock, )
    }

    return EXIT_SUCCESS;
}

void
usage(char* app_name)
{
    printf("usage: %s [-p port]\n"
           "  options:\n"
           "    -p port: server listening port (default: %d)\n",
           app_name,
           DEFAULT_SERVER_PORT);
    w_exit(EXIT_FAILURE);
}
