#ifndef __SERVER_H
#define __SERVER_H

#include "protocol.h"

#define DEFAULT_SERVER_PORT     1313

void
usage(char* app_name);

void
client_req_status(int                cli_sock,
                  struct sockaddr_in cli_addr,
                  status_t           srv_status);

void
client_req_data(int                cli_sock,
                struct sockaddr_in cli_addr);

void
client_req_unknown(int cli_sock);

#endif // __SERVER_H
