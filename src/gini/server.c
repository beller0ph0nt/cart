#include <stdio.h>
#include <unistd.h>

#include <netinet/in.h>

#include "trace.h"
#include "server.h"
#include "protocol.h"
#include "wrap_socket.h"
#include "wrap_stdlib.h"
#include "wrap_unistd.h"

int
main(int argc, char** argv)
{
    status_t srv_status = GINI_STATUS_IDLE;
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

        gini_msg_t recv_msg;
        recvfrom(cli_sock,
                 &recv_msg,
                 sizeof(recv_msg),
                 0,
                 (struct sockaddr*) &cli_addr,
                 &cli_addr_len);

        pid_t pid = w_fork();
        if (pid == 0)
        {
            close(sock);

            switch (recv_msg.cmd)
            {
            case GINI_REQ_STATUS:
                client_req_status(cli_sock, cli_addr, srv_status);
                break;
            case GINI_REQ_DATA:
                client_req_data(cli_sock, cli_addr);
                break;
            default:
                client_req_unknown(cli_sock);
            }

            w_exit(EXIT_SUCCESS);
        }

        close(cli_sock);
    }

    close(sock);

    return EXIT_SUCCESS;
}

void
client_req_status(int                cli_sock,
                  struct sockaddr_in cli_addr,
                  status_t           srv_status)
{
    gini_msg_t send_msg;
    send_msg.cmd = GINI_ANS_STATUS;
    send_msg.arg.status = srv_status;

    sendto(cli_sock,
           &send_msg,
           sizeof(send_msg),
           0,
           (struct sockaddr*) &cli_addr,
           sizeof(cli_addr));
    close(cli_sock);
}

void
client_req_data(int                cli_sock,
                struct sockaddr_in cli_addr)
{
    gini_msg_t send_msg;
    send_msg.cmd = GINI_ACK;

    sendto(cli_sock,
           &send_msg,
           sizeof(send_msg),
           0,
           (struct sockaddr*) &cli_addr,
           sizeof(cli_addr));
    close(cli_sock);
}

void
client_req_unknown(int cli_sock)
{
    TRACE_ERROR("unknown gini proto cmd");
    close(cli_sock);
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
